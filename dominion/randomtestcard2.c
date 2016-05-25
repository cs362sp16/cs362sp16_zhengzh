#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"
#include "dominion.h"
#include <math.h>

int main(int argc, char *argv[]){

  	
  struct gameState g;

  int k[10] = {embargo,adventurer,gardens,smithy,cutpurse,mine,ambassador,
	       outpost,baron,tribute};


  int numPlayer;
  int i;
  int seed= atoi(argv[1]);
  srand(seed);

  for(i=0; i<1000; i++){
 
  	numPlayer = rand() %4;
        int randnum= rand();
  	
	initializeGame(numPlayer, k, randnum, &g);

	
	printf("Begin Test ");
	printf("%d", i);
	printf(": \n");

	g.deckCount[0]=rand() % MAX_DECK;
	g.discardCount[0]=rand() % MAX_DECK;
	g.handCount[0]=rand() % MAX_HAND;
	g.numActions= rand() % 5;

	int action = g.numActions;
	int deckcount = g.deckCount[0];
	int discardcount = g.discardCount[0];
	int handcount = g.handCount[0];

	g.hand[0][0] = great_hall;

	playCard(0,0,0,0,&g);


	if(g.handCount[0] != handcount+1){
	
		printf("Did not add card correctly, test fails\n");

	}

	if(g.numActions != action+1){

		printf("Did not add action correctly, test fails\n");

	}

	

}
	
	return 0;
}
