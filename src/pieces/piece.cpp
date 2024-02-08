#include "../../include/constants.hpp"
#include "../../include/piece_square_tables.hpp"
#include "../../include/pieces/piece.hpp"
#include <stdexcept>
#include <string>

using namespace std;

Piece::Piece(PieceColor color, PieceType type) : bitboard(0), color(color), type(type)
{
    for (int i = 0; i < NUMSQUARES; i++) 
    {
        if (color == WHITE) 
        {
            // Mirror the PST from human-readable notation for white pieces
            pieceSquareTable[i] = PIECE_SQUARE_TABLES[type][NUMSQUARES - 1 - i];
        } 
        else 
        {
            // Negate the PST from human-readable notation for black pieces
            pieceSquareTable[i] = -PIECE_SQUARE_TABLES[type][i];
        }
    }

    value = PIECE_VALUES[type] * colorMultiplier(color);
}

void Piece::clearBit(int index) 
{
    bitboard &= ~(1ULL << index);
}

void Piece::clearBit(string squareName) 
{
    clearBit(getBitboardIndex(squareName));
}

bool Piece::getBit(int index) const 
{
    return (bitboard & (1ULL << index)) != 0;
}

bool Piece::getBit(string squareName) const 
{
    return getBit(getBitboardIndex(squareName));
}

void Piece::setBit(int index) 
{
    bitboard |= (1ULL << index);
}

void Piece::setBit(string squareName) 
{
    setBit(getBitboardIndex(squareName));
}

Bitboard Piece::getBitboard() const 
{
    return bitboard;
}

int* Piece::getPieceSquareTable() const 
{
    return (int*) pieceSquareTable;
}

int Piece::getValue() const 
{
    return value;
}

Bitboard Piece::getStartingPos() const
{
    throw std::logic_error("Function getStartingPos() should be implemented in the derived class");
}
