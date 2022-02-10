#include "chip8memory.h"

void memory_set(int addr, unsigned char val, Chip8memory *memory) {
    memory->memory[addr] = val;
}

unsigned char memory_get(int addr, Chip8memory *memory) {
    return memory->memory[addr];
}
