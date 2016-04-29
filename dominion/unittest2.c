#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"

#define MIN_NUM_PLAYER 2
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
        printf("Tested successfully\n");
    }else{
        printf("Test fails");
    }
}

//testing for whoseTurn test #2
int main(){

    struct gameState g;
    //struct gameState *gameState = newGame();
	int k_cards[] = { smithy, adventurer, gardens, embargo, cutpurse, mine, ambassador, outpost, baron, tribute };

    initializeGame(MIN_NUM_PLAYER, k_cards, 5, &g);

	int x = whoseTurn(&g);
	my_assert((x == 0), "whoseTurn did not recognize the turn appropriately!\n");

	

    return 0;
}