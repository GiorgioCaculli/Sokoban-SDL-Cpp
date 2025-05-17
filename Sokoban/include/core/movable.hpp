#ifndef MOVABLE_HPP
#define MOVABLE_HPP

#include "actor.hpp"

class Movable
        : public Actor
{
public:
    Movable( int x, int y );
    ~Movable() override;
    Movable( const Movable &other );
    Movable &operator=( const Movable &other );
    void move( int dx, int dy );
    std::string to_string() const override;

protected:

private:
};

#endif // MOVABLE_HPP
