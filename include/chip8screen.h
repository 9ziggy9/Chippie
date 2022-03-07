#ifndef CHIP8SCREEN_H_
#define CHIP8SCREEN_H_
#include <stdbool.h>
#include "config.h"

typedef struct {
    bool pixels[CHIP8_DISPLAY_HEIGHT][CHIP8_DISPLAY_WIDTH];
} Chip8screen;

void pixel_set(int x, int y, Chip8screen* screen);
bool pixel_is_set(int x, int y, Chip8screen* screen);
bool draw_sprite(int x, int y, const char* sprite,
		 int num_bytes, Chip8screen* screen);

#endif // CHIP8SCREEN_H_
