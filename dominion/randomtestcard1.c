#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define NUM_TEST 1000
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

int main(int argc, char* argv[]){

    int i, j;
    struct gameState G;
    int seed = 0;
    int numPlayer = rand() % MAX_PLAYER;
    int k[10] = {adventurer, gardens, embargo, village, steward, mine, cutpurse, sea_hag, tribute, smithy};
    int state1 = rand() % 3;
    int state2 = rand() % 3;
    int state3 = rand() % 3;

    seed = (int)argv[1];
    srand(seed);

    printf("Testing the card Cutpurse by randmom generation");

	for (i = 0; i < NUM_TEST; i++){
        j = initializedGame(((numPlayer) + 1), k, rand(), &G);
        j = cardEffect(cutpurse, state1, state2, state3, &G, 0, 0);

        my_assert(j == 0, "Random Testing failed");

        if(failure){
            break;
        }
    }

    check_asserts();

    return 0;
}