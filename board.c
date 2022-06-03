#include "board.h"

/* Display the game board
*   param Board the game board to display
*/
void displayBoard(Board tab){
	//printf("\n A B C D E F G H I J ...\n");
	int intCharRow = 65;
	char charRow;
	for (int i = 0; i < tab.width; i++){
		charRow = intCharRow;
		printf(" %c", charRow);
		intCharRow++;
	}
	printf("\n");
	
	// Print the grid
	for (int i = 0; i < tab.height; i++){
		printf("|");
		for (int j = 0; j < tab.width; j++){
			color(tab.grid[i][j]);
			if (tab.grid[i][j] == 0) {
				printf(" ");
			} else if (tab.grid[i][j] == 1) {
				printf("*");
			} else {
				printf("@"); // ■
			}
			color(0);
			printf("|");
		}
		printf("\n");
	}
	for (int i = 0; i < tab.width; i++){
		printf("——");
	}
	printf("—\n\n");
}

/* Initialize the board
* return Board the board created
*/
Board setBoard(int height, int width) {
    Board tab;
    tab.height = height;
    tab.width = width;
    tab.grid = malloc(sizeof(int*)*tab.height);
    for (int i = 0; i < tab.height; i++){
        tab.grid[i] = malloc(sizeof(int)*tab.width);
		for (int j = 0; j < tab.width ; j++){
			tab.grid[i][j] = 0;
		}
	}
    return tab;
}

/* Remove full lines
*   param Board the game board
*/
void breakFullLine(Board tab) {
	for(int i = 0; i < tab.height; i++) {
		// 1 <=> line that should be breaked
		if (tab.grid[i][0] == 1) {
			// Empty the line
			for(int j = 0; j < tab.width; j++) {
				tab.grid[i][j] = 0;
			}
			// Shift every line above the one breaked
			// one time down
			for(int k = i - 1; k >= 0; k--) {
				for(int j = 0; j < tab.width; j++) {
					tab.grid[k+1][j] = tab.grid[k][j];
				}
			}
			// Empty the all top line
			for(int j = 0; j < tab.width; j++) {
				tab.grid[0][j] = 0;
			}
		}
	}
}

/* Check how many lines are full 
*   param Board the game board
*   return int the number of full lines
*/
int countFullLine(Board tab) {
	int nb_full_line = 0;
	for(int i = 0; i < tab.height; i++) {
		int line_full = 1;
		for(int j = 0; j < tab.width; j++) {
			// if one case in the line is empty
			if (tab.grid[i][j] == 0) {
				// the line is not full
				line_full = 0;
			}
		}

		if (line_full) {
			nb_full_line++;
			// Flag the line for display and breakFullLine
			for(int j = 0; j < tab.width; j++) {
				tab.grid[i][j] = 1;
			}
		}
	}
	
	// Tetris bonus
	if (nb_full_line == 4) {
		nb_full_line += 2;
	}
	return nb_full_line;
}