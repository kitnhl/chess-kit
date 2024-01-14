#include "chess_gui.h"
#include "constants.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(480, 480), "Chess Kit");

    sf::Texture t1, t2;
    t1.loadFromFile("images/board.png");
    t2.loadFromFile("images/pieces.png");
    sf::Sprite cleanBoard(t1);

    for (int i = 0; i < NUMPIECES; i++)
    {
        pieces[i].setTexture(t2);
    }
    loadPosition();

    bool dragging = false;
    sf::Vector2f oldPos;
    int active = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            
            // Check if a piece is clicked upon
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    for (int i = 0; i < NUMPIECES; i++)
                    {
                        if (pieces[i].getGlobalBounds().contains(mousePos))
                        {
                            dragging = true;
                            active = i;
                            oldPos = mousePos - pieces[i].getPosition();
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
                }
            }
        }

        // Update the position of the piece being dragged   
        if (dragging)
        {
            pieces[active].setPosition(window.mapPixelToCoords(sf::Mouse::getPosition(window)) - oldPos);
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