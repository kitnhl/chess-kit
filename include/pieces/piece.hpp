#ifndef PIECE_H
#define PIECE_H

#include "../constants.hpp"

using namespace std;

class Piece {
protected:
    Bitboard bitboard;
    PieceColor color;

public:
    Piece(PieceColor color);

    void clearBit(int index);
    void clearBit(string squareName);
    bool getBit(int index) const;
    bool getBit(string squareName) const;
    void setBit(int index);
    void setBit(string squareName);

    Bitboard getBitboard() const;

    virtual Bitboard getStartingPos() const;
};

#endif // PIECE_H