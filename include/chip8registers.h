#ifndef CHIP8REGISTERS_H_
#define CHIP8REGISTERS_H_

#include "config.h"

typedef struct {
    unsigned char V[CHIP8_TOTAL_GEN_REGISTERS]; // 16 8-bit general
    unsigned short I; // 16-bit memory register
    unsigned char DT; // delay timer
    unsigned char ST; // sound timer
    unsigned short PC; // program counter
    unsigned char SP; // stack pointer
} Chip8registers;

#endif // CHIP8REGISTERS_H_
