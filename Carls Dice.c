/*
 ============================================================================
 Name        : Carls.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



//compare function for quick sort
int compare_int(const void * a, const void * b)
{
	if ( *(int*)a <  *(int*)b ) return -1;
	if ( *(int*)a == *(int*)b ) return 0;
	return 1;
}

int roll_dice()
{
	int dice = rand() % 6 + 1;
	return dice;
}

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
//sort function
//*parameters:
//(1) array of int's to sort
//(2) the size of the array
//(3) char 'r' to sort reversed - any other char to sort small to big
void sort(int arr[], int arr_size, char c)
{
	qsort (arr, arr_size, sizeof(int), compare_int);
	if (c == 'r') {
		for(int i = 0; i<arr_size/2; i++){
			int temp = arr[i];
			arr[i] = arr[arr_size-i-1];
			arr[arr_size-i-1] = temp;
		}
	}
}

void save_value_second_time(int value_to_save, int dice_pool[])
{
	{
		int merged_array[5];

		printf("Saved dice 2: \n");
		for (int i = 0; i < 5; i++)
		{
			if (value_to_save == dice_pool[i])
			{
				merged_array[i] = value_to_save;
				printf("%d ", merged_array[i]);

			}
			else
				merged_array[i]++;
		}

	}
}


int main()
{
	srand(time(NULL));
	int dice_pool[5];
	roll_pool(5, dice_pool);
	printf("\n");
	save_value(5, dice_pool);
	printf("\n");


}
