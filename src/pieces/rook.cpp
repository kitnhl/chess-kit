#include "../../include/pieces/rook.hpp"

Rook::Rook(PieceColor color) : Piece(color) 
{
    this->color = color;
    if (color == WHITE) {
        // Set the first row bits for the white rooks
        setBit(0);  // a1
        setBit(7);  // h1
    } else {
        // Set the last row bits for the black rooks
        setBit(56);  // a8
        setBit(63);  // h8
    }
}