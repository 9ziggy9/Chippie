#ifndef CHIP8MEMORY_H_
#define CHIP8MEMORY_H_
#include "config.h"

typedef struct {
    unsigned char memory[CHIP8_MEMORY_SIZE];
} Chip8memory;

void memory_set(int addr, unsigned char val, Chip8memory *memory);
unsigned char memory_get(int addr, Chip8memory *memory);
#endif // CHIP8MEMORY_H_
