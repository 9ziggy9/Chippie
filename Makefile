##
# CHIPPIE
# @version 0.1
INCLUDES=-I ./include
PKGS=sdl2
CFLAGS=-Wall -ggdb -std=c11 -pedantic `pkg-config --cflags sdl2`
LIBS=`pkg-config --libs sdl2`
OBJECTS=./build/chip8memory.o

chippie: main.c
	$(CC) $(CFLAGS) -o chippie main.c $(LIBS)

chip8memory: src/chip8memory.c
	$(CC) $(INCLUDES) ./src/chip8memory.c -c -o ./build/chip8memory.o

clean:
	rm -rf ./chippie ./build/*
# end
