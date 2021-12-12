#include "board.hpp"

Board::Board()
{
    //ctor
}

Board::~Board()
{
    //dtor
}

Board::Board(const Board& other)
: Board()
{
    //copy ctor
}

Board& Board::operator=(const Board& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
