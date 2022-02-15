#include <assert.h>
#include <stdio.h>
#include "../include/chip8stack.h"
#include "../include/chip8.h"

static void stack_in_bounds(Chip8* chip8) {
}

void stack_push(unsigned short val, Chip8* chip8) {
    printf("Chip8 %d", chip8->registers.V[0]);
}
