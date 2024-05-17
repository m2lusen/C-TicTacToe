#include <stdio.h>

// Define the size of the tic-tac-toe board
#define SIZE 3

// Function prototypes
void printBoard(char board[SIZE][SIZE]);      // Function to print the game board
int checkWin(char board[SIZE][SIZE]);         // Function to check if there is a winner
int checkDraw(char board[SIZE][SIZE]);        // Function to check if the game is a draw
void makeMove(char board[SIZE][SIZE], int player); // Function to process a player's move

int main() {
    // Initialize the game board with numbers 1 to 9
    char board[SIZE][SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int player = 1;  // Variable to track the current player (1 or 2)
    int win = 0;     // Variable to track if there is a win (1) or not (0)
    int draw = 0;    // Variable to track if the game is a draw (1) or not (0)

    printf("Tic-Tac-Toe Game\n");

    // Main game loop
    while (1) {
        printBoard(board);           // Print the current state of the board
        makeMove(board, player);     // Prompt the current player to make a move
        win = checkWin(board);       // Check if the current player has won
        draw = checkDraw(board);     // Check if the game is a draw

        if (win) {  // If there is a win, print the board and announce the winner
            printBoard(board);
            printf("Player %d wins!\n", player);
            break;
        } else if (draw) {  // If the game is a draw, print the board and announce the draw
            printBoard(board);
            printf("It's a draw!\n");
            break;
        }

        // Switch player: if current player is 1, switch to 2, otherwise switch to 1
        player = (player == 1) ? 2 : 1;
    }

    return 0;
}

// Function to print the current state of the game board
void printBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {  // Loop through each row
        for (int j = 0; j < SIZE; j++) {  // Loop through each column
            printf(" %c ", board[i][j]);  // Print the cell value
            if (j < SIZE - 1) printf("|"); // Print column separator
        }
        printf("\n");
        if (i < SIZE - 1) printf("---|---|---\n"); // Print row separator
    }
    printf("\n");
}

// Function to check if there is a winner
int checkWin(char board[SIZE][SIZE]) {
    // Check each row and column for a win
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;  // Win in a row
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;  // Win in a column
    }
    // Check both diagonals for a win
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;  // Win in the main diagonal
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;  // Win in the anti-diagonal

    return 0;  // No win
}

// Function to check if the game is a draw
int checkDraw(char board[SIZE][SIZE]) {
    // Loop through each cell on the board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // If any cell is not marked by 'X' or 'O', the game is not a draw
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
        }
    }
    return 1;  // All cells are marked, so it's a draw
}

// Function to process a player's move
void makeMove(char board[SIZE][SIZE], int player) {
    int move;  // Variable to store the player's chosen move
    char mark = (player == 1) ? 'X' : 'O';  // Determine the player's mark ('X' or 'O')
    while (1) {
        // Prompt the player for a move
        printf("Player %d, enter your move (1-9): ", player);
        scanf("%d", &move);
        // Validate the move
        if (move < 1 || move > 9) {
            printf("Invalid move! Try again.\n");
        } else {
            // Calculate the row and column based on the move
            int row = (move - 1) / SIZE;
            int col = (move - 1) % SIZE;
            // Check if the chosen cell is empty
            if (board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = mark;  // Mark the cell with the player's symbol
                break;
            } else {
                printf("Square already taken! Try again.\n");
            }
        }
    }
}
