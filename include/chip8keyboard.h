#ifndef CHIP8KEYBOARD_H_
#define CHIP8KEYBOARD_H_

#include <stdbool.h>
#include "config.h"

typedef struct {
    bool keyboard[CHIP8_KEYS];
} Chip8keyboard;

void keyboard_down(int key, Chip8keyboard* keyboard);
void keyboard_up(int key, Chip8keyboard* keyboard);
bool keyboard_is_down(int key, Chip8keyboard* keyboard);
int keyboard_map(const char* map, char key);

#endif // CHIP8KEYBOARD_H_
