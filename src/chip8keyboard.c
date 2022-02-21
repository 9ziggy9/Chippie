#include "../include/chip8keyboard.h"

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
