#ifndef __GAME_H__
#define __GAME_H__
#include <stdbool.h>

/**
 * @file game.h
 *
 * @brief This file describes the programming interface of a puzzle
 * game, named 'Net'.
 *
 * @mainpage
 *
 * This game was originally invented by David Millar. A demo of this game is 
 * provided in the Simon Tatham's Portable Puzzle Collection, under the name
 * <a href="https://www.chiark.greenend.org.uk/~sgtatham/puzzles/js/net.html">'Net'</a>.
 *
 * The goal of the game is to join up the pieces on a grid into a single 
 * conected network with no loops. This can be achieved by rotating the squares of 
 * the grid in a clockwise manner.
 *
 * The squares of the grid are denoted by (x,y) coordinates, (0,0) corresponding to 
 * the bottom left corner, and the first coordinate indicating the column.
 * *
 * Here is an example of a game and its solution.
 *
 @verbatim
 
 | Example of game

|  ┘ ^ < └ v  |  ┌ < > ┐ v  |
|  ┬ ┤ ┴ ├ ├  |  ├ ┬ ┬ ┴ ┤  |
|  > ^ ┤ < -  |  ^ ^ ├ < |  |
|  v ┬ ┴ ┘ |  |  > ┬ ┴ ┐ |  |
|  > ┤ v > v  |  > ┴ < ^ ^  |
|             |             |
|    start    |   solution  |

 @endverbatim
 * Observe the four types of pieces in their default direction (North):
 * leaf (^), segment (|) corner (└) and tee (┴).
 * Note that a leaf directed West (<) cannot be connected to its right 
 * to another piece . This is also true for a segment directed North/South (|),
 * a tee to West (┤) and a corner directed South (┐) or West (┘). 
 * Observe that in the solution all the pieces are connected in a network without loops.
 **/

/**
 * @brief The possible pieces
 **/

typedef enum piece_e {EMPTY=-1, LEAF=0, SEGMENT=1, CORNER=2, TEE=3} piece;

#define NB_PIECE_TYPE 4



/**
 * @brief The four cardinal directions
 **/

typedef enum direction_e {N,E,S,W} direction;

#define NB_DIR 4

/**
 * @brief The structure pointer that stores the game
 **/

typedef struct game_s* game;



/**
 * @brief The structure constant pointer that stores the game
 * 
 * That means that it is not possible to modify the game using this pointer.
 * See also: http://www.geeksforgeeks.org/const-qualifier-in-c/
 * See also this more technical discussion: http://stackoverflow.com/questions/8504411/typedef-pointer-const-weirdness
 **/

typedef const struct game_s* cgame;


/**
 * @brief Creates an empty game (DEFAULT_SIZE x DEFAULT_SIZE) with squares set to empty and directions set to North
 * 
 * @return the newly created game
 **/

game new_game_empty();



/**
 * @brief Creates a new game having a square grid of DEFAULT_SIZE x DEFAULT_SIZE
 * 
 * @param pieces the pieces to fill the grid
 * @param initial_directions the directions in which the pieces are oriented initially
 * @return the newly created game
 **/

game new_game(piece *pieces, direction *initial_directions);




/**
 * @brief Initialises a grid square to a given piece and orientation
 * 
 * @param game the game to be modified
 * @param x the x coordinate (the column) of the square on the grid
 * @param y the y coordinate (the row) of the square on the grid
 * @param piece the piece to be put in the grid square
 * @param orientation the initial orientation of the piece
 **/

void set_piece(game g, int x, int y, piece piece, direction orientation);



/**
 * @brief Shuffles the orientations of the pieces
 * 
 * @param g the game to be shuffled
 **/

void shuffle_dir(game g);

/**
 * @brief Return the number of rows on the grid
 *
 * @param game the game
 * @return the height of the game
 **/

int game_height(cgame game);


/**
 * @brief Return the number of columns on the game
 *
 * @param game the game
 * @return the width of the game
 **/

int game_width(cgame game); 


/**
 * @brief Rotates a piece once clockwise
 *
 * @param game the game
 * @param x the x coordinate of the piece on the grid
 * @param y the y coordinate of the piece on the grid
 **/

void rotate_piece_one(game game, int x, int y);


/**
 * @brief Rotates a piece several times clockwise
 *
 * @param game the game
 * @param x the x coordinate of the piece on the grid
 * @param y the y coordinate of the piece on the grid
 * @param nb_ccw_quarter_turn number of clockwise turns to be applied
 **/

void rotate_piece(game game, int x, int y, int nb_cw_quarter_turn);

/**
 * @brief set the current dir of piece located at (x,y)
 * 
 * @param x the column (x coordinate) of the piece on the grid
 * @param y the row (y coordinate) of the piece on the grid
 * @param dir the direction in which to test whether the piece could be connecte
 **/
void set_piece_current_dir (game game, int x, int y, direction dir);

/**
 * @brief Tests whether a piece on a given position is oriented so as it could be connected in the given direction
 *
 * @param g a constant pointer on the game
 * @param x the column (x coordinate) of the piece on the grid
 * @param y the row (y coordinate) of the piece on the grid
 * @param dir the direction in which to test whether the piece could be connected
 * @return true if the piece on (x,y) could be connected in the direction dir, false otherwise
 **/

bool is_edge_coordinates(cgame g, int x, int y, direction dir);


/**
 * @brief Tests whether a piece with a specific orientation could be connected in the given direction
 *
 * @param piece the type of the piece
 * @param orientation the orientation of the piece
 * @param dir the direction in which to test whether the piece could be connected
 * @return true if the piece could be connected in the direction dir, false otherwise
 **/

bool is_edge(piece piece, direction orientation, direction dir);


/**
 * @brief Compute the opposite of a given direction
 *
 * @param dir the direction
 * @return the opposite direction of dir
 **/

direction opposite_dir(direction dir);
 

/**
 * @brief Clone the game g_src
 * 
 * @param g_src a constant pointer on the game to clone
 * @return the clone of g_src
 **/
game copy_game (cgame g_src);


/**
 * @brief Destroy the game and free allocated memory
 * 
 * @param g the game to destroy
 **/
void delete_game (game g);


/**
 * @brief Get the piece of a square on the grid
 * 
 * @param game the game we consider
 * @param x the x coordinate of the square
 * @param y the y coordinate of the square
 * @return the piece of the square
 **/

piece get_piece(cgame game, int x, int y);


/**
 * @brief Get the current orientation of a square on the grid
 * 
 * @param g a constant pointer on the game we consider
 * @param x the x coordinate of the square
 * @param y the y coordinate of the square
 * @return the current orientation
 **/

direction get_current_dir(cgame g, int x, int y);


/**
 * @brief Test if the game is over (that is the grid is filled according to the requirements)
 * 
 * @return true if all the constraints are satisfied
 **/

bool is_game_over (cgame g);


/**
 * @brief Restart a game by cleaning monsters from the board.
 **/

void restart_game(game g);

#endif // __GAME_H__
