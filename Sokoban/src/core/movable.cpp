#include <core/movable.hpp>

Movable::Movable( int x, int y )
        : Actor( x, y )
{
    //ctor
}

Movable::~Movable()
{
    //dtor
}

Movable::Movable( const Movable &other )
        : Movable( other.get_x(), other.get_y() )
{
    //copy ctor
}

Movable &Movable::operator=( const Movable &rhs )
{
    if ( this != &rhs )
    {
        Actor::operator=( rhs );
    }
    return *this;
}

void Movable::move( int dx, int dy )
{
    set_x( get_x() + dx );
    set_y( get_y() + dy );
}

std::string Movable::to_string() const
{
    return Actor::to_string();
}
