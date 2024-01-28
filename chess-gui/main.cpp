#include "../chess-engine/position.h"
#include "../constants.h"
#include "chess_gui.h"
#include <iostream>

using namespace std;

int main()
{
    Position pos = Position();
    
    sf::RenderWindow window(sf::VideoMode(480, 480), "Chess Kit");

    sf::Texture t1, t2;
    t1.loadFromFile("images/board.png");
    t2.loadFromFile("images/pieces.png");
    sf::Sprite cleanBoard(t1);

    for (int i = 0; i < NUMPIECES; i++)
    {
        pieces[i].setTexture(t2);
    }

    bool dragging = false;
    int active = 0;
    string notation;
    string scoreSheet = "";

    loadBoard(scoreSheet);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            // Undo previous move
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::BackSpace)
                {
                    if (scoreSheet.length())
                    {
                        scoreSheet.erase(scoreSheet.length() - 5, 5);
                        loadBoard(scoreSheet);
                    }
                }
            }
            
            // Check if a piece is clicked upon
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mouseCoord = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    for (int i = 0; i < NUMPIECES; i++)
                    {
                        if (pieces[i].getGlobalBounds().contains(mouseCoord))
                        {
                            dragging = true;
                            active = i;
                            oldCoord = pieces[i].getPosition();
                            coordOffset = mouseCoord - oldCoord;
                        }
                    }
                }
            }
            
            // Check if a piece is released
            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    dragging = false;
                    // Snap the piece to the nearest square
                    sf::Vector2f newCoord = pieces[active].getPosition();
                    newCoord.x = SQUARESIZE * round(newCoord.x / SQUARESIZE);
                    newCoord.y = SQUARESIZE * round(newCoord.y / SQUARESIZE);
                    
                    string previousMove = notation;
                    notation = toSquareName(oldCoord) + toSquareName(newCoord);
                    
                    // Only allow legal moves
                    if (pos.generatePawnMoves().find(notation) != string::npos)
                    {
                        pos.playMove(notation);
                        movePiece(active, notation);
                        scoreSheet += notation + " ";
                        cout << notation << endl;
                    }
                    else
                    {
                        pieces[active].setPosition(oldCoord);
                    }

                    // if (notation != previousMove && oldCoord != newCoord)
                    // {
                    //     scoreSheet += notation + " ";
                    //     cout << notation << endl;
                    // }

                    // movePiece(active, notation);
                }
            }
        }

        // Update the position of the piece being dragged   
        if (dragging)
        {
            pieces[active].setPosition(window.mapPixelToCoords(sf::Mouse::getPosition(window)) - coordOffset);
        }

        // Draw the board and pieces
        window.clear();
        window.draw(cleanBoard);
        for (int i = 0; i < NUMPIECES; i++)
        {
            window.draw(pieces[i]);
        }
        window.display();
    }

    return 0;
}