#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"

int failure = 0;

int my_assert(int x, char* message){
    if(x == 0){
        printf("assertion failed \n",message);
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

//testing for playCard test: #1
int main(){

    struct gameState g;

    int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute};

	initializeGame(2, k, 5, &g);
    int buyCards = buyCard(copper, &g);

    if(buyCards == 0){
        printf("Buy Successfully");
    }else{
        printf("Fail to buy");
    }
    int previousBuys = g.numBuys;
    int previousCoins = g.coins;

    if(g.numBuys == (previousBuys - 1)){
        printf("Buy Successfully");
    }else{
        printf("Fail to buy");
    }
    if(g.coins == (previousCoins - (getCost(copper)))){
        printf("Buy Successfully");
    }else{
        printf("Not enough coins to buy");
    }

	printf("Test Successfully \n");
    return 0;
}

