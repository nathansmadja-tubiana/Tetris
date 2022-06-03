#ifndef PIECE_H
#define PIECE_H

#include <stdio.h>
#include <stdlib.h>

#include "color.h"

typedef struct {
	int height;
	int width;
	int color;
	char** shape;
} Piece;


/* Display a piece
*   param Piece the piece to display
*/
void displayPiece(Piece p);

/* Display the list of pieces horizontally
*   param Piece[] the list to display
*/
void displayPieceChoice(Piece list[4]);

/* Ask the orientation the piece should have
*   param Piece[] the list of possibilities
*   return Piece the choosen piece
*/
Piece choosePiece(Piece list[4]);

/* Create all pieces
*   param Piece[][] the array to save pieces
*/
void setTabPiece(Piece tabPiece[7][4]);

#endif