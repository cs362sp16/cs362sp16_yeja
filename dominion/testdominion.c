#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "dominion.h"
#include "interface.h"
#include "dominion_helpers.h"
#include "rngs.h"

int failure = 0;

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

struct gameState randomInitialize(long seed){
    struct gameState gamePlay;
    enum CARD k[10];

    SelectStream(1);
    PutSeed(seed);

    randomKingdomCards(k);

    int numPlayers = ((int)floor(Random()*2)) + 2;
    initializeGame(numPlayers, (int*)k, (int)seed, &gamePlay);

    return gamePlay;
}

bool containCard(int *cards, int card){
    int i;
    for(i = 0; i < 10; i++){
        if(cards[i] == card){
            return true;
        }
    }
    return false;
}

enum CARD randomCard(){
    return rand() % (treasure_map + 1);
}

int cardCheck(enum CARD* arry, enum CARD card, int index){
    int i;
    for(i = 0; i < index; i++){
        if(arry[i] == card){
            return 1;
        }
    }
    return 0;
}

void randomKingdomCards(int *cards){
    srand(time(NULL));
    for(i = 0; i < 10; i++){
        cards[i] = (enum CARD)(int)floor(Random() * (treasure_map + 1));
        while(cardCheck(cards, cards[i], i - 1)){
            cards[i] = (enum CARD)(int) floor (Random() * (treasure_map + 1));
        }
    }
}

int countTreasure(struct gameState *g, int player){
    int card, x = 0;
    int i;
    for(i = 0; i < (*g).handCount[player]; i++){
        treasureCard = g->hand[player][i];
        if(card == copper){
            x++;
        }
        if(card == silver){
            x = x+2;
        }
        if(card == gold){
            x = x+3;
        }
    }
    return x;
}


int playerBuyCards(struct gameState *g){
    enum CARD card = randomCard();
    updateCoins(g->whoseTurn, g, 0);
    while(g->numBuys > 0){

        if(g->coins = 0 || g->numBuys == 0){
             printf("Failed to buy\n");
             return -1
        }
        while(getCost(card) > g->coins || card == curse || g->supplyCount[card] == 0){
            card = randomCard();
        }

        printf("Successfully bought card: %d\n", card);
        buyCard(card, g);
    }
    return 0;
}

int cardAction(enum CARD *cards, int length){
    int i;
    for(i = 0; i < length; i++){
       if(cards[i] >= adventurer && cards[i] <= treasure_map){
            return 1;
       }
    }
    return 0;
}

void playerAction(){
    int success = 1;
    while(success && g->numActions > 0){
        while(cardAction(g->hand[g->whoseTurn],g->handCount[g->whoseTurn])){
            success = playCard(g) = -1 ? 0 : 1;
        }
    }
}

int getCardIndex(struct gameState *g){
    int handCount;
    enum CARD *currentHand;

    handCount = g->handCount[g->whoseTurn];
    currentHand = g->hand[g->whoseTurn];

    if(!cardAction(currentHand, handCount)){
       return -1;
    }
    int randmonCardIndex = (int)floor(Random()*handCount);

    while(!currentHand[randmonCardIndex] >= adventurer && currentHand[randmonCardIndex] <= treasure_map)){
        randmonCardIndex = (int)floor(Random()*handCount);
    }

    return randmonIndex;
}

int playCards(struct gameState *g){
    int randmonCardIndex, result;
    enum CARD *currentCard;

    randmonIndex = getCardIndex(g);
    currentCard = g->hand[g->whoseTurn][randmonCardIndex];
    result = playCard(randmonCardIndex, 0, 0, 0, &g);

    printf("You played : %d", currentCard, " card\n");

    return result;
}

void getGameWinner(struct gameState *g){
    printf("Game over");
    int i;
    int winner[4];
    getWinner(winner, &g)
    for(i = 0; i < g.numPlayers; i++){
        if(winner[i]){
            printf("Player %d WON!\n", i);
        }
    }
}

void randomGamePlay(long seed){
    struct gameState g = randomInitialize(seed);

    printf("Number of players: %d\n", g.numPlayers);
    while(!isGameOver(&g)){
        printf("Player: %d\n", g.whoseTurn);
        playerAction(&g);
        playerBuyCards(&g);
        printf("End Turn\n");
    }

    //keep track of players' score
    int i;
    for(i = 0; i < g.numPlayers; i++){
        printf("Score for Player %d\n", i, scoreFor(i, &g));
    }

    getGameWinner(&g);
}

int main(int argc, char** argv[]){
    long seeding;

    if(argc != 2){
        printf("testdominion.c [seed]");
        return 0;
    }

    seeding = atoi(argv[1]);
    randomGamePlay(seeding);

    return 0;
}