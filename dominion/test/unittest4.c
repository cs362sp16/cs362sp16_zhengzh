/*Unit Test for endTurn function
 *
 *
 */ 
#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void checkasserts(){

	printf("endTurn successfully ran\n");

}

int main(){

  struct gameState g;

  int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
	       outpost,baron,tribute};

  int r = initializeGame(2, k, 5, &g);

  int current=g.whoseTurn;
  printf("%d", current); 
  endTurn(&g);

  assert(current != g.whoseTurn);
  assert(g.whoseTurn == 1);

  endTurn(&g);
  assert(g.whoseTurn == 0);

  printf("Test can end a player's turn, and loops back around when it reaches the max player, however, player number starts at player 0, ends at player 1, instead of player 1 and player 2.");
  checkasserts();

return 0;

}
