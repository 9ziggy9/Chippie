#ifndef CONFIG_H_
#define CONFIG_H_

#define CHIP8_MEMORY_SIZE 4096
#define CHIP8_DISPLAY_WIDTH 64
#define CHIP8_DISPLAY_HEIGHT 32
#define CHIP8_TOTAL_GEN_REGISTERS 16
#define WINDOW_SCALE 15
#define CHIP8_STACK_DEPTH 16
#define CHIP8_KEYS 16
// sprites are stored in the interpreter are of chip8 memory
// (0x000 to 0x1FF)
#define CHIP8_CHAR_SET_ADDR 0x00

#endif // CONFIG_H_
