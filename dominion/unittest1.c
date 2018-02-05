#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "rngs.h"

#define NOISY  1 //set to noisy to one if you want all the messages.

int main(void)
{
	if(NOISY)
	{
		printf("Testing the isGameOverFunction\n");
	}

	int i;
	int players = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
	int seed = 1000;
	struct gameState G;
	
	if(initializeGame(players, k, seed, &G))
	{
		fprintf(stderr, "Could not initialize the game\n");
	}
	
	//set everything to have a value > 0 except for province
	for(i = 0; i < 25; i++)
	{
		G.supplyCount[i] = 10;
	}

	G.supplyCount[province] = 0;

	if(isGameOver(&G) && NOISY)
	{
		printf("All values set to a value greater than zero except for province: PASSED\n");
	}

	else if(NOISY)
	{
		printf("All values set to a value greater than zero except for province: FAILED\n");
		exit(1);
	}

	//set all values to zero except for province
	for(i = 0; i < 25; i++)
	{
		G.supplyCount[i] = 0;
	}

	G.supplyCount[province] = 10;

	if(isGameOver(&G) && NOISY)
	{
		printf("All values set to 0 except for province: PASSED\n");
	}

	else if(NOISY)
	{
		printf("All values set to 0 except for province: FAILED\n");
		exit(1);
	}

	//all values set to zero
	for(i = 0; i < 25; i++)
	{
		G.supplyCount[i] = 0;
	}
	
	if(isGameOver(&G) && NOISY)
	{
		printf("All values set to 0: PASSED\n");
	}

	else if(NOISY)
	{
		printf("All values set to 0: FAILED\n");
		exit(1);
	}

	//all values set to one
	for(i = 0; i < 25; i++)
	{
		G.supplyCount[i] = 1;
	}
	
	if(isGameOver(&G) == 0 && NOISY)
	{
		printf("All values set to 1: PASSED\n");
	}

	else if(NOISY)
	{
		printf("All values set to 1: FAILED\n");
		exit(1);
	}

	printf("All tests passed\n");

	return 0;
}
