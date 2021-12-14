#ifndef BOARD_HPP
#define BOARD_HPP

#include "box.hpp"
#include "wall.hpp"
#include "player.hpp"
#include "platform.hpp"

#include <string>
#include <vector>

class Board
{
public:
    enum
    {
        LEFT_COLLISION,
        RIGHT_COLLISION,
        TOP_COLLISION,
        BOTTOM_COLLISION
    };
    explicit Board( const std::string &level );
    virtual ~Board();
    Board( const Board &other );
    Board &operator=( const Board &other );
    std::string get_level() const;
    int get_width() const;
    int get_height() const;
    std::vector< Actor * > get_world() const;
    std::vector< Box * > get_boxes() const;
    std::vector< Wall * > get_walls() const;
    std::vector< Player * > get_players() const;
    std::vector< Platform * > get_platforms() const;
    bool check_wall_collision( const Actor *actor, const int type );
    bool check_box_collision( const int type );
    bool is_completed() const;
    std::string to_string() const;

private:
    std::string _level;
    int _width;
    int _height;
    std::vector< Actor * > _world;
    std::vector< Box * > _boxes;
    std::vector< Wall * > _walls;
    std::vector< Player * > _players;
    std::vector< Platform * > _platforms;
    void init_board();
    void init_world();
    void build_world();
};

#endif // BOARD_HPP
