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
int find(int dice_pool[], int size, int dice_face) {
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
int x_of_a_kind(int dice_pool[], int size, int x_of_a_kind) {
	qsort(dice_pool, size, sizeof(int), compare_big);
	int points = 0;
	if (x_of_a_kind != 5) {
		for (int i = 0; i < size; i++) {
			if ((find(dice_pool, size, dice_pool[i]) / dice_pool[i]) == x_of_a_kind) {
				points += (dice_pool[i] * x_of_a_kind);
				return points;
			}
		}
	} else {
		if ((find(dice_pool, size, dice_pool[0]) / dice_pool[0]) == x_of_a_kind) {
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
int check_small_straigt(int dice_pool[], int size) {
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
int check_large_straigt(int dice_pool[], int size) {
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
int check_pairs(int dice_pool[], int size, int pair) {
	qsort(dice_pool, size, sizeof(int), compare_big);
	int pairs = 0;
	int points = 0;
	for (int i = 0; i < size;) {
		if ((find(dice_pool, size, dice_pool[i]) / dice_pool[i]) > 3) {
			return 0;
		}
		if ((find(dice_pool, size, dice_pool[i]) / dice_pool[i]) < 2) {
			i++;
			continue;
		} else {
			pairs++;
			points += (dice_pool[i] * 2);
			if (pairs == pair) {
				return points;
			} else {
				i += (find(dice_pool, size, dice_pool[i]) / dice_pool[i]);
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
	if ((find(dice_pool, size, dice_pool[0]) / dice_pool[0]) == 3) {
		if ((find(dice_pool, size, dice_pool[4]) / dice_pool[4]) == 2) {
			points += (dice_pool[0] * 3);
			points += (dice_pool[4] * 2);
			return points;
		}
	}
	if ((find(dice_pool, size, dice_pool[0]) / dice_pool[0]) == 2) {
		if ((find(dice_pool, size, dice_pool[4]) / dice_pool[4]) == 3) {
			points += (dice_pool[0] * 2);
			points += (dice_pool[4] * 3);
			return points;
		}
	}
	return 0;
}