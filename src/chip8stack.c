#include <assert.h>
#include <stdio.h>
#include "../include/chip8stack.h"
#include "../include/chip8.h"

static void stack_in_bounds(struct Chip8* chip8) {
    assert(chip8->registers.SP < CHIP8_STACK_DEPTH);
}

void stack_push(unsigned short val, struct Chip8* chip8) {
    stack_in_bounds(chip8);
    chip8->stack.buffer[chip8->registers.SP] = val;
    chip8->registers.SP++;
}

unsigned short stack_pop(struct Chip8* chip8) {
    chip8->registers.SP--;
    stack_in_bounds(chip8);
    return chip8->stack.buffer[chip8->registers.SP];
}

void stack_dump(Chip8stack *stack) {
    printf("----- STACK DUMP -----\n");
    for (int i = CHIP8_STACK_DEPTH; i >= 0; i--) {
        printf("\033[0;32m"); // set green
        printf("Buffer frame %d: \033[0m", i);
        printf("%x\n", stack->buffer[i]);
    }
    printf("\033[0m"); // set white
}
