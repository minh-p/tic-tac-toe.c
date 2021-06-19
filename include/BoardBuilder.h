// Contains functions to make a tic-tac-toe board.
// minh_p
// 6/18/2021

#include <stdio.h>

void buildBoard(char marks[]) {
    // Make some space
    printf("\n");

    for (int index = 0; index < 9; index += 3) {
        if (index % 3 == 0 && index != 0) printf("\t----|----|----\n");
        printf("\t %c  | %c  | %c\n", marks[index], marks[index + 1], marks[index + 2]);
    }
}
