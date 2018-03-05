#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define NOISY 1 // set to 0 if you dont want all the printfs

int main(void)
{
	int i;
	int players = 0;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
	int seed = 1000;
	struct gameState G;

	initializeGame(players, k, seed, &G);

	for(i = 0; i < 2000; i++)
	{
		if(i < 2)
		{
			if(initializeGame(players, k, seed, &G) == -1 && NOISY)
			{
				printf("Few players test failed\n");
				exit(1);
			}

			else if(NOISY)
			{
				printf("Few players test passed\n");
			}
		}

		else if( i >= 2 && i <= 4)
		{
			if(initializeGame(players, k, seed, &G) == -1 && NOISY)
			{
				printf("correct players test failed\n");
				exit(1);
			}

			else if(NOISY)
			{
				printf("correct players test passed\n");
			}

		}

		else if(i > 4)
		{
			if(initializeGame(players, k, seed, &G) == -1 && NOISY)
			{
				printf("Too many players test failed\n");
				exit(1);
			}

			else if(NOISY)
			{
				printf("Too many players test passed\n");
			}

		}
	}

	return 0;
}
