#include "platform.hpp"

Platform::Platform( int x, int y )
: Actor( x, y )
{
    //ctor
}

Platform::~Platform()
{
    //dtor
}

Platform::Platform(const Platform& other)
: Platform( other.get_x(), other.get_y() )
{
    //copy ctor
}

Platform& Platform::operator=(const Platform& rhs)
{
    if (this != &rhs)
    {
        Actor::operator=( rhs );
    }
    return *this;
}
