/*
 * Start of a tic-tac-toe game
 * minh_p
 * 6/18/2021
*/

#include <stdio.h>
#include <conio.h>
#include "../include/BoardBuilder.h"
#include <stdbool.h>
#include "../include/WinningCheck.h"

int introduceTurn(int roundPos) {
    if (roundPos == 0 || roundPos % 2 == 0) {
        printf("Player1's turn, enter the position you want to put (O): ");
        return 1;
    } else {
        printf("Player2's turn, enter the position you want to put (O): ");
        return 2;
    }
}


bool updateBoard(int givenPosition, int playerNumber, char marks[]) {
    if (playerNumber == 1) {
        marks[givenPosition] = 'X';
    } else {
        marks[givenPosition] = 'O';
    }

    buildBoard(marks);
    // Function from ../include/WinningCheck.h
    return checkWinningCondition(marks);
}


void announceWinner(int playerNumber) {
    if (playerNumber == 1) printf("Player1 wins!\n");
    if (playerNumber == 2) printf("Player2 wins!\n");
}


void runGameLoop(char marks[]) {
    for (int roundPos = 0; roundPos < 9; roundPos++) {
        printf("This is Round#%d.\n", roundPos);

        int playerNumber = introduceTurn(roundPos);

        int givenPosition;
        int *givenPositionPointer = &givenPosition;
        scanf("%d", givenPositionPointer);

        // Handle invalid spot.
        if (!(marks[givenPosition] == ' ') || givenPosition < 0 || givenPosition > 8) {
            printf("\n\nInvalid Spot");
            buildBoard(marks);
            // restart iteration.
            roundPos--;
            continue;
        }

        bool isWinningMove = updateBoard(givenPosition, playerNumber, marks);
        if (isWinningMove) {
            announceWinner(playerNumber);
            roundPos = 8;
        }

        printf("Press any key to continue\n\n");
        getch();
    }
}


int main() {
    char marks[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    // First board setup (Function from ../include/BoardBuilder.h.
    buildBoard(marks);
    // Call game loop.
    runGameLoop(marks);
    return 0;
}
