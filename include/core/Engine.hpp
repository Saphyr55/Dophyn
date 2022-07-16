#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include "utils/Time.hpp"
#include "utils/matrix.hpp"
#include "utils/Point.hpp"
#include "utils/vector.hpp"
#include "utils/Color.hpp"
#include "core/Logger.hpp"
#include "renderer/Window.hpp"
#include "renderer/Renderer.hpp"

constexpr auto SUCCESS = 0;
constexpr auto FAILURE = -1;
constexpr auto TITLE = "Dophyn";

namespace Dophyn
{

	class Engine
	{

	public:
		bool isRunning;
		Renderer::Renderer *renderer;
		SDL_Texture *texture;
		vector::Vec2Float *vecPosMouse;
		Renderer::Window *window;
		// Time::Timer *timer;

		Engine();

		int init();
		void handleEvents();
		void update();
		void render();
		int clean();
		bool running() { return this->isRunning; };
		void updateMousePos(SDL_Event &event);
		void launch();
	};
}

#endif
