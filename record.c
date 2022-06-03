#include "record.h"

/* Compare two strings
*   param char[] the first string to compare
*   param char[] the second string to compare
*   return int boolean if egal
*/
int charEgal(char a[],char b[])  {
    int i=0;
    // While char[] are not finished (\0 = end of string)
    while(a[i] != '\0' || b[i] != '\0') {
        // We look for a difference
        if(a[i] != b[i]) {  
            return 0; 
        }  
        i++;  
    }
    return 1;
}  

/* Read the player's score from score.txt file
*   param char[10] the player's name
*   return int the score (-1 if file not found)
*/
int getPlayerScore(char player[10]) {
    int size;
    char player_read[10];
    int score;
    FILE* file = fopen("score.txt", "r");
    if (file == NULL) {
        return -1;
    }

    fscanf(file, "%d", &size);
    // Check for each player register
    for (int i = 0; i < size; i++) {
        fscanf(file, "%s", player_read);
        fscanf(file, "%d", &score);
        if (charEgal(player_read, player)) {
            return score;
        }
    }
    return -1;
}

/* Change the player's score or add it to the list
*   param FILE* the file containing the list of record
*   param char[10] the player's name
*   param int the new score
*   param int the old score
*/
void addPlayerScore(FILE* file, char player[10], int new_score, int old_score) {
    FILE* file_tmp = fopen("score_tmp.txt", "w");
    if(file_tmp == NULL) {
        printf("File can't be written\n");
        return;
    }

    int size;
    char player_read[10];
    int score = -1;

    fscanf(file, "%d", &size);
    if (old_score == -1) {
        fprintf(file_tmp, "%d\n", size+1);
    } else {
        fprintf(file_tmp, "%d\n", size);
    }

    for (int i = 0; i < size; i++) {
        fscanf(file, "%s", player_read);
        fscanf(file, "%d", &score);

        fprintf(file_tmp, "%s\n", player_read);
        if (charEgal(player_read, player)) {
            fprintf(file_tmp, "%d\n", new_score);
        } else {
            fprintf(file_tmp, "%d\n", score);
        }
    }
    if (old_score == -1) {
        fprintf(file_tmp, "%s\n", player);
        fprintf(file_tmp, "%d\n", new_score);
    }

    fclose(file_tmp);
    rename("score_tmp.txt", "score.txt");
}

/* Update the list of record or create it
*   param char[10] the player's name
*   param int the new score
*   param int the old score
*/
void changeRecordPlayer(char player[10], int new_score, int old_score) {
	FILE* file = fopen("score.txt", "r");

	if (file == NULL) {
        file = fopen("score.txt", "w");
        if(file == NULL) {
		    printf("File can't be written\n");
            return;
		}
        fprintf(file, "1\n");
        fprintf(file, "%s\n", player);
        fprintf(file, "%d\n", new_score);
		fclose(file);

    } else {
        addPlayerScore(file, player, new_score, old_score);
        fclose(file);
    }
}
