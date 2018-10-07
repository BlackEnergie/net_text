#include <stdio.h>
#include <stdlib.h>
#include "game_io.h"
#include "game.h"
#include "afficher.c"
#include "init_game.c"

piece *p;
direction *d;
int x,y,res1,res2;
int height =5;
int width =5;

game init_game(piece *p, direction *d);

int main(void){
	game NET = init_game(p,d);
	//printf("%d \n",get_piece(NET, 2,4));



	while (true) {
		res1 = scanf("%d", &x);
	  res2 = scanf("%d", &y);

	  if (res1==1 && res2==1 && x<width && y<height) {
	    //printf("x: %d\n", x);
	    //printf("y: %d\n", y);
	    rotate_piece_one( NET,x,y);
	    afficher_game(p,d);

	  }

	  else {
	    printf("error\n");

	  }
	}

	return 1;
}
