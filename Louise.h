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
	scoreboard_column score;

}scoreboard;

/*Function that calculates the sum of dicepool*/
int sum_pool(int *dice_pool, int size);

/*Function to print game menu*/
void print_game_menu();

/*Function to calculate first total*/
int calculate_first_total(scoreboard top_column);

/*Function to calculate the bonus*/
int calculate_bonus(scoreboard bonus_score);

/*Function to calculate the total score*/
int calculate_total_score(scoreboard bottom_column);

/*Function to quit game*/
void quit_game();
