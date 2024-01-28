#include "../../include/pieces/piece.hpp"
#include <stdexcept>
#include <string>

using namespace std;

Piece::Piece(PieceColor color) : bitboard(0), color(color) {}

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

Bitboard Piece::getStartingPos() const
{
    throw std::logic_error("Function getStartingPos() should be implemented in the derived class");
}
