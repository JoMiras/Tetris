#ifndef _PIECES_H_
#define _PIECES_H_

class Pieces
{
public:
    int GetBlockType(int pPiece, int pRotation, int pX, int pY);
    int GetInitialPositionX(int pPiece, int pRotation);
    int GetInitialPositionY(int pPiece, int pRotation);

private:
    static const int mPieces[7 /* num of pieces */][4 /* num of rotations */][5 /* size in blocks */][5 /* size in blocks */];
};

#endif
