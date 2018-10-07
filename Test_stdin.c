#include <stdio.h>
#include <stdlib.h>

int main () {

  /***********Déclarer les coordonnees etc**************/
  int x,y,res1,res2;
  /***************************************************/

  //int height =5;
  //int width =5;

/**********Mettre dans la boucle Wile*************/

  //printf("Enter x and y: ");
  res1 = scanf("%d", &x);
  res2 = scanf("%d", &y);

  if (res1==1 && res2==1 && x<width && y<height) {
    //printf("x: %d\n", x);
    //printf("y: %d\n", y);
    void rotate_piece_one(NET,x,y);
    afficher_game(piece pieces[], direction directions[]);

  }

  else {
    printf("error\n");

}
/***************************************************/

  return(0);
}
