#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define NOISY 1 // set to 0 if you dont want all the printfs

int main(void)
{
	int cardPos = 5;
	int players = 0;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
	int seed = 1000;
	struct gameState G;

	initializeGame(players, k, seed, &G);

	//numbuys set to 0;
	G.numBuys = 0;

	if(buyCard(cardPos, &G) == -1 && NOISY)
	{
		printf("No buys test passed\n");
	}

	else if(NOISY)
	{
		printf("No buys test failed\n");
		exit(1);
	}

	//none of that card

	G.supplyCount[cardPos] = 0;

	if(buyCard(cardPos, &G) == -1 && NOISY)
	{
		printf("No card test passed\n");
	}

	else if(NOISY)
	{
		printf("No card test failed\n");
		exit(1);
	}


	//done

	printf("all tests passed\n");


	return 0;

}

