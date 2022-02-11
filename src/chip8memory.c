#include "../include/chip8memory.h"
#include <stdio.h>
#include <assert.h>

// Handle more elegantly in the future
static void memory_in_bounds(int addr) {
    printf("Assert address 0x%x is in bounds", addr);
    assert(addr >= 0 && addr < CHIP8_MEMORY_SIZE);
    printf(" \033[0;32m\xE2\x9C\x93\033[0m\n"); // green check mark
}

void memory_set(int addr, unsigned char val, Chip8memory *memory) {
    memory_in_bounds(addr);
    memory->memory[addr] = val;
}

unsigned char memory_get(int addr, Chip8memory *memory) {
    memory_in_bounds(addr);
    return memory->memory[addr];
}
