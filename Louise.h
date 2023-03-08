/*
 * Louise.h
 *
 *  Created on: 7 Mar 2023
 *      Author: call3
 */

#ifndef LOUISE_H_
#define LOUISE_H_

//*Structure of a yatzee-scoreboard*/
typedef struct scoreboard_column {
	int ones;
	int twos;
	int threes;
	int fours;
	int fives;
	int sixes;
	int first_total;
	int bonus;
	int pair;
	int two_pairs;
	int three_of_a_kind;
	int four_of_a_kind;
	int small_straight;
	int large_straight;
	int full_house;
	int chance;
	int yatzy;
	int total_score;

}scoreboard_column;

/*Struct that contains a player-name and a scoreboard for that player*/
typedef struct scoreboard {
	char name[20];
	struct scoreboard_column;

}scoreboard;

/*Function that calculates the sum of dicepool*/
int sum_pool(int *dice_pool, int size);

/*Function to print game menu*/
void print_game_menu();
