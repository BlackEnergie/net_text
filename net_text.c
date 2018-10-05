#include <stdio.h>
#include <stdlib.h>
#include "game_io.h"
#include "afficher.c"
//#include "init_game.c"

piece *p;
direction *d;

game init_game(piece *p, direction *d);

int main(void){
	game NET = init_game(p,d);
	printf("%d \n",get_piece(NET, 2,4));
	return 1;
}
