#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <stdlib.h>

#include "color.h"

// The Board will contains numbers that represents
// the color of the case
typedef struct {
	int height;
	int width;
	int** grid;
} Board;

/* Display the game board
*   param Board the game board to display
*/
void displayBoard(Board tab);

/* Initialize the board
    * return Board the board created
*/
Board setBoard(int height, int width);

/* Remove full lines
*   param Board the game board
*/
void breakFullLine(Board tab);

/* Check how many lines are full 
*   param Board the game board
*   return int the number of full lines
*/
int countFullLine(Board tab);

#endif