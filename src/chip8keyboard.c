#include "../include/chip8keyboard.h"
#include <assert.h>

static void key_in_bounds(int key)  {
    assert(key >= 0 && key < CHIP8_KEYS);
}

// Given a map of keys:
// 0, 0, 0, 0, 0, 0, 0xff, 0, 0, 0, 0, 0
// -------------------^^----------------
// keyboard_map locates key and returns index as char
int keyboard_map(const char* map, char key) {
    for (int i = 0; i < CHIP8_KEYS; i++) {
        if (map[i] == key) {
            return i;
        }
    }
    return -1; // cannot find key code
}

void keyboard_down(int key, Chip8keyboard* keyboard) {
    keyboard->keyboard[key] = true;
}

void keyboard_up(int key, Chip8keyboard* keyboard) {
    keyboard->keyboard[key] = false;
}

bool keyboard_is_down(int key, Chip8keyboard* keyboard) {
    return keyboard->keyboard[key];
}
