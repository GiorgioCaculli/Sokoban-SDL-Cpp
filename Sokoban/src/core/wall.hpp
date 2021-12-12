#ifndef WALL_HPP
#define WALL_HPP

#include "actor.hpp"


class Wall
: public Actor
{
    public:
        Wall( int x, int y );
        virtual ~Wall();
        Wall(const Wall& other);
        Wall& operator=(const Wall& other);

    protected:

    private:
};

#endif // WALL_HPP
