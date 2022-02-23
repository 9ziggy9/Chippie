#ifndef CHIP8SCREEN_H_
#define CHIP8SCREEN_H_
#include <stdbool.h>
#include "config.h"

typedef struct {
    bool pixels[CHIP8_DISPLAY_HEIGHT][CHIP8_DISPLAY_WIDTH];
} Screen;

void pixel_set(int x, int y, Screen* screen);
bool pixel_is_set(int x, int y, Screen* screen);

#endif // CHIP8SCREEN_H_
