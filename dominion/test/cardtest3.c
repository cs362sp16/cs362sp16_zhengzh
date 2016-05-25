
#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int error =0;
void checkasserts(){
	if(error==0){
	printf("isGameOver successfully ran\n");
	}
}

int main(){

  struct gameState g;

  int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
	       outpost,baron,tribute};

  int r = initializeGame(2, k, 5, &g);

  
  g.hand[0][0]=outpost;

  playCard(0,0,0,0, &g);

  if(g.outpostPlayed!=1){
	printf("Outpost does not increment correctly\n");
	error=1;
	}

  endTurn(&g);
  if(g.whoseTurn != 0){
	printf("error: no extra turn for user\n");
	error=1;
	}//This assertion fails, does not let user take an extra turn

  checkasserts();
return 0;

}
