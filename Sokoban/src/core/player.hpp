#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "movable.hpp"

class Player
        : public Movable
{
public:
    Player( int x, int y );
    virtual ~Player();
    Player( const Player &other );
    Player &operator=( const Player &other );
    std::string to_string() const override;

protected:

private:
};

#endif // PLAYER_HPP
