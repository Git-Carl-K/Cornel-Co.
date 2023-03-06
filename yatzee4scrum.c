#include <stdio.h>
#include <stdlib.h>

//compare function for quick sort
int compare_int(const void * a, const void * b)
{
	if ( *(int*)a <  *(int*)b ) return -1;
	if ( *(int*)a == *(int*)b ) return 0;
	return 1;
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

//prints out dice pool to console
//*parameters:
//(1) array of int's to print
//(2) the size of the array
void print_pool(int arr[], int arr_size)
{
	for (int i = 0; i < arr_size; i++)
		printf ("%d ", arr[i]);
}
