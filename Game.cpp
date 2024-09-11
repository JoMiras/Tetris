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
    // Got tired, will finish tomorrow. 
}