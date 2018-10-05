#include <stdio.h>
#include <stdlib.h>
#include "game_io.h"
#include "game.h"

piece pieces[25] ={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1};
//int test[25] ={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1};

//void printpiece(piece p){

//}

/*game NET,*/ 
void afficher_game(piece pieces[]){
	int height =5;
	int width =5;

	for( int i=0;i < height ;i++){	
		for( int j=0;j<width ;j++){
			int x = pieces[i+j];
            //printf("p:");
			printf("%d ",x);

            
		}
        printf("\n");
	}
}

int main(void){
    printf("main function called \n");
    afficher_game(pieces);
    printf("printing done \n");
    return 1;
}