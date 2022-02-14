#include <stdio.h>
#include <math.h>

#include <SDL2/SDL.h>

#include "include/colors.h"
#include "include/chip8.h"

int sdl_check_error(int code) {
    if (code < 0) {
        fprintf(stderr, "SDL error: %s\n", SDL_GetError());
        exit(1);
    }
    return code;
}

void *sdl_check_pointer(void *ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "SDL error: %s\n", SDL_GetError());
        exit(1);
    }
    return ptr;
}

void set_color_hex(SDL_Renderer *renderer, Uint32 hex) {
    sdl_check_error(SDL_SetRenderDrawColor(
                        renderer,
                        (hex >> (3*8)) & 0xFF, // shift and mask
                        (hex >> (2*8)) & 0xFF,
                        (hex >> (1*8)) & 0xFF,
                        (hex >> (0*8)) & 0xFF));
}

int main(int argc, char **argv) {

    Chip8 chip8;

    registers_initV(&chip8.registers);
    memory_init(&chip8.memory);

    register_setV(0x0F, 50, &chip8.registers);
    memory_set(0xFF, 'Z', &chip8.memory);

    printf("%c\n", memory_get(0xFF, &chip8.memory));
    printf("%c\n", register_getV(0x0F, &chip8.registers));

    memory_dump(&chip8.memory);
    register_dumpV(&chip8.registers);

    sdl_check_error(SDL_Init(SDL_INIT_EVERYTHING));

    SDL_Window *window = SDL_CreateWindow(
        "Chippie Window",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        CHIP8_DISPLAY_WIDTH * WINDOW_SCALE,
        CHIP8_DISPLAY_HEIGHT * WINDOW_SCALE,
        SDL_WINDOW_SHOWN
    );
    sdl_check_pointer(window);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
                                                SDL_TEXTUREACCESS_TARGET);
    sdl_check_pointer(renderer);

    int quit = 0;
    while(!quit) {
        // event loop
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT: {
                    quit = 1;
                } break;
            }
        }

        set_color_hex(renderer, BACKGROUND_COLOR);
        SDL_RenderClear(renderer); // clears with bg color

        /* set_color_hex(renderer, FOREGROUND_COLOR); */
        /* SDL_Rect r; */
        /* r.x = 0; */
        /* r.y = 0; */
        /* r.w = 40; */
        /* r.h = 40; */
        /* SDL_RenderDrawRect(renderer, &r); // draws rect on buffer */
        SDL_RenderPresent(renderer); // present next buffer change
    }

    SDL_DestroyWindow(window);
    return 0;
}
