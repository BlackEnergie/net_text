#include <stdio.h>
#include <stdlib.h>
#include "game_io.h"
#include "game.h"

piece pieces[25] ={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1};
//int test[25] ={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1};
direction directions[25] = {W,N,W,E,S,S,W,N,E,E,E,N,W,W,W,S,S,N,W,N,E,W,S,E,S};
//void printpiece(piece p){
//}

/*game NET,*/ 
void afficher_game(piece pieces[], direction directions[]){
	int height =5;
	int width =5;

	for( int i=0;i < height ;i++){	
		for( int j=0;j<width ;j++){
			int x = pieces[i+j];
			direction y = directions[i+j];
            //printf("p:");
			  if (x == 0){
			    if (y ==N)
			       printf("^");
			    else if (y == E)
                               printf(">");
                            else if (y == S)
			       printf("v");
			    else
			     printf("<");
			  }
			else if (x == 1){ 
				  if (y == N|| y == S)
				    printf("|");
			  else
			    printf("-");
}
			if (x == 2){ 
			  if( y == N)
				    printf("└");
			  else if( y == E)
					 printf("┌");
                          else if (y == S)
					 printf("┐");
			   else
			     printf("┘");
			}
			if (x == 3){ 
			  if (y == N)
				    printf("┴");
			  else if( y == E)
					 printf("├");
                          else if (y == S)
					 printf("┬");
			   else
			     printf("┤");
			}	 


            
		}
        printf("\n");
	}
}

int main(void){
    printf("main function called \n");
    afficher_game(pieces,directions);
    printf("printing done \n");
    return 1;
}
