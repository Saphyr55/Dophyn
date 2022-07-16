#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include "utils/matrix.hpp"
#include "utils/Point.hpp"

#define DEFAULT_WIDTH 1280
#define DEFAULT_HEIGHT 720

namespace Renderer
{
	class Window
	{

	private:
		SDL_Window *window;
		std::string *title;
		matrix::Mat2x2 *baseMat2x2;
		point::Point2Float *basePoint2;

	public:
		Window(std::string title);
		vector::Vec2Float* baseVector();
		void hideWindow();
		void showWindow();
		void raiseWindow();
		int fullscreen(Uint32 flags);
		void destroy();

	public:
		SDL_Window* getWindow();
		std::string* getTitle();
		matrix::Mat2x2* getBaseMatrix2x2();
		point::Point2Float* getBasePoint2Float();
	};
}

#endif