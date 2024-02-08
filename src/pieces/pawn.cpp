#include "../../include/constants.hpp"
#include "../../include/pieces/pawn.hpp"

Pawn::Pawn(PieceColor color) : Piece(color, PAWN) 
{
    if (color == WHITE) 
    {
        // Set the second row bits for white pawns
        for (int i = 8; i < 16; i++) 
        {
            setBit(i);
        }
    } 
    else 
    {
        // Set the seventh row bits for black pawns
        for (int i = 48; i < 56; i++) 
        {
            setBit(i);
        }
    }
    startingPos = bitboard;
}

Bitboard Pawn::getStartingPos() const {
    return startingPos;
}