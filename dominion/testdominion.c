#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"

void randomize(int *array, size_t n);
void chooseCard(int k[10]);

void randomize(int *array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

void chooseCard(int k[10]){
	
	int i;
	int allCards[]={adventurer, council_room, feast, gardens, mine, remodel, smithy, village,baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};

	randomize(allCards, 20);

	for (i=0; i<10; i++){

		k[i]=allCards[i];

	}	
	

}

int main(int argc, char *argv[]){

	int seed = atoi(argv[1]);
	srand(seed);
	int winner[4];
	int numPlayer = (rand() % (4-2+1))+2;
	struct gameState g;
	int k[10];

	chooseCard(k);

	printf("Starting game ...\n");
	initializeGame(numPlayer, k, seed, &g);

        int money = 0;
        int i=0;
        int numSmithies = 0;
        int numAdventurers = 0;
	int player;

	printf("Number of players is: ");
	printf("%d", numPlayer);
	printf("\n");

	while(!isGameOver(&g)){

		player= whoseTurn(&g);
		printf("The turn of player: ");
		printf("%d", player);	
		printf("\n");	

		money = 0;
		
		
    	for (i = 0; i < numHandCards(&g); i++) {
      	if (handCard(i, &g) == copper)
    	money++;
      	else if (handCard(i, &g) == silver)
    	money += 2;
      	else if (handCard(i, &g) == gold)
    	money += 3;

	}

	printf("You have this much money: ");
	printf("%d", money);
	printf("\n");

	while (g.numActions > 0 ){
		
		for(i=0; i<numHandCards(&g); i++){

			if(handCard(i, &g)< 27 && handCard(i, &g) > 6){
				printf("Playing a card\n");
				playCard(i, 0, 0, 0, &g);
				break;	

			}


		}		

		g.numActions = g.numActions-1;	

	}
	
	int provinceorkingdom = rand() % 2;

	if(provinceorkingdom > 1){
	if(money >= 8){

		printf("Bought Province\n");
		buyCard(province, &g);
	}
	else if(money >= 6){

		printf("Bought Gold\n");
		buyCard(gold, &g);
	}
	else if(money >=3){

		printf("Bought Silver\n");
		buyCard(silver, &g);

	}
	}

	if(provinceorkingdom <=1){

		int buyNum =  rand() % 10;
		("Buying a Card\n");
		buyCard(buyNum, &g);

	}

	endTurn(&g);
	}

	for(i=0; i<numPlayer; i++){
	int score= scoreFor(i, &g);
	printf("Score for player ");
	printf("%d", i);
	printf(": ");
	printf("%d", score);
	printf("\n");
	}

return 0;

}
