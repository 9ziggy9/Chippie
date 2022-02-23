#include "../include/chip8screen.h"
#include <assert.h>

static void screen_check_bounds(int x, int y) {
    assert(x >= 0 && x < CHIP8_DISPLAY_WIDTH);
    assert(y >= 0 && y < CHIP8_DISPLAY_HEIGHT);
}

void pixel_set(int x, int y, Screen* screen) {
    screen_check_bounds(x,y);
    screen->pixels[y][x] = true;
}

bool pixel_is_set(int x, int y, Screen* screen) {
    screen_check_bounds(x,y);
    return screen->pixels[y][x];
}
