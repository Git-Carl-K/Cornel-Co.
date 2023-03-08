#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Cornel.h"
#include "Louise.h"
#include "Hanna.h"
#include "Carl.h"

int roll_dice()
{
	int dice = rand() % 6 + 1;
	return dice;
}

//Roll pool of dice with x number of dice in dice array
void roll_pool(int number_of_dice, int dice_pool[])
{
	printf("Rolling pool\n");
	for (int i = 0; i < number_of_dice; i++)
	{
		dice_pool[i] = roll_dice();
		printf("%d ", dice_pool[i]);
	}
	qsort(dice_pool, 5, sizeof(int), compare_small);
	printf("\n Sorted: \n");
	for (int i = 0; i < number_of_dice; i++)
	{
		printf("%d ", dice_pool[i]);
	}
	printf("\n");
}


// Saves the value that you want from said dice_pool. INCOMPLETE
int save_value(int dice_pool[])
{
	int merged_array[5];


	printf("Which dice would you like to save, separate dices with space,"
			" 0 to discard\n");
	fflush(stdout);
	scanf("%d %d %d %d %d", &merged_array[0], &merged_array[1],&merged_array[2],
				&merged_array[3], &merged_array[4]);
	printf("Saved dice: \n");
	for (int i = 0; i < 5; i++)
	{
		if (merged_array[i] == dice_pool[i])
		{
			printf("dice %d: %d ", i + 1, merged_array[i]);
		}
	}

	printf("\n");

	return (0);
}

// Asks user to roll again
int roll_again()
{
	int dice_pool[5];
	printf("Do you wish to roll again? y/n \n");
	fflush(stdout);
	char choice;
	scanf("%c", &choice);
	if (choice == 'y')
	{
		roll_pool(5, dice_pool);
	}
	return (0);
}




// Prints score board for Yatzy
void score_board()
{
	printf("\n\n");
	//	printf ("             ROLL:0             CATEGORY            PLAYER 1   PLAYER 2\n\n");
	printf ("[   ] ONES                [      ]   [      ]\n");
	printf ("[   ] TWOS                [      ]   [      ]\n");
	printf ("[   ] THREES              [      ]   [      ]\n");
	printf ("[   ] FOURS               [      ]   [      ]\n");
	printf ("[   ] FIVES               [      ]   [      ]\n");
	printf ("[   ] SIXES               [      ]   [      ]\n");
	printf ("[   ] TOTAL               [      ]   [      ]\n");
	printf ("[   ] BONUS               [      ]   [      ]\n\n");
	printf ("[   ] THREE OF A KIND     [      ]   [      ]\n");
	printf ("[   ] FOUR OF A KIND      [      ]   [      ]\n");
	printf ("[   ] FULL HOUSE          [      ]   [      ]\n");
	printf ("[   ] SMALL STRAIGHT      [      ]   [      ]\n");
	printf ("[   ] LARGE STRAIGHT      [      ]   [      ]\n");
	printf ("[   ] CHANCE              [      ]   [      ]\n");
	printf ("[   ] YATZY               [      ]   [      ]\n");
	printf ("[   ] TOTAL               [      ]   [      ]\n");
}




