#include "chess_gui.h"
#include "constants.h"

sf::Sprite pieces[32];

void loadPosition()
{
    int k = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (INITPOS[i][j] == 0)
            {
                continue;
            }

            int n = INITPOS[i][j];
            PieceType x = getPieceType(n);
            PieceColor y = getPieceColor(n);
            pieces[k].setTextureRect(sf::IntRect(SQUARESIZE * static_cast<int>(x), SQUARESIZE * static_cast<int>(y), 
                                                 SQUARESIZE, SQUARESIZE));
            pieces[k].setPosition(SQUARESIZE * j, SQUARESIZE * i);
            k++;
        }
    }
}