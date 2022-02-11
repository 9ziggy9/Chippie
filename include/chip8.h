#ifndef CHIP8_H_
#define CHIP8_H_

#include "config.h"
#include "chip8memory.h"
#include "chip8registers.h"

typedef struct {
    Chip8memory memory;
    Chip8registers registers;
} Chip8;

#endif // CHIP8_H_
