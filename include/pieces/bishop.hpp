#ifndef BISHOP_H
#define BISHOP_H

#include "../constants.hpp"
#include "piece.hpp"

class Bishop : public Piece {
public:
    Bishop(PieceColor color);
};

#endif // BISHOP_H