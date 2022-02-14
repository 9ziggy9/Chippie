##
# CHIPPIE
# @version 0.1
INCLUDES=-I ./include
PKGS=sdl2
CFLAGS=-Wall -ggdb -std=c11 -pedantic `pkg-config --cflags sdl2`
LIBS=`pkg-config --libs sdl2`
OBJECTS=./build/chip8memory.o ./build/chip8registers.o

all: chip8memory chip8registers chippie

chippie: main.c $(OBJECTS)
	$(CC) $(INCLUDES) $(CFLAGS) main.c $(OBJECTS) $(LIBS) -o chippie

chip8memory: src/chip8memory.c
	$(CC) $(INCLUDES) -g ./src/chip8memory.c -c -o ./build/chip8memory.o

chip8registers: src/chip8registers.c
	$(CC) $(INCLUDES) -g ./src/chip8registers.c -c -o ./build/chip8registers.o

clean:
	rm -rf ./chippie ./build/*
# end
