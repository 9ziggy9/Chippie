#ifndef CHIP8REGISTERS_H_
#define CHIP8REGISTERS_H_

#include "config.h"

typedef struct {
    unsigned char V[CHIP8_TOTAL_GREGISTERS]; // 16 8-bit general
    unsigned short I; // 16-bit memory register
} Chip8registers;

#endif // CHIP8REGISTERS_H_
