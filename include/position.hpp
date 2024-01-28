#ifndef POSITION_H
#define POSITION_H

#include "pieces/bishop.hpp"
#include "pieces/king.hpp"
#include "pieces/knight.hpp"
#include "pieces/pawn.hpp"
#include "pieces/queen.hpp"
#include "pieces/rook.hpp"
#include <string>

using namespace std;

class Position {
private:
    Queen queens[2];
    King kings[2];
    Rook rooks[2];
    Knight knights[2];
    Bishop bishops[2];
    Pawn pawns[2];
    
    Piece* pieces[12];
    PieceColor turn;  

public:
    Position();

    // Add methods to manipulate and query the position here
    string generatePawnMoves();
    void playMove(string notation);
};

#endif // POSITION_H