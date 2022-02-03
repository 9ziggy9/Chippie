#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 320

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


int main(int argc, char **argv) {
    sdl_check_error(SDL_Init(SDL_INIT_EVERYTHING));

    SDL_Window *window = SDL_CreateWindow(
        "Chippie Window",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN
    );
    sdl_check_pointer(window);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_TEXTUREACCESS_TARGET);
    sdl_check_pointer(renderer);

    int quit = 0;
    while(!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT: {
                    quit = 1;
                } break;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 170, 0); // classic C64 bg
        SDL_RenderClear(renderer); // clears with bg color
        SDL_SetRenderDrawColor(renderer, 187,187,187,0); // set draw color gray
        SDL_Rect r;
        r.x = 0;
        r.y = 0;
        r.w = 40;
        r.h = 40;
        SDL_RenderDrawRect(renderer, &r); // draws rect to screen, need to present
        SDL_RenderPresent(renderer); // present changes
    }

    SDL_DestroyWindow(window);
    return 0;
}
