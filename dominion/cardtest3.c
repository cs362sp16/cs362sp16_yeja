#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"

#define MIN_PLAYERS 2

int failure = 0;

int my_assert(int x, char* message){
	if (x == 0){
		printf("assertion failed %\n", message);
		failure = 1;
	}
	else{
		printf("Test Successfully\n");
	}
}

void check_asserts(){
	if (!failure){
		printf("Tested successfully\n");
	}
	else{
		printf("Test fails\n");
	}
}

int main(){
	printf("====Testing for the card village====");

	struct gameState g;

	int k[10] = {village, adventurer, gardens, embargo, cutpurse, mine, ambassador, outpost, baron, tribute };

	initializeGame(MIN_PLAYERS, k, 5, &g);

	g.whoseTurn = 0;
	g.hand[0][0] = great_hall;

	drawCard(g.whoseTurn, &g);
	g.numActions += 2;
	
	my_assert(g.handCount[0] = g.numActions, "Player has drawn 2 cards by using Village");
	my_assert(g.hand[0][0] != village, "village has been removed from player's hand");

	return 0;
}