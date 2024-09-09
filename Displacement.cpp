#include "Displacement.h"

int mPiecesInitialPosition[7][4][2] = 
{
    {
        [-2,-3],
        {-2,-3},
        {-2,-3},
        {-2,-3} // Square block

    },

    {
        {-2,-2},
        {-2,-3},
        {-2,-2},
        {-2,-3} // I block
    },

    {
        {-2,-3},
        {-2,-3},
        {-2,-3},
        {-2,-2} // L block
    },
    {
        {-2,-3},
        {-2,-2},
        {-2,-3},
        {-2,-2} // Reverse L block
    },

    {
        {-2,-3},
        {-2,-3},
        {-2,-3},
        {-2,-2} // Squiggly block
    },

    
        {
            {-2,-3},
            {-2,-3},
            {-2,-3},
            {-2,-2} // Reverse squiggly
        },
        
        {
            {-2,-3},
            {-2,-3},
            {-2,-3},
            {-2,-2} // T block
        }
    };

    std::pair<int, int> getInitialPosition(int pieceType, int rotation) {
        return { mPiecesInitialPosition[pieceType][rotation][0], mPiecesInitialPosition[pieceType][rotation][1]};
    }
