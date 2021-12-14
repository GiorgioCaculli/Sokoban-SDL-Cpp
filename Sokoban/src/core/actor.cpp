#include "actor.hpp"

#include <sstream>

namespace
{
    int SPACE = 1;
}

Actor::Actor( int x, int y )
        : _x( x )
          , _y( y )
{
}

Actor::~Actor()
{
}

Actor::Actor( const Actor &other )
        : Actor( other._x, other._y )
{
}

Actor &Actor::operator=( const Actor &rhs )
{
    if ( this != &rhs )
    {
        _x = rhs._x;
        _y = rhs._y;
    }
    return *this;
}

bool Actor::is_left_collision( const Actor *actor ) const
{
    return _x - SPACE == actor->_x && _y == actor->_y;
}

bool Actor::is_right_collision( const Actor *actor ) const
{
    return _x + SPACE == actor->_x && _y == actor->_y;
}

bool Actor::is_top_collision( const Actor *actor ) const
{
    return _x == actor->_x && _y - SPACE == actor->_y;
}

bool Actor::is_bottom_collision( const Actor *actor ) const
{
    return _x == actor->_x && _y + SPACE == actor->_y;
}

int Actor::get_x() const
{
    return _x;
}

void Actor::set_x( int x )
{
    _x = x;
}

int Actor::get_y() const
{
    return _y;
}

void Actor::set_y( int y )
{
    _y = y;
}

std::string Actor::to_string() const
{
    std::stringstream ss;
    ss << "X: " << std::to_string( _x ) << " Y: " << std::to_string( _y );
    return ss.str();
}
