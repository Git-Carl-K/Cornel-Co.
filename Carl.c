#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Cornel.h"
#include "Louise.h"
#include "Hanna.h"
#include "Carl.h"
#include <string.h>


#define size 5
int roll_dice()
{
	int dice = rand() % 6 + 1;
	return dice;
}

//Roll pool of dice with x number of dice in dice array
void roll_pool(int dice_pool[])
{
	printf("Rolling pool\n");
	fflush(stdout);
	for (int i = 0; i < 5; i++)
	{
		if(dice_pool[i] == 0)
		{
			dice_pool[i] = roll_dice();
			printf("%d ", dice_pool[i]);
			fflush(stdout);
		}
	}
	qsort(dice_pool, 5, sizeof(int), compare_small);
	printf("\n Sorted: \n");
	fflush(stdout);
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", dice_pool[i]);
		fflush(stdout);
	}
	printf("\n");
	fflush(stdout);
}


// Saves the value that you want from said dice_pool. INCOMPLETE
void save_value(int dice_pool[])
{
	static int merged_array[5];
	int i = 0;

	printf("Which dice would you like to save, separate dices with space,"
			" 0 to discard\n");
	fflush(stdout);
	scanf("%d %d %d %d %d", &merged_array[0], &merged_array[1],&merged_array[2],
			&merged_array[3], &merged_array[4]);
	printf("Saved dice: \n");
	fflush(stdout);
	for (i = 0; i < 5; i++)
	{
		if (merged_array[i] == dice_pool[i])
		{
			printf("dice %d: %d ", i + 1, merged_array[i]);
			fflush(stdout);
		}
	}
	int dice_left_to_throw = 0;

	printf("\n");
	fflush(stdout);
	for (int j = 0; j < 5; j++)
	{
		if (merged_array[j] == 0)
		{
			dice_left_to_throw++;
		}
	}

	printf("Dice left to throw: %d\n", dice_left_to_throw);
	fflush(stdout);
	printf("Do you wish to roll again? y/n \n");
	fflush(stdout);
	char choice[3];
	scanf("%s", choice);

	if (strcmp(choice, "y") == 0)
	{
		roll_pool(merged_array);
	}
}

// Asks user to roll again
//int roll_again()
//{
//
//	int dice_pool[5];
//	printf("Do you wish to roll again? y/n \n");
//	fflush(stdout);
//	char choice;
//	scanf("%c", &choice);
//	if (choice == 'y')
//	{
//		roll_pool(5, dice_pool);
//	}
//	return (0);
//}




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




