#include "actor.hpp"

Actor::Actor( int x, int y )
: _x( x )
, _y( y )
{
}

Actor::~Actor()
{
}

Actor::Actor( const Actor& other )
: Actor( other._x, other._y )
{
}

Actor& Actor::operator=( const Actor& rhs )
{
    if (this != &rhs)
    {
        _x = rhs._x;
        _y = rhs._y;
    }
    return *this;
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
