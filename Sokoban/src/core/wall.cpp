#include "wall.hpp"

#include <sstream>

Wall::Wall( int x, int y )
        : Actor( x, y )
{
    //ctor
}

Wall::~Wall()
{
    //dtor
}

Wall::Wall( const Wall &other )
        : Wall( other.get_x(), other.get_y() )
{
    //copy ctor
}

Wall &Wall::operator=( const Wall &rhs )
{
    if ( this != &rhs )
    {
        Actor::operator=( rhs );
    }
    return *this;
}

std::string Wall::to_string() const
{
    std::stringstream ss;
    ss << "Wall -> " << Actor::to_string();
    return ss.str();
}
