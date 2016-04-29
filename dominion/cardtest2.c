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
}

void check_asserts(){
    if(!failure){
        printf("Tested successfully");
    }else{
        printf("Test fails");
    }
}

int main(){
    printf("====Testing for the card great_hall====");

    struct gameState g;

    int k[10] = {great_hall,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute};

    initializeGame(MIN_PLAYERS, k, 5, &g);

     g.whoseTurn = 0;
     g.hand[0][0] = great_hall;

     drawCard(g.whoseTurn, &g);
     g.numActions++;

	 my_assert(g.handCount[0] = g.numActions, "Player has drawn 1 cards by using great_hall");
	 my_assert(g.hand[0][0] != great_hall, "great_hall has been removed from player's hand");

    return 0;
}