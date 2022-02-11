#ifndef CHIP8REGISTERS_H_
#define CHIP8REGISTERS_H_
#include "config.h"

typedef struct {
    unsigned char v[CHIP8_TOTAL_GREGISTERS];
} Chip8registers;

#endif // CHIP8REGISTERS_H_
