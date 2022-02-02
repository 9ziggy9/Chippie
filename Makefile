##
# CHIPPIE
# @version 0.1
CFLAGS=-Wall -ggdb -std=c11 -pedantic
LIBS=

chippie: main.c
	$(CC) $(CFLAGS) -o chippie main.c $(LIBS)
# end
