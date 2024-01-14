#pragma once

const int BOARDSIZE = 480;
const int NUMPIECES = 32;
const int SQUARESIZE = BOARDSIZE / 8;
// const int PIECESIZE = SQUARESIZE - 10;

const int INITPOS[8][8] = {
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

enum PieceType {
    QUEEN = 0,
    KING = 1,
    ROOK = 2,
    KNIGHT = 3,
    BISHOP = 4,
    PAWN = 5
};

enum PieceColor {
    BLACK = 0,
    WHITE = 1
};

inline PieceType getPieceType(int boardValue) {
    return static_cast<PieceType>(abs(boardValue) - 1);
}

inline PieceColor getPieceColor(int boardValue) {
    return boardValue > 0 ? WHITE : BLACK;
}