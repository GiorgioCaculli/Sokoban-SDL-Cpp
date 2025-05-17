#include <core/box.hpp>

#include <sstream>

Box::Box( int x, int y )
        : Movable( x, y )
{
    //ctor
}

Box::~Box()
{
    //dtor
}

Box::Box( const Box &other )
        : Box( other.get_x(), other.get_y() )
{
    //copy ctor
}

Box &Box::operator=( const Box &rhs )
{
    if ( this != &rhs )
    {
        Movable::operator=( rhs );
    }
    return *this;
}

std::string Box::to_string() const
{
    std::stringstream ss;
    ss << "Box -> " << Movable::to_string();
    return ss.str();
}
