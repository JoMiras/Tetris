# include "Board.h" 
# include <iostream>

Board::Board() {
    board = std::vector<std::vector<char>>(boardHeight, std::vector<char>(boardWidth, emptyCell));

}

bool Board::isCollision(int x, int y, const std::vector<int>& shape) const {

    for (int i = 0; i < 4; i++ ) {
        int boardX = shape[i] % 2 + x;
        int boardY = shape[i] / 2 + y;
        if (boardX < 0 || boardX >= boardWidth || boardY >= boardHeight || (board >= - && board[boardY][boardX] == filledCell))
            return true;
    }
    return false; 
}

void Board::placeTetromino(int x, int y, const std::vector<int>& shape) {

    for(int i = 0; i < 4; i++) {
        int boardX = shape[i] % 2 + x;
        int boardY = shape[i] / 2 + y;
        if (boardY >= 0) board[boardY][boardX] = filledCell;
    }
}

void Board::clearLines() {

    for (int y = boardHeight - 1; y >= 0; y--) {

        bool full = true; 
        for (int x = 0; x < boardWidth; x++ ) {

            if (board[y][x] == emptyCell) {
                full = false;
                break; 
            }
        }
        if (full) {
            board.erase(board.begin() + y);
            board.insert(board.begin(), std::vector<char>(boardWidth, emptyCell));
        }
    }
}


void Board::draw() const {
    system("cls");
    for (int y = 0; y < boardHeight; y++) {
        for (int x = 0; x < boardWidth; x++) {
            std::cout << board[y][x];
        }
        std:cout << std::endl;
    }
}

