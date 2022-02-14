#include "../include/chip8memory.h"
#include <stdio.h>
#include <assert.h>

// TODO: handle memory checking more elegantly in future.
static void memory_in_bounds(int addr) {
    printf("Assert address 0x%x is in bounds", addr);
    assert(addr >= 0 && addr < CHIP8_MEMORY_SIZE);
    printf(" \033[0;32m\xE2\x9C\x93\033[0m\n"); // green check mark
}

void memory_init(Chip8memory *memory) {
    for (int i = 0; i < CHIP8_MEMORY_SIZE; i++) {
        memory->memory[i] = 0;
    }
}

void memory_set(int addr, unsigned char val, Chip8memory *memory) {
    memory_in_bounds(addr);
    memory->memory[addr] = val;
}

unsigned char memory_get(int addr, Chip8memory *memory) {
    memory_in_bounds(addr);
    return memory->memory[addr];
}

void memory_dump(Chip8memory *memory) {
    printf("----- MEMORY DUMP -----\n");
    for (int i = 0; i < CHIP8_MEMORY_SIZE; i++) {
        printf("\033[0;32m"); // set green
        if (memory->memory[i] != 0) {
            printf("Address 0x%x: \033[0m", i);
            printf("%c\n", memory->memory[i]);
        }
    }
    printf("\033[0m"); // set white
}
