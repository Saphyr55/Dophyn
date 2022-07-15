#ifndef APP_H
#define APP_H

#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include "matrix.hpp"
#include "Point.hpp"
#include "vector.hpp"

#define SUCCESS 0
#define FAILURE -1
#define DEFAULT_WIDTH 1280
#define DEFAULT_HEIGHT 720

namespace engine
{
	class Engine
	{

	public:
		Engine();

		int init(std::string title);
		void handleEvents();
		void update();
		void render();
		int clean();
		bool running() { return this->isRunning; };
		void log(std::string msg) { std::cout << msg << std::endl; }
		void logError(std::string msg) { std::cerr << msg << SDL_GetError() << std::endl; }
		void updateMousePos(SDL_Event &event);

		bool isRunning;
		SDL_Window *window;
		SDL_Renderer *renderer;
		SDL_Texture *texture;
		matrix::Mat2x2 *baseMat2x2;
		point::Point2Float *basePoint2;
		vector::Vec2Float *vecPosMouse;

	private:
		int init(std::string title, int xpos, int ypos, int width, int height);
		int init(std::string title, point::Point2Uint *p, vector::Vec2Uint *v);
		int init(std::string title, point::Point2Float *p, vector::Vec2Float *v);
	};
}

#endif
