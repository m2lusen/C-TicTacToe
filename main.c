#include <stdio.h>

// Function prototypes
void printBoard(char board[3][3]);      // Function to print the game board
int checkWin(char board[3][3]);         // Function to check if there is a winner
int checkDraw(char board[3][3]);        // Function to check if the game is a draw
void makeMove(char board[3][3], int player); // Function to process a player's move

int main() {
    // Initialize the game board with numbers 1 to 9
    char board[3][3] = {
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
void printBoard(char board[3][3]) {

    printf("\n");
    printf("   1   2   3");
    printf("\n");
    
    char row_label = 'a'; // Initialize the row label to 'a'

    for (int i = 0; i < 3; i++) {  // Loop through each row
        printf("%c ", row_label++); // Print the row label and increment it for the next row
        for (int j = 0; j < 3; j++) {  // Loop through each column
            printf(" %c ", board[i][j]);  // Print the cell value
            if (j < 3 - 1) printf("|"); // Print column separator
        }
        printf("\n");
        if (i < 3 - 1) printf("  ---|---|---\n"); // Print row separator
    }
    printf("\n");
}

// Function to check if there is a winner
int checkWin(char board[3][3]) {
    // Check each row and column for a win
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') || (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O'))
            return 1;  // Win in a row
        if ((board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X') || (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O'))

            return 1;  // Win in a column
    }
    // Check both diagonals for a win
    if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O'))
        return 1;  // Win in the main diagonal
    if ((board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') || (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'))
        return 1;  // Win in the anti-diagonal

    return 0;  // No win
}

// Function to check if the game is a draw
int checkDraw(char board[3][3]) {
    // Loop through each cell on the board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // If any cell is not marked by 'X' or 'O', the game is not a draw
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
        }
    }
    return 1;  // All cells are marked, so it's a draw
}

// Function to process a player's move
void makeMove(char board[3][3], int player) {
    int move;  // Variable to store the player's chosen move
    char mark = (player == 1) ? 'X' : 'O';  // Determine the player's mark ('X' or 'O')
    while (1) {
        //Prompt player for move
        printf("Player %d, enter your move (e.g., 1a, 2b, etc.): ", player);
        char move[3]; // Array to store the move as a string (e.g., "1a")
        scanf("%2s", move); // Read the move as a string with maximum length 2

        // Validate the move
        if ((move[0] < '1' || move[0] > '3') || (move[1] < 'a' || move[1] > 'c')) {
            printf("Invalid move! Try again.\n");

        } else {
            // Calculate the row and column based on the move
            int col = move[0] - '0' - 1;
            int row = move[1] - 'a';
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