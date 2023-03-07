#include <stdio.h>
#include <stdlib.h>

///*Structure of a yatzee-scoreboard*/
typedef struct scoreboard_column {
	int ones;
	int twos;
	int threes;
	int fours;
	int fives;
	int six;
	int first_total;
	int bonus;
	int pair;
	int two_pairs;
	int three_of_a_kind;
	int four_of_a_kind;
	int five_of_a_kind;
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

int main(){
	print_game_menu();

	return 0;
}
