#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "yatzy.h"

top_ten players[10];
top_ten fromfile[10];

void play_yatsy() {
	load_highscore(players);
	GameState current_game;
	GameState *p_gamestate = &current_game;
	p_gamestate->num_of_players = 0;
	p_gamestate->turn = 0;
	for (int i = 0; i < size; i++) {
		p_gamestate->current_dicepool[i] = 0;
	}

	while (1) {
		int player_choice1 = game_menu();
		int player_choice2 = 0;

		switch (player_choice1) {
		case 1:
			player_choice2 = single_player_menu();
			break;
		case 2:
			player_choice2 = multi_player_menu();
			break;
		case 3:
			print_top_ten(players);
			play_yatsy();
			break;
		case 4:
			quit_game(p_gamestate);
			break;
		default:
			break;
		}

		// switch depending on player choice
		switch (player_choice2) {
		case 1:
			new_game(player_choice1, p_gamestate);
			break;
		case 2:
			load_game(player_choice1);
			break;
		case 3:
			break;
		case 4:
			quit_game(p_gamestate);
			break;
		default:
			break;
		}

		if (player_choice2 != 3) {
			return;
		}
	}
}

int game_menu() {
	int choice;
	printf("-------------------------------");
	printf("\n      Welcome to Yahtzee!    \n");
	printf("-------------------------------");
	printf("\n          GAME MENU          \n");
	printf("\n1. Single player\n");
	printf("\n2. Multiplayer\n");
	printf("\n3. View highscores\n");
	printf("\n4. Quit game\n");
	printf("-------------------------------");
	printf("\nChoose an option (1-4)\n");
	fflush(stdout);
	scanf("%d", &choice);
	return choice;
}

int single_player_menu() {
	int single_choice;
	printf("-------------------------------");
	printf("\n   Single Player Menu      \n");
	printf("-------------------------------");
	printf("\n1. New game                \n");
	printf("\n2. Load game *COMING SOON* \n");
	printf("\n3. Go back                 \n");
	printf("\n4. Quit game               \n");
	printf("\nChoose an option (1-4)       ");
	fflush(stdout);
	scanf("%d", &single_choice);
	return single_choice;
}

int multi_player_menu() {
	int multi_choice;
	printf("-------------------------------");
	printf("\n      Multiplayer Menu     \n");
	printf("-------------------------------");
	printf("\n1. New game                \n");
	printf("\n2. Load game *COMING SOON* \n");
	printf("\n3. Go back                 \n");
	printf("\n4. Quit game               \n");
	printf("\nChoose an option (1-4)       ");
	fflush(stdout);
	scanf("%d", &multi_choice);
	return multi_choice;
}

void quit_game(GameState *current_game) {
	printf("-----------------------------\n");
	printf("        Quitting game        \n");
	printf("-----------------------------\n");
	fflush(stdout);
	if (current_game->num_of_players == 0)
	{
		printf("-----------------------------\n");
		printf("          Good bye!          \n");
		printf("-----------------------------\n");
		fflush(stdout);
	}
	if (current_game->num_of_players != 0)
	{
		char choice = 'n';
		printf("-----------------------------\n");
		printf("Would you like to save? (y/n)\n");
		printf("-----------------------------\n");
		fflush(stdout);
		scanf("%c", &choice);
		if (choice == 'y')
		{
			//call save game function
			save_game();
			printf("-----------------------------\n");
			printf("Game has been saved!         \n");
			printf("Good bye, thanks for playing!\n");
			printf("-----------------------------\n");
		}
		else
		{
			printf("-----------------------------\n");
			printf("Good bye, thanks for playing!\n");
			printf("-----------------------------\n");
		}
		printf("\n\n");
	}

	free(current_game->players);
}

void create_scoreboard(GameState *current_game) {
	char player_name[20];
	printf("\nEnter player name: \n");
	fflush(stdout);
	scanf("%s", player_name);
	strcpy(current_game->players[current_game->num_of_players - 1].name, player_name);
	preset_scoreboard(current_game);
}

void add_player(GameState *current_game) {
	int player_choice = 1;
	current_game->num_of_players = 1;
	while (player_choice == 1) {
		current_game->players = realloc(current_game->players, sizeof(Scoreboard) * current_game->num_of_players);
		create_scoreboard(current_game);
		printf("\n1. Add player                \n");
		printf("\n2. Start game                \n");
		printf("\nChoose an option (1-2)         ");
		fflush(stdout);
		int player_choice;
		scanf("%d", &player_choice);
		if (player_choice == 1) {
			current_game->num_of_players++;
			continue;
		} else if (player_choice == 2) {
			start_game(current_game);
		}
	}
}

void new_game(int single_or_multi, GameState *current_game) {
	current_game->turn = 1;
	current_game->players = malloc(sizeof(Scoreboard));
	if (single_or_multi == 1) {
		current_game->num_of_players = 1;
		create_scoreboard(current_game);
		start_game(current_game);
	} else if (single_or_multi == 2) {
		add_player(current_game);
	}
}

void load_game(int single_or_multi) {
	printf("\nWARNING: Cannot load games yet\n");
	play_yatsy();
}

void save_game(int single_or_multi) {
	//oklart
}

//compare function for quick sort (small to large)
int compare_small(const void * a, const void * b)
{
	if ( *(int*)a <  *(int*)b ) return -1;
	if ( *(int*)a == *(int*)b ) return 0;
	return 1;
}

//compare function for quick sort (large to small)
int compare_big(const void * a, const void * b)
{
	if ( *(int*)a >  *(int*)b ) return -1;
	if ( *(int*)a == *(int*)b ) return 0;
	return 1;
}

//prints out the dice pool
//*parameters:
//(1) dice_pool of int's
//(2) size of dice_pool
void print_pool(int dice_pool[])
{
	for (int i = 0; i < size; i++) {
		printf ("%d ", dice_pool[i]);
	}
	printf("\n");
}

//checks how many dice with the same dice-face
//*parameters:
//(1) dice_pool of int's
//(2) size of dice_pool
//(3) the dice-face to check for
//returns the points collected
int find(int dice_pool[], int dice_face) {
	int found = 0;
	int points = 0;
	for (int i = 0; i < size; i++) {
		if (dice_pool[i] == dice_face) {
			found++;
		}
	}
	if (found != 0) {
		points = found * dice_face;
		return points;
	} else {
		return 0;
	}
}

//checks for a collection of 3, 4 or 5 dice with the same dice-face
//*parameters:
//(1) dice_pool of int's
//(2) size of dice_pool
//(3) the number of same int's to check for (3, 4 or 5)
//returns the points collected
int x_of_a_kind(int dice_pool[], int x_of_a_kind) {
	qsort(dice_pool, size, sizeof(int), compare_big);
	int points = 0;
	if (x_of_a_kind != 5) {
		for (int i = 0; i < size; i++) {
			if ((find(dice_pool, dice_pool[i]) / dice_pool[i]) == x_of_a_kind) {
				points += (dice_pool[i] * x_of_a_kind);
				return points;
			}
		}
	} else {
		if ((find(dice_pool, dice_pool[0]) / dice_pool[0]) == x_of_a_kind) {
			points = 50;
			return points;
		}
	}
	return 0;
}

//checks for a small straight
//*parameters:
//(1) dice_pool of int's
//(2) size of dice_pool
//returns the points collected
int check_small_straigt(int dice_pool[]) {
	qsort(dice_pool, size, sizeof(int), compare_small);
	int points = 15;
	if (dice_pool[0] == 1) {
		for (int i = 0; i < (size-1); i++) {
			if (dice_pool[i] == dice_pool[i+1] - 1) {
				continue;
			} else {
				return 0;
			}
		}
	} else {
		return 0;
	}
	return points;
}

//checks for a large straight
//*parameters:
//(1) dice_pool of int's
//(2) size of dice_pool
//returns the points collected
int check_large_straigt(int dice_pool[]) {
	qsort(dice_pool, size, sizeof(int), compare_big);
	int points = 20;
	if (dice_pool[0] == 6) {
		for (int i = 0; i < (size-1); i++) {
			if (dice_pool[i] == dice_pool[i+1] + 1) {
				continue;
			} else {
				return 0;
			}
		}
	} else {
		return 0;
	}
	return points;
}

//checks for pairs
//*parameters:
//(1) dice_pool of int's
//(2) size of dice_pool
//(3) the number of pairs to check for (1 or 2)
//returns the points collected
int check_pairs(int dice_pool[], int pair) {
	qsort(dice_pool, size, sizeof(int), compare_big);
	int pairs = 0;
	int points = 0;
	for (int i = 0; i < size;) {
		if ((find(dice_pool, dice_pool[i]) / dice_pool[i]) > 3) {
			return 0;
		}
		if ((find(dice_pool, dice_pool[i]) / dice_pool[i]) < 2) {
			i++;
			continue;
		} else {
			pairs++;
			points += (dice_pool[i] * 2);
			if (pairs == pair) {
				return points;
			} else {
				i += (find(dice_pool, dice_pool[i]) / dice_pool[i]);
				continue;
			}
		}
		i++;
	}
	return 0;
}

//checks for full house
//*parameters:
//(1) dice_pool of int's
//(2) size of dice_pool
//returns the points collected
int check_full_house(int dice_pool[]) {
	qsort(dice_pool, size, sizeof(int), compare_big);
	int points = 0;
	if ((find(dice_pool, dice_pool[0]) / dice_pool[0]) == 3) {
		if ((find(dice_pool, dice_pool[4]) / dice_pool[4]) == 2) {
			points += (dice_pool[0] * 3);
			points += (dice_pool[4] * 2);
			return points;
		}
	}
	if ((find(dice_pool, dice_pool[0]) / dice_pool[0]) == 2) {
		if ((find(dice_pool, dice_pool[4]) / dice_pool[4]) == 3) {
			points += (dice_pool[0] * 2);
			points += (dice_pool[4] * 3);
			return points;
		}
	}
	return 0;
}

/*Function that calculates the sum of dicepool*/
int sum_pool(int *dice_pool) {
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += dice_pool[i];
	}
	return sum;
}

/*Function to calculate the first total
it takes the top_column of the scoreboard struct as an argument*/
int calculate_first_total(Scoreboard top_column){
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
int calculate_bonus(Scoreboard bonus_score){
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
int calculate_total_score(Scoreboard bottom_column)
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

//fills a scoreboard with points
//*parameters:
//(1) GameState struct for the player
//returns the points collected
void fill_scoreboard(GameState *current_game) {
	switch (current_game->turn) {
	case 1:
		current_game->players->score.ones = find(current_game->current_dicepool, 1);
		break;
	case 2:
		current_game->players->score.twos = find(current_game->current_dicepool, 2);
		break;
	case 3:
		current_game->players->score.threes = find(current_game->current_dicepool, 3);
		break;
	case 4:
		current_game->players->score.fours = find(current_game->current_dicepool, 4);
		break;
	case 5:
		current_game->players->score.fives = find(current_game->current_dicepool, 5);
		break;
	case 6:
		current_game->players->score.sixes = find(current_game->current_dicepool, 6);
		break;
	case 7:
		current_game->players->score.first_total = calculate_first_total(*current_game->players);
		break;
	case 8:
		current_game->players->score.bonus = calculate_bonus(*current_game->players);
		break;
	case 9:
		current_game->players->score.pair = check_pairs(current_game->current_dicepool, 1);
		break;
	case 10:
		current_game->players->score.two_pairs = check_pairs(current_game->current_dicepool, 2);
		break;
	case 11:
		current_game->players->score.three_of_a_kind = x_of_a_kind(current_game->current_dicepool, 3);
		break;
	case 12:
		current_game->players->score.four_of_a_kind = x_of_a_kind(current_game->current_dicepool, 4);
		break;
	case 13:
		current_game->players->score.small_straight = check_small_straigt(current_game->current_dicepool);
		break;
	case 14:
		current_game->players->score.large_straight = check_large_straigt(current_game->current_dicepool);
		break;
	case 15:
		current_game->players->score.full_house = check_full_house(current_game->current_dicepool);
		break;
	case 16:
		current_game->players->score.chance = sum_pool(current_game->current_dicepool);
		break;
	case 17:
		current_game->players->score.yatzy = x_of_a_kind(current_game->current_dicepool, 5);
		break;
	case 18:
		current_game->players->score.total_score = calculate_total_score(*current_game->players);
		break;
	default:
		break;
	}
}

int roll_dice()
{
	int dice = rand() % 6 + 1;
	return dice;
}

//Roll pool of dice initialized to 0 within dice array
int roll_pool(GameState *current_game)
{
	static int merged_array[5];
	printf("Rolling pool\n");
	fflush(stdout);

	int rounds = 1;
	for (int i = 0; i < 5; i++)
	{
		if(current_game->current_dicepool[i] == 0)
		{
			current_game->current_dicepool[i] = roll_dice();
		}
		merged_array[i] = 0; // initialize merged_array to 0
		if (rounds <= 1) {
			printf("%d ", current_game->current_dicepool[i]);
			fflush(stdout);
		}
	}
	printf("\n");
	fflush(stdout);
	int throws_left = 3; // set throws_left to 3
	while (rounds <= 3 && throws_left > 0)
	{
		printf("\nWhich dice would you like to save, separate dices with space,"
				" 0 to discard\n");
		fflush(stdout);
		scanf("%d %d %d %d %d", &merged_array[0], &merged_array[1],&merged_array[2],
				&merged_array[3], &merged_array[4]);
		//		for (int i = 0; i < 5; i++)
		//		{
		//			if (merged_array[i] == current_game->current_dicepool[i])
		//			{
		//				printf("%d ", merged_array[i]);
		//				fflush(stdout);
		//			}
		//			else
		//			{
		//				merged_array[i] = 0; // discard any dice not saved
		//			}
		//		}
		throws_left--;
		printf("\n");
		//		printf("Rolling dice:\n");
		fflush(stdout);
		for (int j = 0; j < 5; j++)
		{
			if (merged_array[0] != 0 && merged_array[1] != 0 &&
					merged_array[2] != 0 && merged_array[3] != 0 &&
					merged_array[4] != 0) {
				goto jump;
			}
			if (merged_array[j] == 0)
			{
				merged_array[j] = roll_dice(); // roll any dice not saved
			}
			current_game->current_dicepool[j] = merged_array[j]; // copy rolled dice to dice_pool
		}

		for (int j = 0; j < 5; j++) {
			printf("%d ", merged_array[j]);
			fflush(stdout);
		}

		printf("\n");
		fflush(stdout);
		//		qsort(current_game->current_dicepool, 5, sizeof(int), compare_small);
		//		printf("Sorted: \n");
		//		for (int i = 0; i < 5; i++)
		//		{
		//			printf("%d ", current_game->current_dicepool[i]);
		//			fflush(stdout);
		//		}
		printf("\n");
		fflush(stdout);
		if (rounds == 3)
		{
			printf("You have reached maximum amount of turns\n");
		}
		else if (throws_left == 0)
		{
			printf("You have used up all your throws\n");
		}
		//		else
		//		{
		//			printf("Do you wish to roll again? y/n \n");
		//			fflush(stdout);
		//			char choice[3];
		//			scanf("%s", choice);
		//			if (strcmp(choice, "n") == 0)
		//			{
		//				break;
		//			}
		//		}
		rounds++;
	}
	jump:
	printf("Final dice pool: %d %d %d %d %d\n", current_game->current_dicepool[0],
			current_game->current_dicepool[1], current_game->current_dicepool[2],
			current_game->current_dicepool[3], current_game->current_dicepool[4]);
	return(0);
}

void print_scoreboard(GameState *current_game) {
	printf("\n");
	printf("Ones:        %d\n", current_game->players->score.ones);
	printf("Twos:        %d\n", current_game->players->score.twos);
	printf("Threes:      %d\n", current_game->players->score.threes);
	printf("Fours:       %d\n", current_game->players->score.fours);
	printf("Fives:       %d\n", current_game->players->score.fives);
	printf("Sixes:       %d\n", current_game->players->score.sixes);
	printf("First total: %d\n", current_game->players->score.first_total);
	printf("Bonus:       %d\n", current_game->players->score.bonus);
	printf("Pair:        %d\n", current_game->players->score.pair);
	printf("Two pairs:   %d\n", current_game->players->score.two_pairs);
	printf("3 of a kind: %d\n", current_game->players->score.three_of_a_kind);
	printf("4 of a kind: %d\n", current_game->players->score.four_of_a_kind);
	printf("Small:       %d\n", current_game->players->score.small_straight);
	printf("Large:       %d\n", current_game->players->score.large_straight);
	printf("Full house:  %d\n", current_game->players->score.full_house);
	printf("Chance:      %d\n", current_game->players->score.chance);
	printf("Yatzy:       %d\n", current_game->players->score.yatzy);
	printf("Total score: %d\n", current_game->players->score.total_score);
	fflush(stdout);
}

void preset_scoreboard(GameState *current_game) {
	current_game->players->score.ones = 0;
	current_game->players->score.twos = 0;
	current_game->players->score.threes = 0;
	current_game->players->score.fours = 0;
	current_game->players->score.fives = 0;
	current_game->players->score.sixes = 0;
	current_game->players->score.first_total = 0;
	current_game->players->score.bonus = 0;
	current_game->players->score.pair = 0;
	current_game->players->score.two_pairs = 0;
	current_game->players->score.three_of_a_kind = 0;
	current_game->players->score.four_of_a_kind = 0;
	current_game->players->score.small_straight = 0;
	current_game->players->score.large_straight = 0;
	current_game->players->score.full_house = 0;
	current_game->players->score.chance = 0;
	current_game->players->score.yatzy = 0;
	current_game->players->score.total_score = 0;
}

void start_game(GameState *current_game){
	printf("Game starting...");
	int choice;
	while (current_game->turn < 19) {
		if (current_game->turn == 7 || current_game->turn == 8 || current_game->turn == 18) {
			fill_scoreboard(current_game);
			print_scoreboard(current_game);
			current_game->turn++;
			continue;
		}
		printf("\n1. Throw dice              \n");
		printf("\n2. Quit game               \n");
		printf("\nChoose an option (1-2)       ");
		fflush(stdout);
		scanf("%d", &choice);
		if (choice == 1) {
			for (int i = 0; i < current_game->num_of_players; i++) {
				roll_pool(current_game);
				fill_scoreboard(current_game);
				print_scoreboard(current_game);
			}
		} else if(choice == 2) {
			quit_game(current_game);
		}
		current_game->turn++;
	}

	add_to_highscore(players, *current_game->players);
	save_top_ten("highscore.txt", players);
	read_top_ten ("highscore.txt",  fromfile);

	int cont;
	printf("\n1. Play again              \n");
	printf("\n2. View highscores\n");
	printf("\n3. Quit game               \n");
	printf("\nChoose an option (1-3)       ");
	fflush(stdout);
	scanf("%d", &cont);
	if (cont == 1) {
		play_yatsy();
	} else if (cont == 2) {
		print_top_ten(players);
	} else if (cont == 3) {
		quit_game(current_game);
	}
}

int compare_top_ten (const void *a, const void *b)
{
	top_ten *temp_a, *temp_b;
	temp_a= (top_ten*)a;
	temp_b= (top_ten*)b;

	//if a is bigger than b, move a to the left <-- (up towards index [0]
	if (temp_a->points > temp_b->points)
	{
		return-1;
	}

	//If a is equal to b -- > do nothing
	if (temp_a->points == temp_b->points)
	{
		return 0;
	}


	//if a is smaller than b, move a to the right
	if (temp_a->points < temp_b->points)
	{
		return 1;
	}
	return 0;
}

void load_highscore(top_ten *players)
{
	strcpy(players[0].name, "Robert");
	strcpy(players[1].name, "Anna");
	strcpy(players[2].name, "Markus");
	strcpy(players[3].name, "Johan");
	strcpy(players[4].name, "Hanna");
	strcpy(players[5].name, "Cornel");
	strcpy(players[6].name, "Carl");
	strcpy(players[7].name, "Loise");
	strcpy(players[8].name, "Roger");
	strcpy(players[9].name, "Johan");
	players[0].points = 200;
	players[1].points = 180;
	players[2].points = 160;
	players[3].points = 140;
	players[4].points = 220;
	players[5].points = 100;
	players[6].points = 80;
	players[7].points = 60;
	players[8].points = 40;
	players[9].points = 20;
}

void add_to_highscore(top_ten *players, Scoreboard to_add)
{
	// find which place to put the new score by comparing with placements in the highscore
	// We start with last place and work our way up the highscore
	//We want to use pos later, so we declare it outside of the loop
	int pos;

	for (pos = 9; pos > 0; pos--)
	{
		// If the new player has less points than this placement on the highscore, we stop
		if (players[pos].points > to_add.score.total_score)
		{
			pos++; //go back down one step on the highscore
			break;
		}
	}

	//Pos now contains the index where we want to insert the new score
	//But before we do, we need to move all the other values to make room

	// We start by moving the score in 9th place to 10th place and work our way up
	for (int i = 8; i >= pos; i--)
	{
		// For instance the 8th position moves to 9th position and so on
		players[i+1] = players[i];
	}

	// Once all the players are moved, we write the new player to our highscore
	// His name and score can be found in the scoreboard

	strcpy(players[pos].name, to_add.name);
	players[pos].points = to_add.score.total_score;

	//Since players is a pointer we don't need to return anything. Changes happens directly
	//to the array we sent into this function.
}

bool save_top_ten (char *filename,  top_ten players[])
{
	FILE *pFile;

	// fopen returns a pointer to our file.




	//char filename = choose a name for the file
	// the location on your computer for simplicity
	// 	 EX: "C:\\Users\\Rohdi\\eclipse-workspace\\yatzee, w+)*/

	pFile = fopen ("highscore.txt", "w+");
	if (pFile == NULL)
		perror ("error opening a file");

	else
	{

		//Before writing to file, we sort the scores high to low.

		qsort (players,10, sizeof(top_ten), compare_top_ten);
		for (int i = 1; i < 11; i++)
		{

			//to make it easy to re-read the file again, don´t forget the comma,
			//  after the first format specifier and continue to the last line.
			//	 EX: 	fprintf(pFile, "%s,", players[i-1].name) ;
			//	 	 	and so on..


			fprintf(pFile, "%s,", players[i-1].name) ;
			fprintf(pFile," %d\n", players[i-1].points);
		}

	}


	fclose (pFile);

	return false;
}

bool read_top_ten (char *filename,  top_ten fromfile[])
{

	char buffer [100];

	int count = 0;


	FILE *pFile;

	// fopen returns a pointer to our file.
	// It can either read or write or both. We are going to read "r"

	pFile = fopen ("highscore.txt", "r");
	if (pFile == NULL)
		perror ("error opening a file");


	else
	{

		//Lets read the file until EOF the and store it in buffer.

		while (!feof(pFile))
		{
			if (fgets(buffer, 100, pFile) == NULL)
				break;


			// in main, we created a top_ten fromfile [] array.
			// Store the data in the variables in the array.
			// We store each to first comma , in the line.
			// continue to next comma etc..
			// OBS! Since we are reading from a textfile and we have integers
			// dont forget atoi!

			char *my_string;
			my_string = strtok(buffer, ",");
			strcpy(fromfile[count].name, my_string);

			my_string = strtok(NULL, ",");
			fromfile[count].points = atoi(my_string);
			count++;

		}
	}

	fclose (pFile);

	// after we read the data into our fromfile struct array
	// we print out the top_ten scores from high to low

	qsort (fromfile,10, sizeof(top_ten), compare_top_ten);
	for (int i = 1; i < 11; i++)
	{
		printf("[%d]\t%s\t",i, fromfile[i-1].name);
		printf(" %dp\n", fromfile[i-1].points);
	}



	return false;
}

void print_top_ten(top_ten players[])
{



	printf("---------------------\n");
	printf("   >>> TOP TEN <<< \n");
	printf("---------------------\n");

	qsort (players,10, sizeof(top_ten), compare_top_ten);
	for (int i = 1; i < 11; i++)
	{
		printf("[%d]\t%s\t",i, players[i-1].name);
		printf(" %dp\n", players[i-1].points);
	}

}
