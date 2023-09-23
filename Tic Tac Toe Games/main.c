#include <stdio.h>

char board[3][3]; // 3x3 game board

// Function to initialize the board
void initializeBoard() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the board
void printBoard() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) 
                printf("|");
            
        }
        printf("\n");
        if (i < 2) 
            printf("-----------\n");
        
    }
}

// Function to check if the board is full
int isBoardFull() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') 
                return 0; // Board is not full
            
        }
    }
    return 1; // Board is full
}

// Function to check if a player has won
int checkWin(char player) {
    int i;

    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) 
            return 1; // Player has won
        
    }

    // Check columns
    for (i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) 
            return 1; // Player has won
        
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1; // Player has won
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1; // Player has won
    }

    return 0; // No winner yet
}

// Function to make a move
void makeMove(char player, int row, int col) {
    board[row][col] = player;
}

int main() {
    char player = 'X';
    int row, col;
    int gameOver = 0;

    initializeBoard();

    printf("Tic-Tac-Toe\n");

    while (!gameOver) {
        printf("Player %c's turn\n", player);
        printf("Enter row (0-2): ");
        scanf("%d", &row);
        printf("Enter column (0-2): ");
        scanf("%d", &col);

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        makeMove(player, row, col);
        printBoard();

        if (checkWin(player)) {
            printf("Player %c wins!\n", player);
            gameOver = 1;
        } else if (isBoardFull()) {
            printf("It's a draw!\n");
            gameOver = 1;
        }

        player = (player == 'X') ? 'O' : 'X'; // Switch players
    }

    return 0;
}