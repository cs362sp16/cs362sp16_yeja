#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define NUM_TEST 500
#define MAX_PLAYER 4

int failure = 0;
int success = 0;

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
        printf("Tested successfully\n");
    }else{
        printf("Test fails");
    }
}

int main(int argc, char *argv[]){

    struct gameState G;
    seed = (int)argv[1];
    srand(seed);
    int i, num = 0;

    printf("Testing the card Smithy by random generation");

    int k[10] = {smithy, gardens, embargo, village, steward, mine, cutpurse, sea_hag, tribute, adventurer};

    for(i = 0; i < NUM_TEST; i++){
        initializeGame(MAX_PLAYER, k, rand(), &G);

         G.handCount[num] = rand() % MAX_HAND;
         handCount = G.handCount[num];

         cardEffect(handCount + 2, G, handCount[num], "Number of cards in your hand")
    }

    return 0;
}
