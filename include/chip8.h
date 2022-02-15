#ifndef CHIP8_H_
#define CHIP8_H_

#include "config.h"
#include "chip8memory.h"
#include "chip8registers.h"
#include "chip8stack.h"

struct Chip8 {
    Chip8memory memory;
    Chip8registers registers;
    Chip8stack stack;
};

#endif // CHIP8_H_
