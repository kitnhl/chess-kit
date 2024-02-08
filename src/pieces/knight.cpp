#include "../../include/pieces/knight.hpp"

Knight::Knight(PieceColor color) : Piece(color, KNIGHT) 
{
    if (color == WHITE) 
    {
        // Set the first row bits for white knights
        setBit(1);  // b1
        setBit(6);  // g1  
    } 
    else 
    {
        // Set the last row bits for black knights
        setBit(57);  // b8
        setBit(62);  // g8
    }
}