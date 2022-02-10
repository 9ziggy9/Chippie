##
# CHIPPIE
# @version 0.1
INCLUDES=-I ./include
PKGS=sdl2
CFLAGS=-Wall -ggdb -std=c11 -pedantic `pkg-config --cflags sdl2`
LIBS=`pkg-config --libs sdl2`
OBJECTS=./build/chip8memory.o

all: chip8memory chippie

chippie: main.c $(OBJECTS)
	$(CC) $(INCLUDES) $(CFLAGS) main.c $(OBJECTS) $(LIBS) -o chippie

chip8memory: src/chip8memory.c
	$(CC) $(INCLUDES) -g ./src/chip8memory.c -c -o ./build/chip8memory.o

clean:
	rm -rf ./chippie ./build/*
# end
