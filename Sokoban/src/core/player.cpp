#include "player.hpp"

Player::Player( int x, int y )
: Movable( x, y )
{
    //ctor
}

Player::~Player()
{
    //dtor
}

Player::Player(const Player& other)
: Player( other.get_x(), other.get_y() )
{
    //copy ctor
}

Player& Player::operator=(const Player& rhs)
{
    if (this != &rhs)
    {
        Movable::operator=( rhs );
    }
    return *this;
}
