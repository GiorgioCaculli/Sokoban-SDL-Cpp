#include "main.hpp"

#include <core/board.hpp>

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include <iostream>

/**
 * Starts up SDL and creates a window
 */
bool init();

/** Loads media */
bool load_media();

/** Frees mediand and shuts down SDL */
void close();

/** Screen Width and Height */
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = SCREEN_WIDTH / 4 * 3;

/** The window we'll be rendering to */
SDL_Window *window = nullptr;

/** The surface contained by the window */
SDL_Surface *screen_surface = nullptr;

/** The image we will load and show on the screen */
SDL_Surface *box_surface = nullptr;

int main( int argc, char *argv[] )
{
    std::cout << "Sokoban by Giorgio Caculli W/ SDL3" << std::endl;

    std::cout << "Number of arguments: " << std::to_string( argc ) << std::endl;

    std::cout << "Calling: ";
    for ( int i = 0; i < argc; i++ )
    {
        std::cout << argv[ i ] << " ";
    }
    std::cout << std::endl;

    Board board = Board( "assets/levels/00.lvl" );

    std::cout << board.to_string() << std::endl;

    if ( !init() )
    {
        std::cerr << "Failed to initialize" << std::endl;
    }
    else
    {
        if ( !load_media() )
        {
            std::cerr << "Failed to load media!" << std::endl;
        }
        else
        {
            SDL_BlitSurface( box_surface, nullptr, screen_surface, nullptr );
            SDL_UpdateWindowSurface( window );
            SDL_Delay( 2000 );
        }
    }

    close();

    return 0;
}

bool init()
{
    bool success = true;

    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        success = false;
    }
    else
    {
        window = SDL_CreateWindow( "Sokoban", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_BORDERLESS );
        if ( window == nullptr )
        {
            std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            success = false;
        }
        else
        {
            screen_surface = SDL_GetWindowSurface( window );
        }
    }

    return success;
}

bool load_media()
{
    bool success = true;

    box_surface = IMG_Load( "assets/images/Preview_Sokoban.png" );

    if ( box_surface == nullptr )
    {
        std::cerr << "Unable to load image Preview_Sokoban.png" << std::endl;
        success = false;
    }

    return success;
}

void close()
{
    SDL_DestroySurface( box_surface );

    box_surface = nullptr;

    SDL_DestroyWindow( window );

    window = nullptr;

    SDL_Quit();
}
