#include "box.hpp"

Box::Box( int x, int y )
: Movable( x, y )
{
    //ctor
}

Box::~Box()
{
    //dtor
}

Box::Box(const Box& other)
: Box( other.get_x(), other.get_y() )
{
    //copy ctor
}

Box& Box::operator=(const Box& rhs)
{
    if (this != &rhs)
    {
        Movable::operator=( rhs );
    }
    return *this;
}
