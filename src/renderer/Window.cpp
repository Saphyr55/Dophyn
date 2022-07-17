#include "renderer/Window.hpp"
#include "core/Logger.hpp"

namespace Renderer
{

    Window::Window(std::string title)
    {   
        this->title = &title;
        baseMat2x2 = new matrix::Mat2x2<Uint32>(0, DEFAULT_HEIGHT, DEFAULT_WIDTH, 0);
        basePoint2 = new point::Point2<Uint32>( SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
        window = SDL_CreateWindow(
            this->title->c_str(),
            basePoint2->x, basePoint2->y,
            getBaseVector()->x, getBaseVector()->y,
            SDL_WINDOW_SHOWN
        );
        if (window == NULL)
            Logger::Log::Error("Creation of the window has failed");

    }

    vector::Vec2<Uint32>* Window::getBaseVector()
    {
        return (*baseMat2x2->iVec2 + *baseMat2x2->jVec2);
    }

    void Window::hideWindow()
    {
        SDL_HideWindow(window);
    }

    void Window::showWindow()
    {
        SDL_ShowWindow(window);
    }

    void Window::raiseWindow()
    {
        SDL_RaiseWindow(window);
    }

    int Window::fullscreen(Uint32 flags)
    {
        return SDL_SetWindowFullscreen(window, flags);
    }

    void Window::destroy()
    {   
        if (window != nullptr)
            SDL_DestroyWindow(window);
    }

    SDL_Window* Renderer::Window::getWindow()
    {
        return window;
    }

    std::string* Renderer::Window::getTitle()
    {   
        return title;
    }
    matrix::Mat2x2<Uint32>* Window::getBaseMatrix2x2()
    {
        return baseMat2x2;
    }
    point::Point2<Uint32>* Window::getBasePoint2Float()
    {
        return basePoint2;
    }
}
