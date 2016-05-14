#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define NUM_TEST 1000
#define MAX_PLAYER 4
#define MAX_DECK 500

int failure = 0;
int success = 0;

int main(int argc, char* argv[]){

    int numPlayer = rand() % 4;
    struct gameState G;
    int i, j, newCard, cdeck;
    int treasureCardDrawn[MAX_PLAYER] = {0};

    int k[10] = {adventurer, gardens, embargo, village, steward, mine, cutpurse, sea_hag, tribute, smithy};
    initializeGame(numPlayer, k, rand(), &G);

    for(i = 0; i < numPlayer; i++){
        cdeck = rand()% 45;
        G.deckCount[i] = cdeck;
        G.handCount[i] = 0;
        G.hand[i][0] = adventurer;
        for(j = 1; j < cdeck; j++){
            newCard = rand() % (treasure_map + 1);
            G.deck[i][j] = newCard;

            if(treasureCardDrawn[i] < 2 ){
                treasureCardDrawn[i]++;
            }
        }
    }
	
    for(i=0;i < NUM_TEST;i++){

    			initializeGame(numPlayer,k,rand(),&G);

    			G.deckCount[numPlayer] = rand() % MAX_DECK;
    			G.discardCount[numPlayer] = rand() % MAX_DECK;

    			int deckCount = G.deckCount[numPlayer];

    			cardEffect(adventurer,1,1,1,&G,0,0);
    }

    printf("Random Testing for Adventurer Card Complete \n");

    return 0;
}