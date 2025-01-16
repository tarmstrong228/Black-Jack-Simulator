#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

struct user {
	int winCount;
	int scoreCurrent;
	int card[21];
};



int main() {

	srand(time(NULL));

	struct user player;
	struct user dealer;
	int playerChoice = 1;

	//char card[14] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

	while (1) {
		player.scoreCurrent = 0;
		player.winCount = 0;
		dealer.scoreCurrent = 0;
		dealer.winCount = 0;
		player.card[1] = (rand() % 13);
		player.card[2] = (rand() % 13);
		dealer.card[1] = (rand() % 13);

		printf("Dealer: %d\nPlayer: %d, %d\nWill Player Hit (y) or Hold (n)?\n", dealer.card[1], player.card[1], player.card[2]); // Initial Deal
		scanf("%d", &playerChoice);

		player.scoreCurrent = player.card[1] + player.card[2];
		

		int i = 3;
		if (player.scoreCurrent < 21) {
		if (playerChoice == 1) { // Player Hitting
			printf("test\n");	
		
			//player.card[i] = (rand() % 13);
			//player.scoreCurrent += player.card[i];
			
			//printf("Dealer: %d\nPlayer: %d, %d", dealer.card[1], player.card[1], player.card[2]); 
			
			for (int j = 3; j <= i; j++) { // Print All Cards
				player.card[i] = (rand() % 13);
				player.scoreCurrent += player.card[i];
				printf(", %d", player.card[j]);
			}
			printf("\n");
			
			printf("Will Player Hit (y) or Hold (n)\n");
			scanf("%s", &playerChoice);
			i++;

		}
		}

		if (player.scoreCurrent > 21) { // Player Bust Check
			printf("Game Over: Player Busted\n");
			dealer.winCount++;
			break;
		}


		dealer.scoreCurrent = dealer.card[1];
		printf("Dealer: %d", dealer.card[1]);
		int k = 2;
		while (dealer.scoreCurrent < 17) { // Dealer Hitting
			dealer.card[k] = (rand() % 13);
			printf(", %d", dealer.card[k]);
			dealer.scoreCurrent += dealer.card[k];
			i++;
		}

		printf("\n\nDealer Score: %d\nPlayer Score: %d\n", dealer.scoreCurrent, player.scoreCurrent);

		if (dealer.scoreCurrent > 21) { // Dealer Bust Check
			printf("Dealer Busted: Player Wins\n");
			player.winCount++;
		}
		if (player.scoreCurrent > dealer.scoreCurrent) { // Player Beats Dealer
			printf("Player Wins\n");
			player.winCount++;
		}
		else { // Dealer Beats Player
			printf("Dealer Wins\n");
			dealer.winCount++;
		}

		printf("----------------------------------------\n");


	}	

	return 0;
}
