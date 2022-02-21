#ifndef CHIP8KEYBOARD_H_
#define CHIP8KEYBOARD_H_

#include <stdbool.h>
#include "config.h"

typedef struct {
    bool keyboard[CHIP8_KEYS];
} Chip8keyboard;

void key_down(int key, Chip8keyboard* keyboard);
void key_up(int key, Chip8keyboard* keyboard);
bool key_is_down(int key, const Chip8keyboard* keyboard);
int keyboard_map(const char* map, char key);
void dump_keys(const Chip8keyboard* keyboard);
void clear_keys(Chip8keyboard* keyboard);
extern const char KEYBOARD_MAP[CHIP8_KEYS];

#endif // CHIP8KEYBOARD_H_
