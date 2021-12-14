#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include "actor.hpp"

class Platform
        : public Actor
{
public:
    Platform( int x, int y );
    virtual ~Platform();
    Platform( const Platform &other );
    Platform &operator=( const Platform &other );
    std::string to_string() const override;

protected:

private:
};

#endif // PLATFORM_HPP
