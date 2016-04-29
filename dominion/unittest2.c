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

    int k_cards[] = {smithy, adventurer, gardens, embargo, cutpurse, mine, ambassador, outpost, baron, tribute};

    struct gameState g;
    struct gameState *gameState = newGame();
    int turn;
    initializeGame(MIN_NUM_PLAYER, k_cards, 8, gameState);

    g.whoseTurn = 9;
    my_assert(whoseTurn(&g) != 9, "Too many players!");

    g.whoseTurn = -2;
    my_assert(whoseTurn(&g) != -2, "Too small, the value has become invalid");

    g.whoseTurn = 1;
    my_assert(whoseTurn(&g) == 1, "Correct value");

    turn = whoseTurn(gameState);
    my_assert(turn == 1, "The next player's turn is incorrect");
    turn = whoseTurn(gameState);
    my_assert(turn == 0, "Not the correct starting player's turn");

    return 0;
}