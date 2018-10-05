#include <stdio.h>
#include <stdlib.h>
#include "game_io.h"

int main(void){
	game NET = init_game();
	return 1;
}

void afficher(game g, piece *pieces){
	int height = game_height(g);
	int width = game_width(g);
	int p =0;

	for( int i=0;i == height ;i++){
		printf("\n");
		for( int j=0;j==width ;j++){
			piece x = pieces[p];
			p = p+1;
			printf("%d \n",x);
		}
	}
}
