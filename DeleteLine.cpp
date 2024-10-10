# include <iostream>

void Board::DeleteLine (int pY)

{
    for (int j = pY; > 0; j-)
    {
        for (int i = 0; i < BOARD_WIDTH; i++)
        {
            mBoard[i][j] = mBoard[i][j-1];
        }
    }
}
