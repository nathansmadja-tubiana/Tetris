#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#include <unistd.h>

#include "board.h"
#include "piece.h"
#include "color.h"
#include "record.h"


unsigned long getTimeUSeconds() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return t.tv_sec * 1000000 + t.tv_usec;
}


/* Display the main board
*   param Board the game board to display
*   param int the score to display
*   param int the number of point to add to the score
*/
void displayUIAndAdd(Board tab, int score, int add) {
	clearScreen();
	color(1);
	printf("\nScore : %d", score);

	if (add > 0) {
		printf(" + %d", add);

		if (add > 3) {
			color(31);
			printf("   TETRIS !");
		}
	}
	printf("\n\n");
	color(0);
	displayBoard(tab);
}

/* Display the main board
*   param Board the game board to display
*   param int the score to display
*/
void displayUI(Board tab, int score) {
	displayUIAndAdd(tab, score, 0);
}

/* Compute the height the piece should be placed at
*   param Board the game board
*   param Piece the piece to place
*   return int the choosen column for the piece
*/
int computePieceHeight(Board tab, Piece p, int row) {
	int min_height = tab.height - 1;
	// We check the minimum height where the piece 
	// should be dropped for each row
	for(int j = row; j < row+p.width; j++) {
		int piece_height = 0;
		// We check the height of the choosen row of the piece
		for(int h = 0; h < p.height; h++) {
			//printf("%c ", p.shape[h][j-row]);
			if (p.shape[h][j-row] == '@') {
				piece_height = h+1;
			}
		}
		//printf("  Height : %d\n", height);
		
		int row_height = 0;
		// We check the height of the choosen row of the board
		while(row_height < tab.height && tab.grid[row_height][j] == 0){
			//printf("row_height=%d j=%d  %d \n", row_height, j, tab.grid[row_height][j]);
			row_height++;
		}
		// Check if this row is a new minimum
		if (row_height - piece_height < min_height) {
			min_height = row_height - piece_height;
		}
	}
	return min_height;
}

/* Put the piece at the given position in the board
*   param Board the game board
*   param Piece the piece to place
*   param int the choosen column
*   param int the height of the piece
*/
void placePiece(Board tab, Piece p, int row, int pos){
	//printf("%d \n ", pos);
	for(int j=0; j<p.height;j++){
		for(int i=0; i<p.width; i++){
			if(p.shape[j][i] == '@'){
				// Update the board to add the piece at [pos][row]
				tab.grid[pos+j][row+i] = p.color;
			}
		}
	}
}

/* Ask in wich column the piece should be placed
*   param Board the game board
*   param Piece the piece to place
*   return int the valid user input
*/
int chooseColumn(Board tab, Piece p){
	char inputChar, trash;
	int input;
	int valid = 1;
	do {
		// Empty the input buffer to avoid left garbage
		while((trash = getchar()) != '\n' && trash != EOF);

		if (!valid) {
			printf("Input non valide\n");
		}

		printf("Choix de la colonne :\n");
		scanf("%c",&inputChar);
		// Convert the input char into a int
		input = inputChar;
		// If input is [A-Z]
		if (input > 64 && input < 91) {
			input -= 65;
		// If input is [a-z]
		} else if (input > 96 && input < 123) {
			input -= 97;
		} else {
			input = -1;
		}
		//printf("%d\n", input);
		valid = 0;
		
	} while( input < 0 || p.width+input > tab.width);
	return input;
}

/* Start the main loop
*   param Board the game board
*   param Piece[] the list of Tetris pieces
*   param int the difficulty
*/
void startGame(Board tab, Piece tabPiece[7][4], int difficulty) {
	int score = 0;
	int game_over = 0;
    float delay = 10;
	
	while (!game_over) {
		displayUI(tab, score);
        printf("Vous avez %0.1f secondes pour répondre.\n\n", delay);
        unsigned long start = getTimeUSeconds();
        int randomPiece = rand()%7;
		Piece p = choosePiece(tabPiece[randomPiece]);
		int row = chooseColumn(tab,p);
        if(getTimeUSeconds() > start + delay) {
            printf("\nVous avez mis trop de temps à répondre !\n");
            p = tabPiece[randomPiece][rand()%4];
            row = rand()%(tab.width - p.width + 1);
            usleep(400000);
        }
		int pos = computePieceHeight(tab, p, row);
        
        if (delay > 5) {
            delay -= difficulty * 0.1;
        } else if (delay > 3) {
            delay -= difficulty * 0.05;
        } else {
            delay -= difficulty * 0.03;
        }
		
		if (pos >= 0) {
			placePiece(tab, p, row, pos);
			int nb_full_line = countFullLine(tab);

			if (nb_full_line > 0) {
				displayUIAndAdd(tab, score, nb_full_line);
				usleep(600000);
				breakFullLine(tab);
				score += nb_full_line;
			}

		} else {
			game_over = 1;
			displayUI(tab, score);
			color(31);
			printf("\n\nGame over. Score : %d\n\n", score);
			color(0);

            char player[10];
            printf("Quel est votre nom ? (10 charactères max) :\n");
            scanf("%10s", player);
            printf("\n\n");

			int record = getPlayerScore(player);
			if (score > record) {
				color(5);
				printf("Nouveau record !\n\n");
				color(0);
				changeRecordPlayer(player, score, record);
			}
		}
	}
}

int main(int argc, char *argv[]){
    int height = 10;
    int width = 10;
    int difficulty = 1;
    for(int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            if (argv[i][1] == 'h' && i < argc - 1) {
                height = atoi(argv[i+1]);
                i++;
            } else if (argv[i][1] == 'l') {
                width = atoi(argv[i+1]);
                i++;
            } else if (argv[i][1] == 'd') {
                difficulty = atoi(argv[i+1]);
                if (difficulty < 1)
                    difficulty = 1;
                i++;
            } else {
                printf("Argument non reconnu\n");
                return 1;
            }
        } else {
            printf("Argument malformé\n");
            return 1;
        }
    }

    printf("Height : %d   Width : %d   Difficulty : %d\n", height, width, difficulty);

	Board tab = setBoard(height, width);
	
	// Create all pieces
	Piece tabPiece[7][4];
    setTabPiece(tabPiece);
	
	// fin de creation de piece
	srand(time(NULL));
	startGame(tab, tabPiece, difficulty);
	return 0;
}