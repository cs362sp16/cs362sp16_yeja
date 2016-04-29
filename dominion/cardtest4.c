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
}

void check_asserts(){
	if (!failure){
		printf("Tested successfully");
	}
	else{
		printf("Test fails");
	}
}

int main(){
	printf("=====Testing for the card minion=====");

	struct gameState g;

	int k[10] = {minion, adventurer, gardens, embargo, cutpurse, mine, ambassador, outpost, baron, tribute };

	initializeGame(MIN_PLAYERS, k, 5, &g);

	g.hand[0][0] = minion;
	for (int i = 0; i < 5; i++){
		drawCard(1, &g);
	}
	cardEffect(minion, -1, 0, -1, &g, 0, -1);
	my_assert(g.handCount[0] != 8, "Other player has discard hand and draw 4 new cards");
	my_assert(g.handCount[1] != 4, "You discard a card and draw 4 new cards")


}