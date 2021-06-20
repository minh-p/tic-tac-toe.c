/*
 * Start of a tic-tac-toe game
 * minh_p
 * 6/18/2021
*/

#include <stdio.h>
#include "../include/BoardBuilder.h"
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void introduceTurn(int roundPos) {
    if (roundPos == 0) {
        printf("Player1's turn:");
        return;
    }

    if (roundPos % 2 == 0) {
        printf("Player2's turn: ");
    } else {
        printf("Player1's turn: ");
    }
}

void runGameLoop(char marks[]) {
    for (int roundPos = 0; roundPos < 9; roundPos++) {
        introduceTurn(roundPos);
    }
}

int main() {
    char marks[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    // First board setup.
    buildBoard(marks);
    // Call game loop.
    runGameLoop(marks);
    return 0;
}
