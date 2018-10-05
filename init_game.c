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
