#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"

#define MAX_NUM_PLAYER 4
#define MIN_NUM_PLAYER 2

int failure = 0;

int my_assert(int x, char* message){
    if(x == 0){
        printf("assertion failed %\n",message);
        failure = 1;
    }
}

void check_asserts(){
    if(!failure){
        printf("Tested successfully\n");
    }else{
        printf("Test fails");
    }
}
//testing for endTurn test: #4
int main(){
        int k_cards[] = {smithy, adventurer, gardens, embargo, cutpurse, mine, ambassador, outpost, baron, tribute};

        struct gameState g;
        struct gameState *gameState = newGame();
        int turn;

        initializeGame(MIN_NUM_PLAYER, k_cards, 8, gameState);

        turn = endTurn(gameState);
        my_assert(turn != -1, "Error, unable to end turn");

		printf("Test Successfully");
        return 0;
}