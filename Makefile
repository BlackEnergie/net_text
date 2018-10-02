CC = gcc
CFLAGS = -Wall -std=c99
LDFLAGS = -lm -lgame -L .

ALL : libgame.a net_text

net_text : net_text.o libgame.a
	$(CC) net_text.o -o net_text $(LDFLAGS)

net_text.o : net_text.c
	$(CC) $(CFLAGS) -c net_text.c

libgame.a : game_io.o game.o
	ar rcs libgame.a game.o game_io.o -s

clean :
	rm -f net_text net_text.o libgame.a
