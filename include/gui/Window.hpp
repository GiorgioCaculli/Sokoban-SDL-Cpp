#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>

#include <SDL3/SDL.h>

namespace sokoban::gui
{
    class Window
    {
    private:
        uint16_t _width;
        uint16_t _height;
        std::string _title;
        SDL_Window *_window; /** The window we'll be rendering to */
        SDL_Surface *_screen_surface; /** The surface contained by the window */
        SDL_Surface *_box_surface; /** The image we will load and show on the screen */

    public:
        Window( uint16_t width, uint16_t height );
        Window();
        Window( const Window& );
        Window &operator=( const Window& );
        ~Window();
        bool init();
        bool load_media();
        void close();
        bool run();
        [[nodiscard]] uint16_t get_width() const;
        [[nodiscard]] uint16_t get_height() const;
        [[nodiscard]] std::string get_title() const;
    };
}

#endif //WINDOW_HPP
