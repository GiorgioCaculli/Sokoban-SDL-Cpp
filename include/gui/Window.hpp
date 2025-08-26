#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
bool init();

bool load_media();

void close();


namespace sokoban::gui
{
    class Window
    {
    private:
        uint16_t _width;
        uint16_t _height;
        std::string _title;

        /** The window we'll be rendering to */
        SDL_Window *window = nullptr;

        /** The surface contained by the window */
        SDL_Surface *screen_surface = nullptr;

        /** The image we will load and show on the screen */
        SDL_Surface *box_surface = nullptr;

    public:
        Window( uint16_t width, uint16_t height );
        Window();
        Window( const Window& );
        Window &operator=( const Window& );
        ~Window();
        uint16_t get_width() const;
        uint16_t get_height() const;
        std::string get_title() const;
        bool init();
        bool load_media();
        void close();
    };
}

#endif //WINDOW_HPP
