#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include "utils/Time.hpp"
#include "utils/Matrix.hpp"
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

	private:
		static Engine* engine;

	private:
		bool running;
		Renderer::Renderer *renderer;
		SDL_Texture *texture;
		vector::Vec2<float> *vecPosMouse;
		Renderer::Window *window;
	
	public:
		Engine();

		int init();
		int clean();
		void handleEvents();
		void render();
		void update();
		void updateMousePos(SDL_Event &event);
		void launch();

	public:
		inline static Engine* getEngine() { return engine = (engine != nullptr) ? engine : new Engine(); }
		inline bool isRunning() { return running; }
		inline Renderer::Renderer* getRenderer() { return renderer; }
		inline Renderer::Window* getWindow() { return window; }
		inline vector::Vec2<float>* getPosMouse() { return vecPosMouse; }
	};
}

#endif
