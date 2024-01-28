#pragma once
#include <SFML/Graphics.hpp>

using namespace std;

extern sf::Sprite pieces[32];
extern sf::Vector2f coordOffset, oldCoord, newCoord;

void loadBoard(string scoreSheet);
void movePiece(int index, string notation);

sf::Vector2f toCoord(string squareName);
string toSquareName(sf::Vector2f coord);