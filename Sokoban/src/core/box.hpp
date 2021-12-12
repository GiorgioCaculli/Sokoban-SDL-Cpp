#ifndef BOX_HPP
#define BOX_HPP

#include "movable.hpp"


class Box
: public Movable
{
    public:
        Box( int x, int y );
        ~Box() override;
        Box(const Box& other);
        Box& operator=(const Box& other);

    protected:

    private:
};

#endif // BOX_HPP
