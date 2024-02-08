#include "../../include/pieces/bishop.hpp"

Bishop::Bishop(PieceColor color) : Piece(color, BISHOP) 
{
    if (color == WHITE) 
    {
        // Set the first row bits for the white bishops
        setBit(2);  // c1
        setBit(5);  // f1
    } 
    else 
    {
        // Set the last row bits for the black bishops
        setBit(58);  // c8
        setBit(61);  // f8
    }
}

// Bishop::Bishop(PieceColor color) : Piece(color) {
//     this->pieceType = PieceSpriteType::BISHOP_SPRITE;
//     this->pieceTypeString = "Bishop";
//     this->pieceValue = 3;
//     this->pieceWeight = 300;
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