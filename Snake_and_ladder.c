#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 100

// Function prototypes
int rollDice();
void movePlayer(int *playerPos, int diceRoll);
int checkLadder(int pos);
int checkSnake(int pos);

int main() {
    int player1Pos = 0, player2Pos = 0;
    int currentPlayer = 1;
    int diceRoll;
    
    srand(time(0)); // Seed the random number generator

    // Define ladders and snakes positions
    int ladders[BOARD_SIZE + 1] = {0};
    int snakes[BOARD_SIZE + 1] = {0};
    
    // Example ladders
    ladders[3] = 22;
    ladders[5] = 8;
    ladders[11] = 26;
    ladders[20] = 29;
    
    // Example snakes
    snakes[27] = 1;
    snakes[21] = 9;
    snakes[17] = 4;
    snakes[19] = 7;
    
    while (player1Pos < BOARD_SIZE && player2Pos < BOARD_SIZE) {
        diceRoll = rollDice();
        if (currentPlayer == 1) {
            printf("Player 1 rolls a %d\n", diceRoll);
            movePlayer(&player1Pos, diceRoll);
            if (player1Pos >= BOARD_SIZE) {
                printf("Player 1 wins!\n");
                break;
            }
            currentPlayer = 2;
        } else {
            printf("Player 2 rolls a %d\n", diceRoll);
            movePlayer(&player2Pos, diceRoll);
            if (player2Pos >= BOARD_SIZE) {
                printf("Player 2 wins!\n");
                break;
            }
            currentPlayer = 1;
        }
    }
    
    return 0;
}

int rollDice() {
    return rand() % 6 + 1;
}

void movePlayer(int *playerPos, int diceRoll) {
    *playerPos += diceRoll;
    if (*playerPos > BOARD_SIZE) {
        *playerPos = BOARD_SIZE;
    }
    *playerPos = checkLadder(*playerPos);
    *playerPos = checkSnake(*playerPos);
    printf("Player moves to position %d\n", *playerPos);
}

int checkLadder(int pos) {
    // Define ladders
    switch(pos) {
        case 3: return 22;
        case 5: return 8;
        case 11: return 26;
        case 20: return 29;
        // Add more ladders as needed
        default: return pos;
    }
}

int checkSnake(int pos) {
    // Define snakes
    switch(pos) {
        case 27: return 1;
        case 21: return 9;
        case 17: return 4;
        case 19: return 7;
        // Add more snakes as needed
        default: return pos;
    }
}


