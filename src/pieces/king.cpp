#include "../../include/pieces/king.hpp"

King::King(PieceColor color) : Piece(color) 
{
    this->color = color;
    if (color == WHITE) {
        // Set the first row bit for the white king
        setBit(4);  // e1
    } else {
        // Set the last row bit for the black king
        setBit(60);  // e8
    }
}

// King::King(PieceColor color) : Piece(color) {
//     this->pieceType = PieceType::KING;
//     this->pieceTypeString = "King";
//     this->pieceChar = 'K';
//     this->bitboardChar = 'K';
//     this->pieceValue = 0;
//     this->pieceWeight = 0;
//     this->pieceSquareTable = {
//         { 21, 21, 21, 21, 21, 21, 21, 21 },
//         { 21, 27, 27, 27, 27, 27, 27, 21 },
//         { 21, 27, 33, 33, 33, 33, 27, 21 },
//         { 21, 27, 33, 39, 39, 33, 27, 21 },
//         { 21, 27, 33, 39, 39, 33, 27, 21 },
//         { 21, 27, 33, 33, 33, 33, 27, 21 },
//         { 21, 27, 27, 27, 27, 27, 27, 21 },
//         { 21, 21, 21, 21, 21, 21, 21, 21 }
//     };
//     this->pieceSquareTableEndgame = {
//         { 21, 21, 21, 21, 21, 21, 21, 21 },
//         { 21, 27, 27, 27, 27, 27, 27, 21 },
//         { 21, 27, 33, 33, 33, 33, 27, 21 },
//         { 21, 27, 33, 39, 39, 33, 27, 21 },
//         { 21, 27, 33, 39, 39, 33, 27, 21 },
//         { 21, 27, 33, 33, 33, 33, 27, 21 },
//         { 21, 27, 27, 27, 27, 27, 27, 21 },
//         { 21, 21, 21, 21, 21, 21, 21, 21 }
//     };
//     this->initBitboard();
// }