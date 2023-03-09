/*
 * cornel.h
 *
 *  Created on: 7 Mar 2023
 *      Author: Cornel
 */

#ifndef CORNEL_H_
#define CORNEL_H_



#endif /* CORNEL_H_ */


//This is the struct for top ten scores with names

typedef struct top_ten{

	char name [50];
	int score;


}top_ten;

int compare_top_ten (const void *a, const void *b);
bool save_top_ten (char *filename,  top_ten players[]);
bool read_top_ten (char *filename,  top_ten fromfile[]);
void print_top_ten (top_ten players[]);
void load_highscore(top_ten *players);
