#include <iostream>

int board[9][9]; // X, Y

void showBoard() {
    for (unsigned int y = 0; y < 9; y++) {
        if ((y) % 3 == 0 && y != 0) std::cout << std::endl << "-------|-------|-------";
        for (unsigned int x = 0; x < 9; x++) {
            if ((x) % 3 == 0 && x != 0) std::cout << " |";
            if (x == 0) std::cout << std::endl;
            std::cout << " " << board[x][y]; 
        }
    }
}

void copyArray(int *dest, int source[3]) {
    for (unsigned int i = 0; i < 9; i++)
        dest[i] = source[i];
}

void copyArrayColumn(int (*dest)[9], int source[9], int column) {
    for (unsigned int i = 0; i < 9; i++)
        dest[column][i] = source[i];
}

void copyArrayColumn(int** dest, int source[9], int column) {
    for (unsigned int i = 0; i < 9; i++)
        dest[column][i] = source[i];
}


int** invertArray(int array[9][9]) {
    int** newArray;
    newArray = new int*[9];

    for(int i = 0; i < 9; i++)
        newArray[i] = new int[9];

    for (unsigned int y = 0; y < 9; y++)
        for (unsigned int x = 0; x < 9; x++)
            newArray[y][x] = array[x][y];

    return newArray;
}

void generateBoard(unsigned int seed, float difficulty) {
    // Create Default Board
    for (unsigned int y = 0; y < 9; y++)
        for (unsigned int x = 0; x < 9; x++)
            board[x][y] = ((x + (y % 3 * 3)) + (y - y % 3) / 3) % 9 + 1;
            // board[x][y] = y + 1; // Board Shuffling Test

    // Shuffle Columns
    for (unsigned int column = 0; column < 9; column++) {
        int shuffle = 9 * (rand() / (RAND_MAX + 1.0));
        if (shuffle == 0) continue;

        int buffer[9];
        copyArray(buffer, board[(column + shuffle) % 9]);
        copyArrayColumn(board, board[column], (column + shuffle) % 9);
        copyArrayColumn(board, buffer, column);
    }

    // Shuffle Rows
    int** newBoard = invertArray(board);

    for (unsigned int row = 0; row < 9; row++) {
        int shuffle = 9 * (rand() / (RAND_MAX + 1.0));
        if (shuffle == 0) continue;

        int buffer[9];
        copyArray(buffer, newBoard[(row + shuffle) % 9]);
        copyArrayColumn(newBoard, newBoard[row], (row + shuffle) % 9);
        copyArrayColumn(newBoard, buffer, row);
    }
    
    for (unsigned int y = 0; y < 9; y++)
        for (unsigned int x = 0; x < 9; x++)
            board[y][x] = newBoard[x][y];
}

int main(int, char**){
    generateBoard(18401, 0.5f);
    showBoard();

    std::cout << std::endl << std::endl;
}
