#include "../include/chip8memory.h"
#include <assert.h>

// Handle more elegantly in the future
static void memory_in_bounds(int addr) {
    assert(addr >= 0 && addr < CHIP8_MEMORY_SIZE);
}

void memory_set(int addr, unsigned char val, Chip8memory *memory) {
    memory_in_bounds(addr);
    memory->memory[addr] = val;
}

unsigned char memory_get(int addr, Chip8memory *memory) {
    memory_in_bounds(addr);
    return memory->memory[addr];
}
