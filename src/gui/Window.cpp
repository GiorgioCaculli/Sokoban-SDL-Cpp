#include <iostream>
#include <gui/Window.hpp>

using namespace sokoban::gui;

Window::Window( uint16_t width, uint16_t height )
    : _width( width ), _height( height ), _title( "SokobanSDL" )
{
    init();
}

Window::Window()
    : Window( 800, 600 )
{
}

Window::Window( const Window& window )
    : Window( window.get_width(), window.get_height() )
{
}

Window& Window::operator=( const Window& window )
{
    if ( this != &window )
    {
        this->_width = window._width;
        this->_height = window._height;
        this->_title = window._title;
    }
    return *this;
}

Window::~Window()
{
    close();
}

/**
 * Starts up SDL and creates a window
 */
bool Window::init()
{
    bool success = true;

    if ( !SDL_Init( SDL_INIT_VIDEO ) )
    {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        success = false;
    }
    else
    {
        window = SDL_CreateWindow( get_title().c_str(), get_width(), get_height(), SDL_WINDOW_BORDERLESS );
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

/** Loads media */
bool Window::load_media()
{
    bool success = true;

    /* TODO: SDL3 Image linkage fails for function IMG_Load, to fix in CMakeLists.txt */
    /*box_surface = IMG_Load( "assets/images/Preview_Sokoban.png" );

    if ( box_surface == nullptr )
    {
        std::cerr << "Unable to load image Preview_Sokoban.png" << std::endl;
        success = false;
    }*/

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


    return success;
}

/** Frees mediand and shuts down SDL */
void Window::close()
{
    SDL_DestroySurface( box_surface );

    box_surface = nullptr;

    SDL_DestroyWindow( window );

    window = nullptr;

    SDL_Quit();
}

uint16_t Window::get_width() const
{
    return _width;
}

uint16_t Window::get_height() const
{
    return _height;
}

std::string Window::get_title() const
{
    return _title;
}
