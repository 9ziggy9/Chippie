#include "../include/chip8keyboard.h"
#include <assert.h>
#include <stdio.h>

const char KEYBOARD_MAP[CHIP8_KEYS] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05,
    0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B,
    0x0C, 0x0D, 0x0E, 0x0F
};

static void key_in_bounds(int key)  {
    assert(key >= 0 && key < CHIP8_KEYS);
}

// Given a map of keys:
// 0, 0, 0, 0, 0, 0, 0xff, 0, 0, 0, 0, 0
// -------------------^^----------------
// keyboard_map locates key and returns index
int keyboard_map(const char* map, char key) {
    for (int i = 0; i < CHIP8_KEYS; i++) {
        if (map[i] == key) {
            return i;
        }
    }
    return -1; // cannot find key code
}

void key_down(int key, Chip8keyboard* keyboard) {
    key_in_bounds(key);
    keyboard->keyboard[key] = true;
}

void key_up(int key, Chip8keyboard* keyboard) {
    key_in_bounds(key);
    keyboard->keyboard[key] = false;
}

bool key_is_down(int key, const Chip8keyboard* keyboard) {
    key_in_bounds(key);
    return keyboard->keyboard[key];
}

void clear_keys(Chip8keyboard* keyboard) {
    for(int i = 0; i < CHIP8_KEYS; i++) {
        keyboard->keyboard[i] = false;
    }
}

void dump_keys(const Chip8keyboard* keyboard) {
    for (int i = 0; i < CHIP8_KEYS; i++) {
        if (key_is_down(i, keyboard)) {
            printf("Key #%d is down\n", i);
        }
    }
}
