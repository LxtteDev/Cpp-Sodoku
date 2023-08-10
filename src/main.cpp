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

void generateBoard(float difficulty) {
    // Create Default Board
    for (unsigned int y = 0; y < 9; y++)
        for (unsigned int x = 0; x < 9; x++)
            board[x][y] = ((x + (y % 3 * 3)) + (y - y % 3) / 3) % 9 + 1;
}

int main(int, char**){
    generateBoard(0.5f);
    showBoard();

    std::cout << std::endl << std::endl;
}
