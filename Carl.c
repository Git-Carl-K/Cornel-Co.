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
	qsort(dice_pool, 5, sizeof(int), compare_int);
	printf("\n Sorted: \n");
	for (int i = 0; i < number_of_dice; i++)
	{
		printf("%d ", dice_pool[i]);
	}

}

// Saves the value that you want from said dice_pool. INCOMPLETE
void save_value(int value_to_save, int dice_pool[])
{
	int merged_array[5];

	printf("Saved dice: \n");
	for (int i = 0; i < 5; i++)
	{
		if (value_to_save == dice_pool[i])
		{
			merged_array[i] = value_to_save;
			printf("%d ", merged_array[i]);

		}

	}
}

//compare function for quick sort
int compare_int(const void * a, const void * b)
{
	if ( *(int*)a <  *(int*)b ) return -1;
	if ( *(int*)a == *(int*)b ) return 0;
	return 1;
}
