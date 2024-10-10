# include <iostream>


bool Board::IsGameOver();
{
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        if (mBoard[i][0] == POS_FILLED) return true; 
    }    
    return false; 
}

