/*Unit Test for the card Smithy
 *
 *
 */
#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int error =0;
void checkasserts(){
	if(error==0){
	printf("Smithy successfully ran\n");
	}
}

int main(){

  struct gameState g;

  int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
	       outpost,baron,tribute};

  int r = initializeGame(2, k, 5, &g);

  g.hand[0][0]=smithy;
  int numCardHandBefore=g.handCount[0];
  playCard(0,0,0,0, &g);
  if(g.handCount[0]!=numCardHandBefore+2){
	printf("Does not correctly draw 3 cards\n");
	error=1;	


	}//Does not correctly draw 3 cards
   else if(g.handCount[0]==numCardHandBefore+2){
	printf("Test passed for drawing 3 cards\n");

	}

	if(cardEffect(smithy, 0,0,0,&g,0,0)==0){
		printf("cardEffect successfully returned 0\n");

	}
	else if(cardEffect(smithy, 0,0,0,&g,0,0)!=0){
		printf("cardEffect failed to return 0\n");

	}
 
  checkasserts();
  return 0; 
}
