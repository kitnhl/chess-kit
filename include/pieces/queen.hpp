#ifndef QUEEN_H
#define QUEEN_H

#include "../constants.hpp"
#include "piece.hpp"

class Queen : public Piece {
public:
    Queen(PieceColor color);
};

#endif // QUEEN_H