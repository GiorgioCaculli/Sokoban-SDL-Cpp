#include "main.hpp"

#include <gzc/games/sokoban/core/Board.hpp>

#include <gui/Window.hpp>

#include <iostream>

int main( const int argc, char* argv[ ] )
{
    std::cout << "Sokoban by Giorgio Caculli W/ SDL3" << std::endl;

    std::cout << "Number of arguments: " << std::to_string( argc ) << std::endl;

    std::cout << "Calling: ";
    for ( int i = 0; i < argc; i++ )
    {
        std::cout << argv[ i ] << " ";
    }
    std::cout << std::endl;

    const auto board = sokoban::core::Board( "assets/levels/00.lvl" );

    std::cout << board.to_string() << std::endl;

    auto* window = new sokoban::gui::Window( 1280, 720 );

    bool loaded_media = window->load_media();

    std::cout << loaded_media << std::endl;

    delete window;

    return 0;
}
