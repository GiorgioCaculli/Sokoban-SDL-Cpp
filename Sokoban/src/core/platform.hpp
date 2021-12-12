#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include "actor.hpp"


class Platform
: public Actor
{
    public:
        Platform( int x, int y );
        virtual ~Platform();
        Platform(const Platform& other);
        Platform& operator=(const Platform& other);

    protected:

    private:
};

#endif // PLATFORM_HPP
