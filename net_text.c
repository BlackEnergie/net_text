#include <stdio.h>
#include <stdlib.h>
#include "game_io.h"

int main(void){
	game NET = init_game();
	return 1;
}

game init_game(){
	piece pieces[25];
	direction directions[25];

	for (size_t i = 0; i < 25; i++) {
		pieces[i] = rand()%(0-4);
		directions[i] = 'N';
	}
	game g = new_game(pieces, directions);
	shuffle_dir(g);
	afficher(g, pieces);
	return g;
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
