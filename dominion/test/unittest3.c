/*Unit Test for gainCard function
 *
 */

#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int error=0;
void checkasserts(){

	if(error==0){
	printf("gainCard successfully ran\n");
	}
}

int main(){

  struct gameState g;

  int i;
  int j;

  int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
	       outpost,baron,tribute};

  int r = initializeGame(2, k, 5, &g);

  int sizeDeckBefore=g.deckCount[0];
  int sizeHandBefore=g.handCount[0];

  int gainreturn=gainCard(province, &g, 1, 0);

  if(g.deckCount[0]!=sizeDeckBefore+1){
  printf("Deckcount was not correctly incremented\n");
	error = 1;
	}
  for(i=1;i<5;i++){
    int temp=g.hand[0][i];
    printf("hand before\n");
    printf("%d", temp);
    printf("\n");
  
  }  

  int gain2return=gainCard(cutpurse, &g, 2, 0);

  if(g.handCount[0]!=sizeHandBefore+1){
	printf("size of hand was not correctly incremented");
	error=1;
    }
  if(g.supplyCount[cutpurse]!=9){
	printf("supplyCount was correctly decremented\n");
	error=1;
	}
  

  for(j=1; j<6; j++){
    int temp2=g.hand[0][j];
    printf("hand after\n");
    printf("%d", temp2);
    printf("\n");

  }
  
   
  printf("Can properly increment deckCount and handCount, also tested that it can add the correct card to its hand. However, for some reason the initialize function starts the game with player 0 instead of player 1 which can get confusing. This is an issue with initialize however"); 

  checkasserts();

  return 0;

}
