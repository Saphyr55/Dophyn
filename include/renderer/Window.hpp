#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include "utils/Matrix.hpp"
#include "utils/Point.hpp"

#define DEFAULT_WIDTH 1280
#define DEFAULT_HEIGHT 720

namespace Dophyn
{
	namespace Renderer
	{
		class Window
		{

		private:
			SDL_Window* window;
			std::string* title;
			matrix::Mat2x2<Uint32>* baseMat2x2;
			point::Point2<Uint32>* basePoint2;

		public:
			Window(std::string title);
			void hideWindow();
			void showWindow();
			void raiseWindow();
			int fullscreen(Uint32 flags);
			void destroy();

		public:
			vector::Vec2<Uint32>* getBaseVector();
			SDL_Window* getWindow();
			std::string* getTitle();
			matrix::Mat2x2<Uint32>* getBaseMatrix2x2();
			point::Point2<Uint32>* getBasePoint2Float();
		};
	}
}

#endif
