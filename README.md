Chippie is a chip-8 emulator implemented in pure C

Graphics are provided through SDL2

Memory Map:
The Chip-8 language is capable of accessing up to 4KB (4,096 bytes) of RAM, from location 0x000 (0) to 0xFFF (4095). The first 512 bytes, from 0x000 to 0x1FF, are where the original interpreter was located, and should not be used by programs.

Most Chip-8 programs start at location 0x200 (512), but some begin at 0x600 (1536). Programs beginning at 0x600 are intended for the ETI 660 computer.

SOURCES:
chip-8 specifications - http://devernay.free.fr/hacks/chip8/C8TECH10.HTM
