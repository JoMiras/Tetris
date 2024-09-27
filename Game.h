#ifndef GAME_H
#define GAME_H 

#include "Board.h"
#include "Pieces.h"
#include <utility>

class Game {
    public: 
    Game();
    ~Game();

    void run();

private: 
        void processInput(); // Handle user input
        void update();       // Update game state (move piece, check for collisions, etc.)
        void render();       // Render the game board
        void spawnPiece();   // Generate and place a new piece on the board

        bool isGameOver();   // Check if the game is over
        void reset();        // Reset the game state

        Board board;         // Game board
        Pieces currentPiece; // Current active piece
        Pieces nextPiece;    // Next piece to be spawned

        std::pair<int, int> piecePosition; // The position of the current piece on the board

        bool gameOver;       // Flag to indicate if the game is over
        int score;           // Keep track of the player's score
        int level;           // Game level for difficulty adjustment
        int linesCleared;    // Number of lines cleared
};

#endif
