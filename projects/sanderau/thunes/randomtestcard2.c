/******************************************************************************
 * Author: Austin Sanders
 * Date: 2.17.18
 * Description: Random test one for the great hall card
 * Input: none
 * Output: random tests trying to break the function, and testing code coverage.
 * Warnings: none
*******************************************************************************/
#define loud 1 // display all tests
#define indefinite 0 // when true it will perform tests till failure
#define definite 10000 //how many times to run through a non infinite loop

//standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

//our libraries
#include "dominion.h"
#include "dominion_helpers.h"

//helper functions
void runTest(int, struct gameState, int);

int main(int argc, char *argv[])
{
	if(loud)
		printf("--------------------------------- Random Test Card Two -----------------------------------------\n");
	srand(time(NULL));

	int players = 2, player = 1;
	int k[10] = {council_room, adventurer, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int seed = 1000;
	struct gameState G;

	if(initializeGame(players, k, seed, &G) == -1)
	//initialize game, if failed print error and exit.
	{
		fprintf(stderr, "Could not initialize game!\n");
		exit(1);
	}		

	if(indefinite)
	{
		int i = 1;
		while(1)
		{
			runTest(player, G, i);
			i++;	
		}
	}

	else
	{
		int i;
		for(i = 0; i < definite; i++)
		{
			runTest(player, G, i+1);
		}
	}

	return 0;
}	

//implement helper functions
void runTest(int player, struct gameState G, int iterator)
{
	player = G.whoseTurn;
	int newActions = rand()%10000+1; // generate a new random number of actions
	G.numActions = newActions;
	newActions++;

	int sizeOfDeck = rand()%MAX_DECK+1;
	G.deckCount[player] = sizeOfDeck;
	int i;
	for(i = 0; i < sizeOfDeck; i++)
	{
		G.deck[player][i] = rand()%25; //put a random card in the deck
	}
	G.deck[player][i] = -1; // cap the deck

	for(i = 0; i < 5; i++)
	{
		G.hand[player][i] = rand()%25; // get a random card
	}

	int villagePos = rand()%5; //get a position to put the village card
	G.hand[player][villagePos] = village;
	G.handCount[player] = 5; // set hand count to five

	cardeffect_great_hall(great_hall, 0, 0, 0, &G, 0, NULL);
	if(loud)
	{
		printf("ITERATION: %d\n", iterator);
		printf("---------------------EXPECTED-------------------\n");
		printf("Actions: %d | sizeOfDeck: %d  \n", newActions, sizeOfDeck-1);
		
		printf("---------------------RECEIVED-------------------\n");
		printf("Actions: %d | sizeOfDeck: %d \n", G.numActions, G.deckCount[player]);
	
		if(newActions == G.numActions && G.deckCount[player] == sizeOfDeck-1)
		{
			printf("STATUS: PASSED\n\n");
		}

		else
		{
			printf("STATUS: FAILED\n\n");
		}
	}
}
