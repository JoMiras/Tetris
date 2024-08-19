#ifndef _BOARD_
#define _BOARD_

#include "Pieces.h"

// Defines
#define BOARD_LINE_WIDTH 6 // Width of the two lines that delimit the board
#define BLOCK_SIZE 16 //Width and height of each block of a piece
#define BOARD_POSITION 320 // Center position of the board from the left of the screen
#define BOARD_WIDTH 10 // Board width in blocks
#define BOARD_HEIGHT 20 // Board height in blocks
#define MIN_VERTICAL_MARGIN 20 // Min vert margin for board limit
#define MIN_HORIZONTAL_MARGIN 20 // Min horiz margin for the board limit
#define PIECE_BLOCKS 5 // Number of horizontal and vertical blocks of a matrix piece

// Board

class Board 
{
    public:

    Board (Pieces *pPieces, int pScreenHeight); 

    int GetXPosInPixels (int pPos);
    int GetYPosInPixels (int pPos);
    bool IsFreeBlock (int pX, int pY);
    bool IsPossibleMovement (int pX, int pY, int pPiece, int pRotation);
    void  DeletePossibleLines ();
    bool IsGameOver (); 

    private:

    enum: { POS_FREE, POS_FILLED }; 
    /*POS_FREE = free position of the board;
    POS_FILLED = filled position of the board */  

    int mBoard [BOARD_WIDTH][BOARD_HEIGHT]; // Board that contains the pieces
    Pieces * mPieces;
    int mScreenHeight;

    void InitBoard();
    void DeleteLine (int pY);

};

#endif // _BOARD_ 

/*
Init the board blocks with free positions
*/

void Board::InitBoard()
{
    for (int i = 0; i < BOARD_WIDTH; i++)
    for (int j = 0; j < BOARD_HEIGHT; j++)
    mBoard[i][j] = POS_FREE;
}

/* 
pX: Horiz position in blocks
pY: Vert pos in blocks
pPiece: Piece to create / spawn
pRotation: 1 of the 4 possible rotations
*/

void Board::StorePiece (int pX, int pY, int pPiece, int pRotation)

{
    // Store each block of the piece into the board
    for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++)
    {
        for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++)
        {
            // Store only the blocks of the piece that are not holes
            if (mPieces->GetBlockType (pPiece, pRotation, j2, i2) != 0)
            mBoard[i1][j1] = POS_FILLED;
        }
    }
}

/*
Check if game is over becuase player has topped off
*/

bool Board::IsGameOver()
{
    // If the first line has blocks, then, game over
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        if (mBoard[i][0] == POS_FILLED) return true;
    }

    return false;
}

/*
Delete a line of the board and shift above layer down
*/

void Board::DeleteLine (int pY)

{
    // Shift upper lines one row down

    for (int j = pY; j > 0; j-)
    {
        for (int i = 0; i < BOARD_WIDTH; i++)
        {
            mBoard[i][j] = mBoard[i][j-1];
        }
    }
}

/*
Delete row of lines that need to be removed
*/

void Board::DeletePossibleLines ()

{
    for (int j = 0; j < BOARD_HEIGHT; j++)
    {
        int i = 0;
        while (i < BOARD_WIDTH)
        {
            if (mBoard[i][j] != POS_FILLED) break;
            i++;
        }

        if (i == BOARD_WIDTH) DeleteLine (j);
    }
}

/* 
Returns 1 (true) if the this block of the baord is empty, 0 if's filled
pX: Horiz pos in blocks
pY: Vert pos in blocks
*/

bool Board::IsFreeBlock (int pX, int pY)
{
    if (mBoard [pX][pY] == POS_FREE) return true; else return false;
}

/*
Returns the horiz pos (in pixels) of the block given like parameter
pPos: Horiz position of the block in the board
*/

int Board::GetYPosInPixels (int pPos)
{
    return ((mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT)) + (pPos * BLOCK_SIZE) );
}

/*
Check if the piece can be stored at this position without any collision
Returns true if the movement is possible, false if it not possible
pX: Horiz pos in blocks
pY: Vert pos in blocks
pPiece: Piece to draw
pRotation: 1 of the 4 possible rotations
*/

bool Board::IsPossibleMovement (int pX, int pY, int pPiece, int pRotaiton)
{
    // Checks collision with pieces already stored in the baord or the board limits
    // This is just to check the 5x5 blocks of a piece with the appropriate area in the board

    for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++)
    {
        for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++)
        {
            // Check if the piece is outside the limits of the board
            if (i1 < 0 || 
            i1 > BOARD_WIDTH - 1 ||
            j1 > BOARD_HEIGHT - 1 )
            {
                if (mPieces->GetBlockType (pPiece, pRotation, j2, i2) != 0)
                return 0; 
            }

            // Check if the piece have collisioned with a block stored in the grid

            if (j1 >= 0)
            {
                if ((mPieces->GetBlockType (pPiece, pRotation, j2, i2) != 0) && 
                (!IsFreeBlock (i1, j1)) )
                return false;
            }
        }
    }

    // No collision 
    return true;
}
