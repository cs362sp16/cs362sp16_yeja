#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

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
//testing for supplyCount test: #3
int main(){
    struct gameState g;
    int testCard = 1;

    g.supplyCount[testCard] = 5;
    if(supplyCount(testCard,&g) != 5){
        printf("Error in card supply\n");
        failure = 1;
    }else{
        printf("Correct supplyCount\n");
    }
    if(failure == 0){
        printf("No Error found in card supply\n");
    }
	//printf("Test Successfully");
    return 0;
}