// Tic-tac-toe: Check if someone have won.
// minh_p
// 6/20/2021

#include <stdbool.h>

bool _checkRow(char symbol, int firstIndexOfRow, char marks[]) {
    if (marks[firstIndexOfRow] == symbol && marks[firstIndexOfRow+1] == symbol && marks[firstIndexOfRow+2] == symbol) {
        return true;
    }
    return false;
}


bool _checkCollumn(char symbol, int headIndexOfCollumn, char marks[]) {
    if (marks[headIndexOfCollumn] == symbol && marks[headIndexOfCollumn+3] == symbol && marks[headIndexOfCollumn+6] == symbol) {
        return true;
    }
    return false;
}


bool checkWinningCondition(char marks[]) {
    // Check rows
    for (int i = 0; i < 9; i = i + 3) {
        if (_checkRow('X', i, marks) || _checkRow('O', i, marks)) {
            return true;
        }
    }

    // Check collumns
    for (int j = 0; j < 3; j++) {
        if (_checkCollumn('X', j, marks) || _checkCollumn('O', j, marks)) {
            return true;
        }
    }

    return false;
}
