#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Carl.h"
#include "Cornel.h"
#include "Louise.h"
#include "Hanna.h"

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
void print_pool(int dice_pool[], int size)
{
	for (int i = 0; i < size; i++)
		printf ("%d ", dice_pool[i]);
}

//checks for a collection of the same dice-face
//*parameters:
//(1) dice_pool of int's
//(2) size of dice_pool
//(3) the number to check for
//returns the points collected
int find_num_in_pool(int dice_pool[], int size, int num) {
	int found = 0;
	for (int i = 0; i < size; i++) {
		if (dice_pool[i] == num) {
			found++;
		}
	}
	if (found != 0) {
		return found * num;
	} else {
		return 0;
	}
}

//checks for a collection of 3, 4 or 5 of the same number
//*parameters:
//(1) dice_poolay of int's to check
//(2) the size of the dice_poolay
//(3) the number of same int's to check for
//returns the points collected
int x_of_a_kind(int dice_pool[], int size, int num) {
	qsort(dice_pool, size, sizeof(int), compare_big);
	int points = 0;
	if (num != 5) {
		for (int i = 0; i < size; i++) {
			if ((find_num_in_pool(dice_pool, size, dice_pool[i]) / dice_pool[i]) == num) {
				points += (dice_pool[i] * num);
				return points;
			}
		}
	} else {
		if ((find_num_in_pool(dice_pool, size, dice_pool[i]) / dice_pool[i]) == num) {
			points = 50;
			return points;
		}
	}
	return 0;
}

//checks for a small straight
//*parameters:
//(1) dice_poolay of int's to check
//(2) the size of the dice_poolay
//returns the points collected
int check_small_straigt(int dice_pool[], int size) {
	qsort(dice_pool, size, sizeof(int), compare_small);
	int points = 0;
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
	for (int i = 0; i < size; i++) {
		points += dice_pool[i];
	}
	return points;
}

//checks for a large straight
//*parameters:
//(1) dice_poolay of int's to check
//(2) the size of the dice_poolay
//returns the points collected
int check_large_straigt(int dice_pool[], int size) {
	qsort(dice_pool, size, sizeof(int), compare_big);
	int points = 0;
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
	for (int i = 0; i < size; i++) {
		points += dice_pool[i];
	}
	return points;
}

//checks for pairs
//*parameters:
//(1) dice_poolay of int's to check
//(2) the size of the dice_poolay
//(3) the number of pairs to check for
//returns the points collected
int check_pairs(int dice_pool[], int size, int num) {
	qsort(dice_pool, size, sizeof(int), compare_big);
	int pairs = 0;
	int points = 0;
	for (int i = 0; i < size; ) {
		if ((find_num_in_pool(dice_pool, size, dice_pool[i]) / dice_pool[i]) >= 2) {
			pairs++;
			points += (dice_pool[i] * 2);
			if (pairs == num) {
				return points;
			} else {
				i += (find_num_in_pool(dice_pool, size, dice_pool[i]) / dice_pool[i]);
				continue;
			}
		}
		i++;
	}
	return 0;
}

//checks for full house
//*parameters:
//(1) dice_poolay of int's to check
//(2) the size of the dice_poolay
//returns the points collected
int check_full_house(int dice_pool[], int size) {
	qsort(dice_pool, size, sizeof(int), compare_big);
	int points = 0;
	if ((find_num_in_pool(dice_pool, size, dice_pool[0]) / dice_pool[0]) == 3) {
		if ((find_num_in_pool(dice_pool, size, dice_pool[4]) / dice_pool[4]) == 2) {
			points += (dice_pool[0] * 3);
			points += (dice_pool[4] * 2);
			return points;
		}
	}
	if ((find_num_in_pool(dice_pool, size, dice_pool[0]) / dice_pool[0]) == 2) {
		if ((find_num_in_pool(dice_pool, size, dice_pool[4]) / dice_pool[4]) == 3) {
			points += (dice_pool[0] * 2);
			points += (dice_pool[4] * 3);
			return points;
		}
	}
	return 0;
}
