##
# CHIPPIE
# @version 0.1
INCLUDES=-I ./include
PKGS=sdl2
CFLAGS=-Wall -ggdb -std=c11 -pedantic `pkg-config --cflags sdl2`
LIBS=`pkg-config --libs sdl2`
OBJECTS=./build/chip8memory.o ./build/chip8registers.o ./build/chip8stack.o ./build/chip8keyboard.o ./build/chip8.o ./build/chip8screen.o

all: chip8stack chip8memory chip8registers chip8keyboard chip8screen chip8 chippie

chippie: main.c $(OBJECTS)
	$(CC) $(INCLUDES) $(CFLAGS) main.c $(OBJECTS) $(LIBS) -o chippie

chip8: src/chip8.c
	$(CC) $(INCLUDES) -g ./src/chip8.c -c -o ./build/chip8.o

chip8memory: src/chip8memory.c
	$(CC) $(INCLUDES) -g ./src/chip8memory.c -c -o ./build/chip8memory.o

chip8registers: src/chip8registers.c
	$(CC) $(INCLUDES) -g ./src/chip8registers.c -c -o ./build/chip8registers.o

chip8stack: src/chip8stack.c
	$(CC) $(INCLUDES) -g ./src/chip8stack.c -c -o ./build/chip8stack.o

chip8keyboard: src/chip8keyboard.c
	$(CC) $(INCLUDES) -g ./src/chip8keyboard.c -c -o ./build/chip8keyboard.o

chip8screen: src/chip8screen.c
	$(CC) $(INCLUDES) -g ./src/chip8screen.c -c -o ./build/chip8screen.o

clean:
	rm -rf ./chippie ./build/*
# end
