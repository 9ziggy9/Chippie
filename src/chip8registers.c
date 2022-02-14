#include "../include/chip8registers.h"
#include <stdio.h>
#include <assert.h>
#include "../include/config.h"

// TODO: handle register checking more elegantly in future.
static void register_in_bounds(int addr) {
    printf("Assert register 0x%x is in bounds", addr);
    assert(addr >= 0 && addr < CHIP8_TOTAL_GEN_REGISTERS);
    printf(" \033[0;32m\xE2\x9C\x93\033[0m\n"); // green check mark
}

void registers_initV(Chip8registers *registers) {
    for (int i = 0; i < CHIP8_TOTAL_GEN_REGISTERS; i++) {
        registers->V[i] = 0;
    }
}

void register_setV(int addr, unsigned char val, Chip8registers *registers) {
    register_in_bounds(addr);
    registers->V[addr] = val;
}

unsigned char register_getV(int addr, Chip8registers *registers) {
    register_in_bounds(addr);
    return registers->V[addr];
}
