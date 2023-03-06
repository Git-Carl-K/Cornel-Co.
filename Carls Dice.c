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




int roll_dice()
{
	int dice = rand() % 6 + 1;
	return dice;
}

void add_dice_to_pool()
{
	int dice_pool[5];
	int count = 0;
	for (int i = 0; i < 5; i++)
	{
		dice_pool[count] = roll_dice();
		printf("%d\n", dice_pool[count]);
		count++;

	}
}



//
//int print_dice()
//{
//	roll_dice(1);
//	printf("%d", dice);
//}




int main()
{
	srand(time(NULL));

//	roll_dice;
	add_dice_to_pool();



}
