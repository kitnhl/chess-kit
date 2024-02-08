#ifndef PIECE_H
#define PIECE_H

#include "../constants.hpp"

using namespace std;

class Piece {
protected:
    Bitboard bitboard;
    PieceColor color;
    int pieceSquareTable[64];
    PieceType type;
    int value;

public:
    Piece(PieceColor color, PieceType type);

    void clearBit(int index);
    void clearBit(string squareName);
    bool getBit(int index) const;
    bool getBit(string squareName) const;
    void setBit(int index);
    void setBit(string squareName);

    Bitboard getBitboard() const;
    int* getPieceSquareTable() const;
    int getValue() const;

    virtual Bitboard getStartingPos() const;
};

#endif // PIECE_H