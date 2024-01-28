#ifndef KING_H
#define KING_H

#include "../constants.hpp"
#include "piece.hpp"

class King : public Piece {
public:
    King(PieceColor color);
};

#endif // KING_H