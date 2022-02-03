##
# CHIPPIE
# @version 0.1
PKGS=sdl2
CFLAGS=-Wall -ggdb -std=c11 -pedantic `pkg-config --cflags sdl2`
LIBS=`pkg-config --libs sdl2`
HDRS=include/colors.h

chippie: main.c $(HDRS)
	$(CC) $(CFLAGS) -o chippie main.c $(LIBS)

clean:
	rm -rf ./chippie
# end
