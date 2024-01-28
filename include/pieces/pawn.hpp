#ifndef PAWN_H
#define PAWN_H

#include "../constants.hpp"
#include "piece.hpp"

class Pawn : public Piece {
private:
    Bitboard startingPos;

public:
    Pawn(PieceColor color);

    Bitboard getStartingPos() const override;
};

#endif // PAWN_H