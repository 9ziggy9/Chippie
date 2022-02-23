#ifndef CHIP8_H_
#define CHIP8_H_

#include "config.h"
#include "chip8memory.h"
#include "chip8registers.h"
#include "chip8stack.h"
#include "chip8keyboard.h"
#include "chip8screen.h"

struct Chip8 {
    Chip8memory memory;
    Chip8registers registers;
    Chip8stack stack;
    Chip8keyboard keyboard;
    Chip8screen screen;
};

void chip8_init(struct Chip8* chip8);

#endif // CHIP8_H_
