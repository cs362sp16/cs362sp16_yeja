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

int my_assert(int x, int y, char* message){
    if(x != y){
        printf("Test failed %\n",message);
        failure = 1;
	}
	else{
		printf("Random Generated Successfully\n");
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
    
    srand(time(NULL));
    int i, num = 0;

    printf("Testing the card Smithy by random generation");

    int k[10] = {smithy, gardens, embargo, village, steward, mine, cutpurse, sea_hag, tribute, adventurer};

    for(i = 0; i < NUM_TEST; i++){
        initializeGame(MAX_PLAYER, k, rand(), &G);

         G.handCount[num] = rand() % MAX_HAND;
         int numCardInHand = G.handCount[num];

		 cardEffect(smithy ,0, 0, 0, &G, 0, 0);

		 my_assert(numCardInHand + 2, G.handCount[num], "Number of Cards in Hand");
    }

    printf("Testing complete");
    return 0;
}