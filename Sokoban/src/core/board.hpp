#ifndef BOARD_HPP
#define BOARD_HPP


class Board
{
    public:
        Board();
        virtual ~Board();
        Board(const Board& other);
        Board& operator=(const Board& other);

    protected:

    private:
};

#endif // BOARD_HPP
