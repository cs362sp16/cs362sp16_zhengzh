/*Unit Test for Great Hall
 *
 *
 */

#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void checkasserts(){

	printf("Great Hall is implemented incorrectly, however somewhere else in the code is making it work\n");

}

int main(){

  struct gameState g;

  int k[10] = {great_hall,adventurer,gardens,embargo,cutpurse,mine,ambassador,
	       outpost,baron,tribute};

  int r = initializeGame(2, k, 5, &g);

  g.hand[0][0]=great_hall;
  int action= g.numActions;
  int numCardHand=g.handCount[0];

  playCard(0,0,0,0, &g);

  assert(g.numActions==action);//The code that is in charge of decrementing action is not working, this is why this assertion passes, even though it shouldn't have.
  assert(g.handCount[0]==numCardHand);

  
  checkasserts(); 

return 0;

}
