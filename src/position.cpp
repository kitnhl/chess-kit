#include "../include/constants.hpp"
#include "../include/pieces/bishop.hpp"
#include "../include/pieces/king.hpp"
#include "../include/pieces/knight.hpp"
#include "../include/pieces/pawn.hpp"
#include "../include/pieces/queen.hpp"
#include "../include/pieces/rook.hpp"
#include "../include/position.hpp"
#include <bitset>
#include <iostream>
#include <string>

using namespace std;

Position::Position() :
    pawns {Pawn(BLACK), Pawn(WHITE)},
    knights {Knight(BLACK), Knight(WHITE)},
    bishops {Bishop(BLACK), Bishop(WHITE)},
    rooks {Rook(BLACK), Rook(WHITE)},
    queens {Queen(BLACK), Queen(WHITE)},
    kings {King(BLACK), King(WHITE)},
    pieces {
        &pawns[BLACK], &pawns[WHITE],
        &knights[BLACK], &knights[WHITE],
        &bishops[BLACK], &bishops[WHITE],
        &rooks[BLACK], &rooks[WHITE],
        &queens[BLACK], &queens[WHITE],
        &kings[BLACK], &kings[WHITE]
    },
    turn(WHITE) 
    {
    // Any additional initialization goes here
    }

Position::Position(const Position& other) :
    pawns {other.pawns[BLACK], other.pawns[WHITE]},
    knights {other.knights[BLACK], other.knights[WHITE]},
    bishops {other.bishops[BLACK], other.bishops[WHITE]},
    rooks {other.rooks[BLACK], other.rooks[WHITE]},
    queens {other.queens[BLACK], other.queens[WHITE]},
    kings {other.kings[BLACK], other.kings[WHITE]},
    pieces {
        &pawns[BLACK], &pawns[WHITE],
        &knights[BLACK], &knights[WHITE],
        &bishops[BLACK], &bishops[WHITE],
        &rooks[BLACK], &rooks[WHITE],
        &queens[BLACK], &queens[WHITE],
        &kings[BLACK], &kings[WHITE]
    },
    turn(other.turn) 
    {
    // Any additional initialization goes here
    }

int Position::evaluate() 
{
    int eval = 0;

    for (int i = 0; i < NUMPIECETYPES * 2; i++) {
        int pieceValue = pieces[i]->getValue();
        int *pieceSquareTable = pieces[i]->getPieceSquareTable();

        for (int j = 0; j < NUMSQUARES; j++) 
        {
            if (pieces[i]->getBit(j)) 
            {
                eval += pieceValue + pieceSquareTable[j];
            }
        }
    }

    return eval;
}

string Position::findBestMove()
{
    int maxEval = INT_MIN, alpha = INT_MIN, beta = INT_MAX;
    string moves = generatePawnMoves();
    string bestMove = moves.length() ? moves.substr(0, NOTATIONLENGTH) : "";
    for (size_t i = 0; i < moves.length(); i += NOTATIONLENGTH + 1) 
    {
        std::unique_ptr<Position> childPos(new Position(*this));
        childPos->playMove(moves.substr(i, NOTATIONLENGTH));
        int childEval = -childPos->_negamax(MAXSEARCHDEPTH - 1, -beta, -alpha);
        if (childEval > maxEval) 
        {
            maxEval = childEval;
            bestMove = moves.substr(i, NOTATIONLENGTH);
        }
        alpha = max(alpha, maxEval);
        if (alpha >= beta) 
        {
            break;
        }
    }

    return bestMove;
}

string Position::generatePawnMoves()
{
    string moves;

    Bitboard occupancy = pawns[BLACK].getBitboard() | pawns[WHITE].getBitboard();
    // Piece* pieces[] = {&bishops[0], &bishops[1], &kings[0], &kings[1], &knights[0], &knights[1], &pieces[0], &pieces[1], &queens[0], &queens[1], &rooks[0], &rooks[1]};
    // for (int i = 0; i < 12; i++) {
    //     occupancy |= pieces[i]->getBitboard();
    // }
    // for (int i = 0; i < 12; i++) {
    //     occupancy |= *(&(pawns[0].getBitboard()) + i);
    // }

    if (turn == WHITE) 
    {
        // Generate white pawn moves
        Bitboard singlePush = pawns[WHITE].getBitboard() << NUMCOLS;
        singlePush ^= singlePush & occupancy;

        Bitboard doublePush = (pawns[WHITE].getBitboard() & pawns[WHITE].getStartingPos()) << (NUMCOLS * 2);
        doublePush ^= doublePush & occupancy;

        // Ensure that the double push is not jumping over a piece
        doublePush = doublePush >> NUMCOLS;
        doublePush &= singlePush;
        doublePush = doublePush << NUMCOLS;

        for (int i = 0; i < NUMSQUARES; i++) {
            if (getBit(singlePush, i)) {
                moves += string(SQUARE_NAMES[i - NUMCOLS]) + string(SQUARE_NAMES[i]) + " ";
            }
            if (getBit(doublePush, i)) {
                moves += string(SQUARE_NAMES[i - NUMCOLS * 2]) + string(SQUARE_NAMES[i]) + " ";
            }
        }
    } 
    else 
    {
        // Generate black pawn moves
        Bitboard singlePush = pawns[BLACK].getBitboard() >> NUMCOLS;
        singlePush ^= singlePush & occupancy;

        Bitboard doublePush = (pawns[BLACK].getBitboard() & pawns[BLACK].getStartingPos()) >> (NUMCOLS * 2);
        doublePush ^= doublePush & occupancy;
        
        // Ensure that the double push is not jumping over a piece
        doublePush = doublePush << NUMCOLS;
        doublePush &= singlePush;
        doublePush = doublePush >> NUMCOLS;

        for (int i = 0; i < NUMSQUARES; i++) {
            if (getBit(singlePush, i)) 
            {
                moves += string(SQUARE_NAMES[i + NUMCOLS]) + string(SQUARE_NAMES[i]) + " ";
            }
            if (getBit(doublePush, i)) 
            {
                moves += string(SQUARE_NAMES[i + NUMCOLS * 2]) + string(SQUARE_NAMES[i]) + " ";
            }
        }
    }

    return moves;
}

void Position::playMove(string notation) 
{
    for (int i = 0; i < NUMPIECETYPES * 2; i++) {
        // Move desired piece
        if (pieces[i]->getBit(notation.substr(0, 2))) 
        {
            pieces[i]->clearBit(notation.substr(0, 2));
            pieces[i]->setBit(notation.substr(2, 2));
        } 
        // Remove captured piece
        else if (pieces[i]->getBit(notation.substr(2, 2))) 
        {
            pieces[i]->clearBit(notation.substr(2, 2));
        }
    }

    turn = (turn == WHITE) ? BLACK : WHITE;
}

int Position::_negamax(int depth, int alpha, int beta) 
{
    if (depth == 0) 
    {
        return evaluate() * colorMultiplier(turn);
    }

    int maxEval = INT_MIN;
    string moves = generatePawnMoves();
    for (size_t i = 0; i < moves.length(); i += NOTATIONLENGTH + 1) 
    {
        std::unique_ptr<Position> childPos(new Position(*this));
        childPos->playMove(moves.substr(i, NOTATIONLENGTH));

        maxEval = max(maxEval, -childPos->_negamax(depth - 1, -beta, -alpha));
        alpha = max(alpha, maxEval);
        if (alpha >= beta) 
        {
            break;
        }
    }

    return maxEval;
}