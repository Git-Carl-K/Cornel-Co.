
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "Cornel.h"


int compare_top_ten (const void *a, const void *b)
{
	top_ten *temp_a, *temp_b;
	temp_a= (top_ten*)a;
	temp_b= (top_ten*)b;

	//if a is bigger than b, move a to the left <-- (up towards index [0]
	if (temp_a->score > temp_b->score)
	{
		return-1;
	}

	//If a is equal to b -- > do nothing
	if (temp_a->score == temp_b->score)
	{
		return 0;
	}


	//if a is smaller than b, move a to the right
	if (temp_a->score < temp_b->score)
	{
		return 1;
	}
	return 0;
}


void print_top_ten (top_ten players[])
{



	printf("---------------------\n");
	printf("   >>> TOP TEN <<< \n");
	printf("---------------------\n");

	qsort (players,10, sizeof(top_ten), compare_top_ten);
	for (int i = 1; i < 11; i++)
	{
		printf("[%d]\t%s\t",i, players[i-1].name);
		printf(" %dp\n", players[i-1].score);
	}

}

/*
* Loads highscore into players (can later be remade to read contents from a file instead)
* Since we are using a pointer we do not have to return anything. The results will be
* directly saved into the array that we put into the function
*/

void load_highscore(top_ten *players)
{
    strcpy(players[0].name, "Robert");
    strcpy(players[1].name, "Anna");
    strcpy(players[2].name, "Markus");
    strcpy(players[3].name, "Johan");
    strcpy(players[4].name, "Hanna");
    strcpy(players[5].name, "Cornel");
    strcpy(players[6].name, "Carl");
    strcpy(players[7].name, "Loise");
    strcpy(players[8].name, "Roger");
    strcpy(players[9].name, "Johan");
    players[0].score = 200;
    players[1].score = 180;
    players[2].score = 160;
    players[3].score = 140;
    players[4].score = 120;
    players[5].score = 100;
    players[6].score = 80;
    players[7].score = 60;
    players[8].score = 40;
    players[9].score = 20;

}

void add_to_highscore(top_ten *players, score_board to_add)
{
    // find which place to put the new score by comparing with placements in the highscore
    // We start with last place and work our way up the highscore
	//We want to use pos later, so we declare it outside of the loop
	int pos;

    for (pos = 9; pos > 0; pos--)
    {
        // If the new player has less points than this placement on the highscore, we stop
        if (players[pos].score > to_add.scores.total_score)
        {
            pos++; //go back down one step on the highscore
            break;
        }
    }

    //Pos now contains the index where we want to insert the new score
    //But before we do, we need to move all the other values to make room

    // We start by moving the score in 9th place to 10th place and work our way up
    for (int i = 8; i >= pos; i--)
    {
        // For instance the 8th position moves to 9th position and so on
        players[i+1] = players[i];
    }

    // Once all the players are moved, we write the new player to our highscore
    // His name and score can be found in the scoreboard

    strcpy(players[pos].name, to_add.name);
    players[pos].score = to_add.scores.total_score;

    //Since players is a pointer we don't need to return anything. Changes happens directly
    //to the array we sent into this function.
}

/* SAVE TO TEXTFILE
 * This function takes the players top_ten struct array and prints it out to a textfile
 * top_ten players [] = the struct array located in main and holds
   the variables name and score.
*/


bool save_top_ten (char *filename,  top_ten players[])
{
	FILE *pFile;

	// fopen returns a pointer to our file.




	//char filename = choose a name for the file
	// the location on your computer for simplicity
	// 	 EX: "C:\\Users\\corne\\OneDrive\\Desktop\\ xxx.txt" , w+)*/

	pFile = fopen (filename, "w+");
	if (pFile == NULL)
		perror ("error opening a file");

	else
	{

		//Before writing to file, we sort the scores high to low.

		qsort (players,10, sizeof(top_ten), compare_top_ten);
		for (int i = 1; i < 11; i++)
		{

			//to make it easy to re-read the file again, don´t forget the comma,
			//  after the first format specifier and continue to the last line.
			//	 EX: 	fprintf(pFile, "%s,", players[i-1].name) ;
			//	 	 	and so on..


			fprintf(pFile, "%s,", players[i-1].name) ;
			fprintf(pFile," %d\n", players[i-1].score);
		}

	}


	fclose (pFile);

	return false;
}

bool read_top_ten (char *filename,  top_ten fromfile[])
{

	char buffer [100];

	int count = 0;


	FILE *pFile;

	// fopen returns a pointer to our file.
	// It can either read or write or both. We are going to read "r"

	pFile = fopen (filename, "r");
	if (pFile == NULL)
		perror ("error opening a file");


	else
	{

		//Lets read the file until EOF the and store it in buffer.

		while (!feof(pFile))
		{
			if (fgets(buffer, 100, pFile) == NULL)
				break;


			// in main, we created a top_ten fromfile [] array.
			// Store the data in the variables in the array.
			// We store each to first comma , in the line.
			// continue to next comma etc..
			// OBS! Since we are reading from a textfile and we have integers
			// dont forget atoi!

			char *my_string;
			my_string = strtok(buffer, ",");
			strcpy(fromfile[count].name, my_string);

			my_string = strtok(NULL, ",");
			fromfile[count].score = atoi(my_string);
			count++;

		}
	}

	fclose (pFile);

	// after we read the data into our fromfile struct array
	// we print out the top_ten scores from high to low

	qsort (fromfile,10, sizeof(top_ten), compare_top_ten);
	for (int i = 1; i < 11; i++)
	{
		printf("[%d]\t%s\t",i, fromfile[i-1].name);
		printf(" %dp\n", fromfile[i-1].score);
	}



	return false;
}









int main ()
{




	//Kvar i main
	top_ten players [10];


	load_highscore(players);

	print_top_ten(players);

	top_ten fromfile [10];

//    score_board current_player;
//    strcpy(current_player.name,"Per");
//    current_player.scores.total_score = 90;
//
//    add_to_highscore(players, current_player);
//
//    print_top_ten(players);

	return 0;
}




