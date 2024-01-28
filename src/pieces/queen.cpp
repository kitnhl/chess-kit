#include "../../include/pieces/queen.hpp"

Queen::Queen(PieceColor color) : Piece(color) 
{
    this->color = color;
    if (color == WHITE) {
        // Set the first row bit for the white queen
        setBit(3);  // d1
    } else {
        // Set the last row bit for the black queen
        setBit(59);  // d8
    }
}

// Queen::Queen(PieceColor color) : Bitboard(color) {
//     this->pieceType = QUEEN;
//     this->pieceTypeString = "Queen";
//     this->pieceValue = 900;
//     this->pieceWeight = 9;
//     this->pieceSquareTable = {
//         { -21, -21, -21, -21, -21, -21, -21, -21 },
//         { -21,  9,  9,  9,  9,  9,  9, -21 },
//         { -21,  9, 27, 27, 27, 27,  9, -21 },
//         { -21,  9, 27, 39, 39, 27,  9, -21 },
//         { -21,  9, 27, 39, 39, 27,  9, -21 },
//         { -21,  9, 27, 27, 27, 27,  9, -21 },
//         { -21,  9,  9,  9,  9,  9,  9, -21 },
//         { -21, -21, -21, -21, -21, -21, -21, -21 }
//     };
//     this->pieceSquareTableEndgame = {
//         { -21, -21, -21, -21, -21, -21, -21, -21 },
//         { -21,  9,  9,  9,  9,  9,  9, -21 },
//         { -21,  9, 27, 27, 27, 27,  9, -21 },
//         { -21,  9, 27, 39, 39, 27,  9, -21 },
//         { -21,  9, 27, 39, 39, 27,  9, -21 },
//         { -21,  9, 27, 27, 27, 27,  9, -21 },
//         { -21,  9,  9,  9,  9,  9,  9, -21 },
//         { -21, -21, -21, -21, -21, -21, -21, -21 }
//     };
//     this->initBitboard();
// }