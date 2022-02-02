#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 320

int main(int argc, char** argv) {

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("SDL error: %s\n", SDL_GetError());
        exit(1);
    } else {
        printf("SDL initialized correctly.\n");
    }

    SDL_Window* window = SDL_CreateWindow(
        "Chippie Window",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if (window == NULL) {
        printf("SDL error: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_TEXTUREACCESS_TARGET);

    while(true) {
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
