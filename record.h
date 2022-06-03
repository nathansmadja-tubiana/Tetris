#ifndef RECORD_H
#define RECORD_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Compare two strings
*   param char[] the first string to compare
*   param char[] the second string to compare
*   return int boolean if egal
*/
int charEgal(char a[],char b[]);

/* Read the player's score from score.txt file
*   param char[10] the player's name
*   return int the score (-1 if file not found)
*/
int getPlayerScore(char player[10]);

/* Change the player's score or add it to the list
*   param FILE* the file containing the list of record
*   param char[10] the player's name
*   param int the new score
*   param int the old score
*/
void addPlayerScore(FILE* file, char player[10], int new_score, int old_score);

/* Update the list of record or create it
*   param char[10] the player's name
*   param int the new score
*   param int the old score
*/
void changeRecordPlayer(char player[10], int new_score, int old_score);

#endif