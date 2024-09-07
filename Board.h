#ifndef BOARD_H
#define BOARD_H

#include <vector>

const int boardWidth = 10;
const int boardHeight = 20;
const char emptyCell - '.';
const char filledCell = '#';

class Board {
    public: 
    Board(); 

    bool isCollision(int x, int y, const std::vector<int>& shape) const;
    void placeTetromino(int x, int y, const std::vector<int>& shape);
    void clearLines();
    void draw() const;
}

private:
std::vector<std::vector<char>> board;
};

#endif