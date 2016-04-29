#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"

#define MIN_PLAYERS 2

int failure = 0;

int my_assert(int x, char* message){
    if(x == 0){
        printf("assertion failed %\n",message);
        failure = 1;
	}
	else{
		printf("Test Successfully\n");
	}
}

void check_asserts(){
    if(!failure){
        printf("Tested successfully");
    }else{
        printf("Test fails");
    }
}
//testing for the card: Smithy
int main(){
    printf("=====Testing for the card: Smithy=====\n");

    struct gameState g;

    int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute};

    initializeGame(MIN_PLAYERS, k, 5, &g);

    g.whoseTurn = 0;
    g.hand[0][0] = smithy;

    int beforeHandCount = g.handCount[0];
    g.handCount[0] = beforeHandCount + 2;

    playCard(0,0,0,0,&g);
    my_assert(g.handCount[0], "Player has drawn 3 cards by using Smithy");
    my_assert(g.hand[0][0] != smithy, "Smithy has been removed from player's hand");

	printf("Test Successfully\n");

    return 0;
}