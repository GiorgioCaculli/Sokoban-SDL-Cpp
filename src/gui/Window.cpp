#include <iostream>
#include <gui/Window.hpp>
#include <SDL3_image/SDL_image.h>

using namespace sokoban::gui;

Window::Window( uint16_t width, uint16_t height )
    : _width( width ), _height( height ), _title( "SokobanSDL" ), _window( nullptr ), _screen_surface( nullptr ),
      _box_surface( nullptr )
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
    } else
    {
        _window = SDL_CreateWindow( get_title().c_str(), get_width(), get_height(), SDL_WINDOW_BORDERLESS );
        if ( _window == nullptr )
        {
            std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            success = false;
        } else
        {
            _screen_surface = SDL_GetWindowSurface( _window );
        }
    }

    return success;
}

/** Loads media */
bool Window::load_media()
{
    /* TODO: SDL3 Image linkage fails for function IMG_Load, to fix in CMakeLists.txt */
    _box_surface = IMG_Load( "assets/images/Preview_Sokoban.png" );

    if ( _box_surface == nullptr )
    {
        std::cerr << "Unable to load image Preview_Sokoban.png" << std::endl;
        return false;
    }

    return true;
}

bool Window::run()
{
    try
    {
        SDL_BlitSurface( _box_surface, nullptr, _screen_surface, nullptr );
        SDL_UpdateWindowSurface( _window );
        SDL_Delay( 2000 );
    }
    catch ( std::exception& e )
    {
        std::cerr << e.what() << std::endl;
        return false;
    }

    return true;
}


/** Frees mediand and shuts down SDL */
void Window::close()
{
    SDL_DestroySurface( _box_surface );

    _box_surface = nullptr;

    SDL_DestroyWindow( _window );

    _window = nullptr;

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
