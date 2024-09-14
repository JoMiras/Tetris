#include "Game.h"
#include "Board.h"
#include "Pieces.h"
#include "Displacement.h"
#include <conio.h> 
#include <cstdlib>
#include <ctime>

Game::Game() {
    srand(time(0));
    board = new Board();
    spawnNewPiece();
    gameOver = false;
}

void Game::spawnNewPiece() {
    currentPieceType = rand() % 7; //Picks a random piece from 0 and 6
    currentRotation = 0;
    std::pair<int, int> getInitialPosition = getInitialPosition(currentPieceType, currentRotation);
    currentX = initialPosition.first;
    currentY = initialPosition.second;

    if (board->isCollision(currentX, currentY, Pieces::getPieceShape(currentPieceType, currentRotation))) {
        gameOver = true;
    }
}

void Game::rotatePiece() {
    int newRotation = (currentRotation + 1) % 4; 
    if ( !board-> isCollision(currentX, currentY, Pieces::getPieceShape( currentPieceType, newRoation))) {
        currentRotation = newRotation;
    }
}

void Game::movePiece(int dx) {
    if (!board-> isCollison(currentX + dx, currentY, Pieces::getPieceShape(currentPieceType, currentRotation))) {
        current += dx;
    }
}

void Game::dropPiece() {
    if (!board->isCollision(currentX, currentY + 1, Pieces:: getPieceShape(currentPieceType, currentRotation))) {
        currentY++;
    } else {
        board->placeTetromino(currentX, currentY, Pieces::getPieceShape(currentPieceType, currentRotation));
        board->clearLines();
        spawnNewPiece(); 
    }
}

void Game::run() {
    while (!gameOver) {
        board->draw();

        if(_kbhit()) {
            char key = _getch();
            switch (key) {
                case 'a': movePiece(-1); break;
                case 'd': movePiece(1); break;
                case 's': dropPiece(); break;
                case 'w': rotatePiece(); break;
            }
        }
        dropPiece():
        _sleep(500);
    }
    system ("cls");
    std::cout <<"Game Over!" << std::endl; 
}
Game::~Game() {
    delete board;
}

