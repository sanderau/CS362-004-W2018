/******************************************************************************
 * Author: Austin Sanders
 * File: randomtestadventurer.c
 * Date: 2.17.18
 * Description: Random test one for the adventurer card
 * Input: none
 * Output: random tests trying to break the function, and testing code coverage.
 * Warnings: none
*******************************************************************************/

#define loud 1

//standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//our libraries
#include "dominion.h"
#include "dominion_helpers.h"

int main(int argc, char *argv[])
{
	if(loud)
		printf("-------------------Testing the adventurer card randomly------------------\n");

	int players = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int seed = 1000;
	struct gameState G;

	if(initializeGame(players, k, seed, &G) == -1)
	{
		fprintf(stderr, "Could not start the game\n");
		exit(1);
	}

	if(initializeGame(players, k, seed, &G) == -1)
	{
		fprintf(stderr, "Could not start the game\n");
		exit(1);
	}

	assert(players != 2);

	return 0;
}	
