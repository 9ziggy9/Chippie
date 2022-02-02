##
# CHIPPIE
# @version 0.1

CC := clang

CFLAGS := `sdl2-config --libs --cflags` -ggdb3 -O0 --std=c99 -Wall -pedantic -lSDL2_image -lm -lSDL2_gfx -lSDL2_ttf

SRCS := hello.c

OBJS := $(SRCS:.c=.o)

EXEC := chippie

all: $(EXEC)

$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

# recipe for building object files
#$(OBJS): $(@:.o=.c) $(HDRS) Makefile
#	$(CC) -o $@ $(@:.o=.c) -c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean

# end
