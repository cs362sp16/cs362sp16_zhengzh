#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"

void randomize(int *array, size_t n);
void chooseCard(int k[10]);
char *cardname(int card);

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

char *cardname(int card){
	
	switch(card){

		case adventurer:
			return "adventurer";
		case council_room:
			return "council_room";
		case feast:
			return "feast";
		case gardens:
			return "gardens";
		case mine:
			return "mines";
		case remodel:
			return "remodel";
		case smithy:
			return "smithy";
		case village:
			return "village";
		case baron:
			return "baron";
		case great_hall:
			return "great_hall";
		case minion:
			return "minion";
		case steward:
			return "steward";
		case tribute:
			return "tribute";
		case ambassador:
			return "ambassador";
		case cutpurse:
			return "cutpurse";
		case embargo:
			return "embargo";
		case outpost:
			return "outpost";
		case salvager:
			return "salvager";
		case sea_hag:
			return "sea_hag";
		case treasure_map:
			return "treasure_map";


	}


}

int main(int argc, char *argv[]){

	int seed = atoi(argv[1]);
	srand(seed);
	int winner[4];
	int numPlayer = (rand() % (4-2+1))+2;
	struct gameState g;
	int k[10];
	int j;

	chooseCard(k);

	printf("cards in play are: \n");

	for(j=0; j<10; j++){

		printf("%s\n", cardname(k[j]));

	}

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
	printf("You have this many actions: ");
	printf("%d\n", g.numActions);
	printf("You have this many buys: ");
	printf("%d\n", g.numBuys);
	printf("Number of cards in hand is: ");
	printf("%d\n", numHandCards(&g));
	
	for(i=0; i<numHandCards(&g); i++){
		
			
		
		printf("Phase : ");
		printf("%d\n", g.phase);
		if(playCard(i, 0, 0, 0, &g)!=0){
			int cardd=handCard(i, &g);
			printf("Enum of card attempting is: ");
			printf("%d\n", cardd);
			printf("Trying to play card ");
			printf("Unable to play card, error is: ");
			printf("%d\n", playCard(i,0,0,0, &g));

		}
		if(playCard(i, 0, 0, 0, &g)==0){
			printf("Playing card: ");
			printf("%s\n", cardname(handCard(i, &g)));	
			printf("You have this many actions after playing that card: ");
			printf("%d\n", g.numActions);
			printf("You have this many buys after playing that card: ");
			printf("%d\n", g.numBuys);
				
		}			

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
	if(provinceorkingdom <1){

		int p;
		for(p=0; p<10; p++){
		
			if(buyCard(p, &g)==0){

				printf("Buying card: ");
				printf("%s\n", cardname(k[p]));
				printf("Phase during buycard is: ");
				printf("%d\n", g.phase);
				
			}

		}

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
