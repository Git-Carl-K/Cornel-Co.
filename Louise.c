/*
 * Louise.c
 *
 *  Created on: 7 Mar 2023
 *      Author: call3
 */

#include <stdio.h>
#include <stdlib.h>

/*Function that calculates the sum of dicepool*/
int sum_pool(int *dice_pool, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += dice_pool[i];
	}
	return sum;
}

/*Function to print game menu*/
void print_game_menu() {
	int choice;
	printf("-------------------------------");
	printf("\n      Welcome to Yahtzee!    \n");
	printf("-------------------------------");
	printf("\n          GAME MENU          \n");
	printf("\n1. Single player\n");
	printf("\n2. Multiplayer\n");
	printf("\n3. View highscores\n");
	printf("\n4. Settings\n");
	printf("\n5. Quit game\n");
	printf("-------------------------------");
	printf("\nChoose an option (1-5)\n");
	fflush(stdout);
	scanf("%d", &choice);
	printf("\nYou chose option %d\n", choice);

	printf("\n\n\n");

	if (choice == 1) {
		int single_choice;
		printf("-------------------------------");
		printf("\n   Single Player Menu      \n");
		printf("-------------------------------");
		printf("\n1. New game                \n");
		printf("\n2. Load game \n");
		printf("\nChoose an option (1-2)  ");
		fflush(stdout);
		scanf("%d", &single_choice);
		if (single_choice == 1) {
			printf("Loading new game...");
		}
		if (single_choice == 2){
			printf("Loading old game...");
			}
	}

	if (choice == 2) {
		int multi_choice;
		printf("-------------------------------");
		printf("\n      Multiplayer Menu     \n");
		printf("-------------------------------");
		printf("\n1. New game\n");
		printf("\n2. Load game\n");
		printf("\nChoose an option (1-2)  \n");
		fflush(stdout);
		scanf("%d", &multi_choice);
		if (multi_choice == 1) {
			printf("Loading new game...");
		}
		if (multi_choice == 2){
			printf("Loading old game...");
			}
	}

	if (choice == 5) {
		printf("Bye bye, hope to see you soon again");
	}

}

/*Function to calculate the first total
it takes the top_column of the scoreboard struct as an argument*/
int calculate_first_total(scoreboard top_column){
	int top_sum = 0;

	for (int i = 0; i < 6; i++)
	{
		int field_value = *((int*)&top_column.score + i); //Access the i-th field in the struct
		top_sum += field_value;
	}
	top_column.score.first_total = top_sum;
	return top_sum;
}

/*Function to calculate the bonus
it takes the of bonus of the scoreboard struct as an argument*/
int calculate_bonus(scoreboard bonus_score){
	bonus_score.score.bonus = 50;

	if (calculate_first_total(bonus_score) >= 63)
	{
		return bonus_score.score.bonus;
	} else {
		return 0;
	}
}

/*Function to calculate the total score
it takes the total_score of the scoreboard struct as an argument*/
int calculate_total_score(scoreboard bottom_column)
{
	int bottom_sum = bottom_column.score.first_total + bottom_column.score.bonus;

	for (int i = 8; i <= 18; i++)
	{
		int field_value = *((int*)&bottom_column.score + i);
		bottom_sum += field_value;
	}
	bottom_column.score.total_score = bottom_sum;
	return bottom_sum;
}
