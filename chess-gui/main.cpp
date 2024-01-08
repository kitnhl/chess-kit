#include <SFML/Graphics.hpp>

const int BOARDSIZE = 480;
const int NUMPIECES = 32;
const int SQUARESIZE = BOARDSIZE / 8;

// const int PIECESIZE = SQUARESIZE - 10;

sf::Sprite pieces[32];

int board[8][8] = {
    // Black pieces
    {-3, -4, -5, -1, -2, -5, -4, -3}, 
    {-6, -6, -6, -6, -6, -6, -6, -6}, 
    // Empty squares
    { 0,  0,  0,  0,  0,  0,  0,  0}, 
    { 0,  0,  0,  0,  0,  0,  0,  0}, 
    { 0,  0,  0,  0,  0,  0,  0,  0}, 
    { 0,  0,  0,  0,  0,  0,  0,  0}, 
    // White pieces
    { 6,  6,  6,  6,  6,  6,  6,  6},
    { 3,  4,  5,  1,  2,  5,  4,  3}
};

void loadPosition();

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

void loadPosition()
{
    int k = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == 0)
            {
                continue;
            }

            int n = board[i][j];
            int x = abs(n) - 1;     // 0 = queen, 1 = king, 2 = rook, 3 = knight, 4 = bishop, 5 = pawn
            int y = n > 0 ? 1 : 0;  // 0 = black, 1 = white
            pieces[k].setTextureRect(sf::IntRect(SQUARESIZE * x, SQUARESIZE * y, SQUARESIZE, SQUARESIZE));
            pieces[k].setPosition(SQUARESIZE * j, SQUARESIZE * i);
            k++;
        }
    }
}