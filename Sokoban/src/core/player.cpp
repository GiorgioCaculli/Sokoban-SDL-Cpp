#include <core/player.hpp>

#include <sstream>

Player::Player( int x, int y )
        : Movable( x, y )
{
    //ctor
}

Player::~Player()
{
    //dtor
}

Player::Player( const Player &other )
        : Player( other.get_x(), other.get_y() )
{
    //copy ctor
}

Player &Player::operator=( const Player &rhs )
{
    if ( this != &rhs )
    {
        Movable::operator=( rhs );
    }
    return *this;
}

std::string Player::to_string() const
{
    std::stringstream ss;
    ss << "Player -> " << Movable::to_string();
    return ss.str();
}
