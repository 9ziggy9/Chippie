#ifndef CHIP8STACK_H_
#define CHIP8STACK_H_
#include "config.h"

// Kinda weird, we need to forward declare Chip8 struct to avoid
// loop during compilation; Chip8 has Chip8stack type nested in
// its implementation.
//
// Out of paranoia, I've chosen to return Chip8 to raw struct without
// typedef; though I noticed even with -Wall and -pedantic no actual
// compiler warning was given.
struct Chip8;

typedef struct {
    unsigned short buffer[CHIP8_STACK_DEPTH];
} Chip8stack;

void stack_push(unsigned short val, struct Chip8* chip8);
unsigned short stack_pop(struct Chip8* chip8);
void stack_dump(Chip8stack *stack);

#endif // CHIP8STACK_H_
