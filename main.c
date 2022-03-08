#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include <time.h>

#include <SDL2/SDL.h>

#include "include/colors.h"
#include "include/chip8.h"
#include "include/chip8keyboard.h"
#include "include/chip8screen.h"

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

int Usleep(long miliseconds) {
  struct timespec rem;
  struct timespec req = {
    (int) (miliseconds / 1000),
    (miliseconds % 1000) * 1000000
  };
  return nanosleep(&req, &rem);
}

int main(int argc, char **argv) {

    // TESTING LAND //
    struct Chip8 chip8;
    chip8_init(&chip8);

    // start timer
    chip8.registers.DT = 255;

    // registers
    registers_initV(&chip8.registers);
    register_setV(0x0F, 50, &chip8.registers);

    // memory
    printf("%c\n", memory_get(0xFF, &chip8.memory));
    printf("%c\n", register_getV(0x0F, &chip8.registers));

    memory_dump(&chip8.memory);
    register_dumpV(&chip8.registers);

    // stack
    chip8.registers.SP = 0;
    stack_push(0xff, &chip8);
    stack_push(0xaa, &chip8);
    stack_dump(&chip8.stack);
    printf("POPPED: 0x%x\n", stack_pop(&chip8));
    printf("POPPED: 0x%x\n", stack_pop(&chip8));

    // keyboard
    clear_keys(&chip8.keyboard);
    key_down(0x0f, &chip8.keyboard);
    dump_keys(&chip8.keyboard);
    printf("%d\n", keyboard_map(KEYBOARD_MAP, 0x02));

    // screen
    /* draw_sprite(28, 12, &chip8.memory.memory[0x4B], 5, &chip8.screen); */
    /* draw_sprite(62, 10, &chip8.memory.memory[0x00], 5, &chip8.screen); */

    // TESTING LANDS END //

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

                case SDL_KEYDOWN: {
                    char key = event.key.keysym.sym;
                    int vkey = keyboard_map(KEYBOARD_MAP, key);
                    printf("Key is down (R: %c, V: %x)\n", key, vkey);
		    /* TODO: CLEAN UP, this is only here for testing */
                    if (vkey != -1) {
			key_down(vkey, &chip8.keyboard);
			clear_sprites(&chip8.screen);
			draw_sprite(28, 12, &chip8.memory.memory[5 * vkey],
				    5, &chip8.screen);
		    }
                } break;

                case SDL_KEYUP: {
                    char key = event.key.keysym.sym;
                    int vkey = keyboard_map(KEYBOARD_MAP, key);
                    printf("Key is up\n");
                    if (vkey != -1) key_up(vkey, &chip8.keyboard);
                } break;
            }
        }

        set_color_hex(renderer, BACKGROUND_COLOR);
        SDL_RenderClear(renderer); // clears with bg color

        for (int x = 0; x < CHIP8_DISPLAY_WIDTH; x++) {
            for (int y = 0; y < CHIP8_DISPLAY_HEIGHT; y++) {
                if (pixel_is_set(x, y, &chip8.screen)) {
                    set_color_hex(renderer, FOREGROUND_COLOR);
                    SDL_Rect r;
                    r.w = WINDOW_SCALE;
                    r.h = WINDOW_SCALE;
                    r.x = x * WINDOW_SCALE;
                    r.y = y * WINDOW_SCALE;
                    SDL_RenderFillRect(renderer, &r);
                }
            }
        }

	if (chip8.registers.DT > 0) {
	  Usleep(100);
	  chip8.registers.DT--;
	  printf("DELAY: %d\n", chip8.registers.DT);
	}

        SDL_RenderPresent(renderer); // present next buffer change
    }

    SDL_DestroyWindow(window);
    return 0;
}
