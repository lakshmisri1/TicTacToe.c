#include <stdio.h>
#include <stdlib.h>

char board[3][3];

void initializeBoard();
void printBoard();
int checkWin();
void playerMove(char symbol);

int main() {
    int turn, result;
    char player1 = 'X', player2 = 'O';
    initializeBoard();

    for (turn = 0; turn < 9; turn++) {
        printBoard();
        if (turn % 2 == 0) {
            printf("Player 1 (X), enter your move: \n");
            playerMove(player1);
        } else {
            printf("Player 2 (O), enter your move: \n");
            playerMove(player2);
        }

        result = checkWin();
        if (result == 1) {
            printBoard();
            printf("Player %d wins!\n", (turn % 2) + 1);
            return 0;
        }
    }
    printBoard();
    printf("It's a draw!\n");
    return 0;
}

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---+---+---\n");
    }
    printf("\n");
}

void playerMove(char symbol) {
    int row, col;
    while (1) {
        printf("Enter row (0-2) and column (0-2): ");
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = symbol;
            break;
        } else {
            printf("Invalid move, try again.\n");
        }
    }
}

int checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
    return 0;
}
