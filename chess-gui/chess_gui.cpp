#include "chess_gui.h"
#include "constants.h"

using namespace std;

sf::Sprite pieces[32];
sf::Vector2f coordOffset, oldCoord, newCoord;

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

void movePiece(int index, string notation)
{
    oldCoord = toCoord(notation.substr(0, 2));
    newCoord = toCoord(notation.substr(2, 2));
    // Captured piece must be removed before the capturing piece takes its place
    for (int j = 0; j < NUMPIECES; j++)
    {
        if (pieces[j].getPosition() == newCoord)
        {
            pieces[j].setPosition(-100, -100);
        }
    }

    pieces[index].setPosition(newCoord);
}

sf::Vector2f toCoord(string squareName)
{
    int x = static_cast<int>(squareName[0] - 'a');
    int y = 7 - static_cast<int>(squareName[1] - '1');
    return sf::Vector2f(x * SQUARESIZE, y * SQUARESIZE);
}

string toSquareName(sf::Vector2f coord)
{
    string name = "";
    name += static_cast<char>('a' + static_cast<int>(coord.x / SQUARESIZE));
    name += static_cast<char>('8' - static_cast<int>(coord.y / SQUARESIZE));
    return name;
}