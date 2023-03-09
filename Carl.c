#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Cornel.h"
#include "Louise.h"
#include "Hanna.h"
#include "Carl.h"
#include <string.h>

int rounds = 0;
#define size 5
int roll_dice()
{
	int dice = rand() % 6 + 1;
	return dice;
}

//Roll pool of dice initialized to 0 within dice array
int roll_pool(int dice_pool[])
{
	static int merged_array[5];
	jump:
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
		else if(merged_array[i] == 0)
		{
			merged_array[i] = roll_dice();
			printf("%d " , merged_array[i]);
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
			printf("%d ", merged_array[i]);
			fflush(stdout);
		}

	}
	int throws_left = 0;

	printf("\n");
	fflush(stdout);
	for (int j = 0; j < 5; j++)
	{
		if (merged_array[j] == 0)
		{
			throws_left++;
		}
	}
	rounds++;
	printf("Dice left to throw: %d\n", throws_left);
	fflush(stdout);
	printf("Do you wish to roll again? y/n \n");
	fflush(stdout);
	char choice[3];
	scanf("%s", choice);
	if (rounds != 2)
	{

		if (strcmp(choice, "y") == 0)
		{
			goto jump;
		}
	}
	if (strcmp(choice, "n") == 0)
	{
		printf("You have rolled: %d %d %d %d %d\n", merged_array[0],
				merged_array[1], merged_array[2],
				merged_array[3], merged_array[4]);


	}
	if (rounds == 3)
	{
	printf("You have reached maximum amount of turns\n");
	}
	return(0);
}

// Plocka ut roll again funktionen för att inte hamna i en loooooooop

// Saves the value that you want from said dice_pool. INCOMPLETE
//void save_value(int dice_pool[])
//{
//	static int merged_array[5];
//	int i = 0;
//
//	printf("Which dice would you like to save, separate dices with space,"
//			" 0 to discard\n");
//	fflush(stdout);
//	scanf("%d %d %d %d %d", &merged_array[0], &merged_array[1],&merged_array[2],
//			&merged_array[3], &merged_array[4]);
//	printf("Saved dice: \n");
//	fflush(stdout);
//	for (i = 0; i < 5; i++)
//	{
//		if (merged_array[i] == dice_pool[i])
//		{
//			printf("%d ", merged_array[i]);
//			fflush(stdout);
//		}
//	}
//	int dice_left_to_throw = 0;
//
//	printf("\n");
//	fflush(stdout);
//	for (int j = 0; j < 5; j++)
//	{
//		if (merged_array[j] == 0)
//		{
//			dice_left_to_throw++;
//		}
//	}
//
//	printf("Dice left to throw: %d\n", dice_left_to_throw);
//	fflush(stdout);
//	printf("Do you wish to roll again? y/n \n");
//	fflush(stdout);
//	char choice[3];
//	scanf("%s", choice);
//
//	if (strcmp(choice, "y") == 0)
//	{
//		roll_pool(merged_array);
//	}
//	if (strcmp(choice, "n") == 0)
//	{
//		printf("You have rolled: %d %d %d %d %d", merged_array[0],
//				merged_array[1], merged_array[2],
//				merged_array[3], merged_array[4]);
//	}
//
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




