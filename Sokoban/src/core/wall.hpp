#ifndef WALL_HPP
#define WALL_HPP

#include "actor.hpp"

class Wall
        : public Actor
{
public:
    Wall( int x, int y );
    virtual ~Wall();
    Wall( const Wall &other );
    Wall &operator=( const Wall &other );
    std::string to_string() const override;

protected:

private:
};

#endif // WALL_HPP
