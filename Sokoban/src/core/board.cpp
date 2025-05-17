#include <core/board.hpp>

#include <string>
#include <fstream>
#include <sstream>

namespace
{
    int OFFSET = 1;
    int SPACE = 1;
}

Board::Board( const std::string &level )
        : _level( level )
          , _width( 0 )
          , _height( 0 )
          , _world()
          , _boxes()
          , _walls()
          , _players()
          , _platforms()
{
    std::string line;
    std::stringstream ss;
    std::fstream level_file( level );
    if ( level_file.is_open() )
    {
        while ( std::getline( level_file, line ) )
        {
            ss << line << '\n';
        }
        level_file.close();
    }
    _level = std::move( ss.str() );
    init_board();
}

Board::~Board()
{
    for ( Box *box: _boxes )
    {
        delete box;
    }
    _boxes.clear();
    for ( Wall *wall: _walls )
    {
        delete wall;
    }
    _walls.clear();
    for ( Player *player: _players )
    {
        delete player;
    }
    _players.clear();
    for ( Platform *platform: _platforms )
    {
        delete platform;
    }
    _platforms.clear();
    _world.clear();
}

Board::Board( const Board &other )
        : Board( other._level )
{
}

Board &Board::operator=( const Board &rhs )
{
    if ( this != &rhs )
    {
        _level = rhs._level;
        _width = rhs._width;
        _height = rhs._height;
        _world = rhs._world;
        _boxes = rhs._boxes;
        _walls = rhs._walls;
        _players = rhs._players;
        _platforms = rhs._platforms;
    }
    init_board();
    return *this;
}

void Board::init_board()
{
    init_world();
}

void Board::init_world()
{
    _boxes = std::vector< Box * >();
    _walls = std::vector< Wall * >();
    _players = std::vector< Player * >();
    _platforms = std::vector< Platform * >();

    int x = OFFSET;
    int y = OFFSET;

    Box *box;
    Wall *wall;
    Player *player;
    Platform *platform;

    for ( char item: _level )
    {
        switch ( item )
        {
            case '\n':
                y += SPACE;
                if ( _width < x )
                {
                    _width = x;
                }
                x = OFFSET;
                break;
            case '#':
                wall = new Wall( x, y );
                _walls.emplace_back( wall );
                x += SPACE;
                break;
            case '$':
                box = new Box( x, y );
                _boxes.emplace_back( box );
                x += SPACE;
                break;
            case '.':
                platform = new Platform( x, y );
                _platforms.emplace_back( platform );
                x += SPACE;
                break;
            case '@':
                player = new Player( x, y );
                _players.emplace_back( player );
                x += SPACE;
                break;
            case '*':
                box = new Box( x, y );
                platform = new Platform( x, y );
                _boxes.emplace_back( box );
                _platforms.emplace_back( platform );
                x += SPACE;
                break;
            case '+':
                player = new Player( x, y );
                platform = new Platform( x, y );
                _players.emplace_back( player );
                _platforms.emplace_back( platform );
                x += SPACE;
                break;
            case ' ':
                x += SPACE;
                break;
            default:
                break;
        }
        _height = y;
    }
    build_world();
}

void Board::build_world()
{
    _world = std::vector< Actor * >();
    for ( Player *player: _players )
    {
        _world.emplace_back( player );

        for ( Box *box: _boxes )
        {
            _world.emplace_back( box );
        }
    }
    for ( Platform *platform: _platforms )
    {
        _world.emplace_back( platform );
    }
    for ( Wall *wall: _walls )
    {
        _world.emplace_back( wall );
    }
}

bool Board::check_wall_collision( const Actor *actor, const int type )
{
    for ( const Wall *wall: _walls )
    {
        switch ( type )
        {
            case LEFT_COLLISION:
                if ( actor->is_left_collision( wall ) )
                {
                    return true;
                }
                return false;
            case RIGHT_COLLISION:
                if ( actor->is_right_collision( wall ) )
                {
                    return true;
                }
                return false;
            case TOP_COLLISION:
                if ( actor->is_top_collision( wall ) )
                {
                    return true;
                }
                return false;
            case BOTTOM_COLLISION:
                if ( actor->is_bottom_collision( wall ) )
                {
                    return true;
                }
                return false;
            default:
                return false;
        }
    }
    return false;
}

bool Board::check_box_collision( const int type )
{
    switch ( type )
    {
        case LEFT_COLLISION:
            for( Box *box : _boxes )
            {
                for( Player *player : _players )
                {
                    if( player->is_left_collision( box ) )
                    {
                        for( Box *other_box : _boxes )
                        {
                            if( box != other_box )
                            {
                                if( box->is_left_collision( other_box ) )
                                {
                                    return true;
                                }
                            }
                            if( check_wall_collision( box, LEFT_COLLISION ) )
                            {
                                return true;
                            }
                        }
                        box->move( -SPACE, 0 );
                        is_completed();
                    }
                }
            }
            return false;
        case RIGHT_COLLISION:
            for( Box *box : _boxes )
            {
                for( Player *player : _players )
                {
                    if( player->is_right_collision( box ) )
                    {
                        for( Box *other_box : _boxes )
                        {
                            if( box != other_box )
                            {
                                if( box->is_right_collision( other_box ) )
                                {
                                    return true;
                                }
                            }
                            if( check_wall_collision( box, RIGHT_COLLISION ) )
                            {
                                return true;
                            }
                        }
                        box->move( SPACE, 0 );
                        is_completed();
                    }
                }
            }
            return false;
        case TOP_COLLISION:
            for( Box *box : _boxes )
            {
                for( Player *player : _players )
                {
                    if( player->is_top_collision( box ) )
                    {
                        for( Box *other_box : _boxes )
                        {
                            if( box != other_box )
                            {
                                if( box->is_top_collision( other_box ) )
                                {
                                    return true;
                                }
                            }
                            if( check_wall_collision( box, TOP_COLLISION ) )
                            {
                                return true;
                            }
                        }
                        box->move( 0, -SPACE );
                        is_completed();
                    }
                }
            }
            return false;
        case BOTTOM_COLLISION:
            for( Box *box : _boxes )
            {
                for( Player *player : _players )
                {
                    if( player->is_bottom_collision( box ) )
                    {
                        for( Box *other_box : _boxes )
                        {
                            if( box != other_box )
                            {
                                if( box->is_bottom_collision( other_box ) )
                                {
                                    return true;
                                }
                            }
                            if( check_wall_collision( box, BOTTOM_COLLISION ) )
                            {
                                return true;
                            }
                        }
                        box->move( 0, SPACE );
                        is_completed();
                    }
                }
            }
            return false;
        default:
            return false;
    }
}

bool Board::is_completed() const
{
    unsigned long number_of_boxes = _boxes.size();
    unsigned long finished_boxes = 0;

    for ( Box *box: _boxes )
    {
        for ( Platform *platform: _platforms )
        {
            if ( box->get_x() == platform->get_x() && box->get_y() == platform->get_y() )
            {
                finished_boxes += 1;
            }
        }
    }

    return finished_boxes == number_of_boxes;
}

std::string Board::get_level() const
{
    return _level;
}

int Board::get_width() const
{
    return _width;
}

int Board::get_height() const
{
    return _height;
}

std::vector< Actor * > Board::get_world() const
{
    return _world;
}

std::vector< Box * > Board::get_boxes() const
{
    return _boxes;
}

std::vector< Wall * > Board::get_walls() const
{
    return _walls;
}

std::vector< Player * > Board::get_players() const
{
    return _players;
}

std::vector< Platform * > Board::get_platforms() const
{
    return _platforms;
}

std::string Board::to_string() const
{
    std::stringstream ss;
    ss << _level << std::endl;
    for ( Actor *actor: _world )
    {
        ss << actor->to_string() << std::endl;
    }
    return ss.str();
}
