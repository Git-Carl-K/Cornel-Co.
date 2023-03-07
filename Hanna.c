#include <stdio.h>
#include <stdlib.h>

//compare function for quick sort (small to big)
int compare_small(const void * a, const void * b)
{
	if ( *(int*)a <  *(int*)b ) return -1;
	if ( *(int*)a == *(int*)b ) return 0;
	return 1;
}

//compare function for quick sort (small to big)
int compare_big(const void * a, const void * b)
{
	if ( *(int*)a >  *(int*)b ) return -1;
	if ( *(int*)a == *(int*)b ) return 0;
	return 1;
}

//prints out dice pool to console
//*parameters:
//(1) array of int's to print
//(2) the size of the array
void print_pool(int arr[], int arr_size)
{
	for (int i = 0; i < arr_size; i++)
		printf ("%d ", arr[i]);
}

//checks for a collection of the same dice-face
//*parameters:
//(1) array of int's to check
//(2) the size of the array
//(3) the number to check for
//returns the points collected
int find_num_in_pool(int arr[], int arr_size, int num) {
	int found = 0;
	for (int i = 0; i < arr_size; i++) {
		if (arr[i] == num) {
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
//(1) array of int's to check
//(2) the size of the array
//(3) the number of same int's to check for
//returns the points collected
int x_of_a_kind(int arr[], int arr_size, int num) {
	qsort(arr, arr_size, sizeof(int), compare_big);
	int points = 0;
	for (int i = 0; i < arr_size; i++) {
		if ((find_num_in_pool(arr, arr_size, arr[i]) / arr[i]) == num) {
			points += (arr[i] * num);
			return points;
		}
	}
	return 0;
}

//checks for a small straight
//*parameters:
//(1) array of int's to check
//(2) the size of the array
//returns the points collected
int check_small_straingt(int arr[], int arr_size) {
	qsort(arr, arr_size, sizeof(int), compare_small);
	int points = 0;
	if (arr[0] == 1) {
		for (int i = 0; i < (arr_size-1); i++) {
			if (arr[i] == arr[i+1] - 1) {
				continue;
			} else {
				return 0;
			}
		}
	} else {
		return 0;
	}
	for (int i = 0; i < arr_size; i++) {
		points += arr[i];
	}
	return points;
}

//checks for a large straight
//*parameters:
//(1) array of int's to check
//(2) the size of the array
//returns the points collected
int check_large_straingt(int arr[], int arr_size) {
	qsort(arr, arr_size, sizeof(int), compare_big);
	int points = 0;
	if (arr[0] == 6) {
		for (int i = 0; i < (arr_size-1); i++) {
			if (arr[i] == arr[i+1] + 1) {
				continue;
			} else {
				return 0;
			}
		}
	} else {
		return 0;
	}
	for (int i = 0; i < arr_size; i++) {
		points += arr[i];
	}
	return points;
}

//checks for pairs
//*parameters:
//(1) array of int's to check
//(2) the size of the array
//(3) the number of pairs to check for
//returns the points collected
int check_pairs(int arr[], int arr_size, int num) {
	qsort(arr, arr_size, sizeof(int), compare_big);
	int pairs = 0;
	int points = 0;
	for (int i = 0; i < arr_size; ) {
		if ((find_num_in_pool(arr, arr_size, arr[i]) / arr[i]) >= 2) {
			pairs++;
			points += (arr[i] * 2);
			if (pairs == num) {
				return points;
			} else {
				i += (find_num_in_pool(arr, arr_size, arr[i]) / arr[i]);
				continue;
			}
		}
		i++;
	}
	return 0;
}

//checks for full house
//*parameters:
//(1) array of int's to check
//(2) the size of the array
//returns the points collected
int check_full_house(int arr[], int arr_size) {
	qsort(arr, arr_size, sizeof(int), compare_big);
	int points = 0;
	if ((find_num_in_pool(arr, arr_size, arr[0]) / arr[0]) == 3) {
		if ((find_num_in_pool(arr, arr_size, arr[4]) / arr[4]) == 2) {
			points += (arr[0] * 3);
			points += (arr[4] * 2);
			return points;
		}
	}
	if ((find_num_in_pool(arr, arr_size, arr[0]) / arr[0]) == 2) {
		if ((find_num_in_pool(arr, arr_size, arr[4]) / arr[4]) == 3) {
			points += (arr[0] * 2);
			points += (arr[4] * 3);
			return points;
		}
	}
	return 0;
}
