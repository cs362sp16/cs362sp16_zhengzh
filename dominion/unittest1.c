/*Unit Test for supplyCount function
 *
 *
 *
 */

#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



int main(){

  struct gameState g;

  int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
	       outpost,baron,tribute};

  int r = initializeGame(2, k, 5, &g);

  assert(g.supplyCount[k[1]]==10);
  assert(g.supplyCount[k[2]]==8);
  assert(g.supplyCount[k[3]]==10);
  assert(g.supplyCount[k[4]]==10); 
  assert(g.supplyCount[k[5]]==10); 
  assert(g.supplyCount[k[6]]==10); 
  assert(g.supplyCount[k[7]]==10);
  assert(g.supplyCount[k[8]]==10);
  assert(g.supplyCount[k[9]]==10);
  assert(g.supplyCount[k[10]]==10);
  
  g.supplyCount[k[1]]=50;
  assert(g.supplyCount[k[1]]==50);	
  printf("No bugs in this supplyCount");
	return 0;
}
