/*Unit Test for Embargo
 *
 *
 */

#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int error=0;
void checkasserts(){
	if(error==0){
	printf("Embargo successfully ran\n");
	}
}

int main(){

  struct gameState g;

  int k[10] = {embargo,adventurer,gardens,smithy,cutpurse,mine,ambassador,
	       outpost,baron,tribute};

  int r = initializeGame(2, k, 5, &g);

  g.hand[0][0]=embargo;

  playCard(0, adventurer, 0, 0, &g);

  int totalcoin=g.coins;
 
  if(g.embargoTokens[adventurer]!=1){
	printf("Error incrementing embargo token\n");
	error=1;
	}
  if(g.coins!=totalcoin+2){
	printf("Error incrementing coin\n");
	error=1;
	}
  endTurn(&g);

  buyCard(adventurer, &g);

  if(g.discardCount[1]!=1){

	printf("Error adding curse\n");
	error=1;

	}//Makes sure there is a curse in the discard pile 

  checkasserts();
return 0;

}
