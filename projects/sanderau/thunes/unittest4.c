#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define NOISY 1

int main(void)
{
	int i, j;
	int passed = 1;
	int players = MAX_PLAYERS;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
	int seed = 1000;
	struct gameState G;

	initializeGame(players, k, seed, &G);
	
	//test to make sure the handcount function works for all values
	for(j = 0; j < MAX_PLAYERS; j++)
	{
		for(i = 0; i < MAX_HAND; i++)
		{
			G.handCount[j]++;

			if(NOISY && numHandCards(&G) == i)
			{
				printf("Expecting %d; got %d : PASSED\n", i, numHandCards(&G));
			}

			else if(NOISY)
			{
				printf("Expecting %d; got %d : FAILED\n", i, numHandCards(&G));	
				passed = 0;
			}
		}
	}

	if(passed && NOISY)
	{	
		printf("All tests passed\n");
	}

	else if(NOISY)
	{
		printf("some tests failed\n");
	}

	return 0;
}
