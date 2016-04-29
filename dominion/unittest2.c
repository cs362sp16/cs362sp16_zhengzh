/*Unit Test for isGameOver function
 *
 */

#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void checkasserts(){

	printf("isGameOver successfully ran\n");

}

int main(){

  struct gameState g;

  int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
	       outpost,baron,tribute};

  int r = initializeGame(2, k, 5, &g);


  assert(isGameOver(&g)==0);
  

  g.supplyCount[k[1]]=0;
  g.supplyCount[k[2]]=0;
  g.supplyCount[k[3]]=0;

  assert(isGameOver(&g)==1);

  g.supplyCount[k[1]]=10;
  g.supplyCount[k[2]]=10;
  g.supplyCount[k[3]]=10;
  g.supplyCount[province]=0;

  assert(isGameOver(&g)==1);  

  checkasserts();
  return 0;

}
