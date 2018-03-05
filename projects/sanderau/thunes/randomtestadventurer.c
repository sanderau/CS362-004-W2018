/******************************************************************************
 * Author: Austin Sanders
 * File: randomtestadventurer.c
 * Date: 2.17.18
 * Description: Random test one for the adventurer card. This function will randomly place two
 ** treasure cards in a full deck of cards other than treasure. It makes sure the proper amount
 ** of cards are pulled
 * Input: none
 * Output: random tests trying to break the function, and testing code coverage.
 * Warnings: none
*******************************************************************************/

#define loud 1 // display all values
#define indefinite 0 // run the random testing indefinetly
#define definite 10000 // if you dont want to run it indefinitely, run it this many times

//standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

//our libraries
#include "dominion.h"
#include "dominion_helpers.h"

//hepler functions
void runTest(struct gameState G, int p, int iteration);
int randCard();

int main(int argc, char *argv[])
{
	srand(time(NULL));

	if(loud)
		printf("-------------------Testing the adventurer card randomly------------------\n");

	int players = 2, p = 1;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int seed = 1000;
	struct gameState G;

	if(initializeGame(players, k, seed, &G) == -1)
	{
		fprintf(stderr, "Could not initialize the game!\n");
		exit(1);
	}

	if(indefinite)
	{
		int i = 0;
		while(1)
		//run till error
		{
			runTest(G, p, i);
			i++;
		}
	}

	else
	{
		int i;
		for(i = 0; i < definite; i++)
		//run the random test definite amount of times
		{
			runTest(G, p, i+1);
		}
	}

	return 0;
}	


void runTest(struct gameState G, int p, int iteration)
{
	p = G.whoseTurn;
	int posOne = rand()%(MAX_DECK), posTwo;
	do{
		posTwo = rand()%(MAX_DECK);
	}while(posOne == posTwo); //has to be unique positions
	
	int posMax = posOne > posTwo ? posTwo : posOne; // record where the last card is so we can verify if it passed the test
	posMax = 497 - posMax;

	int i;

	G.deckCount[p] = MAX_DECK; // set the deck count equal to the position of the last treasure card
	G.discardCount[p] = 0;
	G.discard[p][0] = -1;

	for(i = 0; i < MAX_DECK; i++)
	{
		if(i != posTwo && i != posOne)
		// if this isnt a position for the gold
		{
			G.deck[p][i] = randCard();
		}

		else if (i ==posOne)
		{
			G.deck[p][i] = copper;
		}

		else if (i == posTwo)
		{
			G.deck[p][i] = copper;
		}
	}

	G.deck[p][i] = -1; // singal end of deck


	cardeffect_adventurer(adventurer, 0, 0, 0, &G, 0, NULL);

	if(loud)
	{
		printf("Iteration: %d: Expecting: %d Output: %d", iteration, posMax, G.discardCount[p]);
		
		if(posMax == G.discardCount[p])
		{
			printf(" | RESULT: PASSED\n");
		}

		else
		{
			printf(" | RESULT: FAILED\n");
		}
	}
}

int randCard()
{
	int c; // the random card that isnt gold
	do{
		c = rand()%26+1;

	}while(c >= 4 && c <=6);

	return c;
}
