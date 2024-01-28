#pragma once

#include <cstdlib>
#include <string>

using namespace std;

typedef uint64_t Bitboard;

const int BOARDSIZE = 480;
const int NUMCOLS = 8;
const int NUMPIECES = 32;
const int NUMPIECETYPES = 6;
const int NUMROWS = NUMCOLS;
const int OUTOFBOUNDS = -100;
const int SQUARESIZE = BOARDSIZE / NUMROWS;

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

const char SQUARE_NAMES[64][3] = {
    "a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1",
    "a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2",
    "a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3",
    "a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4",
    "a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5",
    "a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6",
    "a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7",
    "a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8"
};

enum PieceColor {
    BLACK = 0,
    WHITE = 1
};

enum PieceType {
    QUEEN = 0,
    KING = 1,
    ROOK = 2,
    KNIGHT = 3,
    BISHOP = 4,
    PAWN = 5
};

inline bool getBit(Bitboard bitboard, int index) {
    return (bitboard & (1ULL << index)) != 0;
}

inline int getBitboardIndex(string squareName) {
    int file = squareName[0] - 'a'; 
    int rank = squareName[1] - '1';

    return rank * 8 + file;
}

inline PieceColor getPieceColor(int boardValue) {
    return boardValue > 0 ? WHITE : BLACK;
}

inline int getPieceIndex(PieceColor color, PieceType type) {
    return type * 2 + color;
}

inline PieceType getPieceType(int boardValue) {
    return static_cast<PieceType>(abs(boardValue) - 1);
}

