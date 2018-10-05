#include "game_io.h"

game init_game_random(){
	piece pieces[25];
	direction directions[25];

	for (int i = 0; i < 25; i++) {
		pieces[i] = rand()%(0-4);
		directions[i] = 'N';
	}
	game g = new_game(pieces, directions);
	shuffle_dir(g);
	afficher(g, pieces);
	return g;
}
 
game init_game(piece *p, direction *d){
	piece pieces[25] = {2,0,0,2,0,3,3,3,3,3,0,0,3,0,1,2,3,3,2,1,0,3,0,0,0};
	p = pieces;
	direction directions[25] = {W,N,W,E,S,S,W,N,E,E,E,N,W,W,W,S,S,N,W,N,E,W,S,E,S};
	d = directions;
	game g = new_game(pieces, directions);
	return g;
}
