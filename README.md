## CHIPPIE README

Chippie is a chip-8 emulator implemented in pure C
Graphics are provided through SDL2

## INSTALLATION

``` shell
git clone https://github.com/9ziggy9/Chippie
cd Chippie
make
./chippie
```

### SPECIFICATIONS
Memory Map:
The Chip-8 language is capable of accessing up to 4KB (4,096 bytes) of RAM, from location 0x000 (0) to 0xFFF (4095). The first 512 bytes, from 0x000 to 0x1FF, are where the original interpreter was located, and should not be used by programs.

Most Chip-8 programs start at location 0x200 (512), but some begin at 0x600 (1536). Programs beginning at 0x600 are intended for the ETI 660 computer.

Note that stack is not part of main memory, it is a set of 16 16-bit values.

Data registers are from V0-VF.
There is an addition register named "I" that is generally used to store memory addresses.

Also has 16-bit PC (program counter), next instruction executed after 2 byte step.
Also has 8-bit stack pointer, register that points to a location in stack.

Sound timer and delay timer (st and dt) execute when non-zero, decrements at rate of
60 hz.

Display is monochromatic 64x32 pixels (we will scale up)
When pixel collisions occur, they XOR'd.
Pixels out of range will be remapped to opposite edges.

#### SOURCES
chip-8 specifications: http://devernay.free.fr/hacks/chip8/C8TECH10.HTM
guide: https://tobiasvl.github.io/blog/write-a-chip-8-emulator/
