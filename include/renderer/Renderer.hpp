#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL2/SDL.h>
#include "renderer/Window.hpp"
#include "utils/Color.hpp"

namespace Renderer
{

	class Renderer
	{

		const SDL_RendererFlags RENDERER_SOFTWARE = SDL_RENDERER_SOFTWARE;
		const SDL_RendererFlags RENDERER_ACCELERATED = SDL_RENDERER_ACCELERATED;
		const SDL_RendererFlags RENDERER_PRESENTVSYNC = SDL_RENDERER_PRESENTVSYNC;

	private:
		SDL_Renderer *renderer;
		Window *window;
		int index;
		Uint32 flags;

	public:
		Renderer(Window &window);
		void destroy();
		void setBackgroundColor(Color::Color& color);
		void render();

	public:
		SDL_Renderer *getRenderer();
		Window &getWindow();
		int getIndex();
		Uint32 getFlags();
		Renderer *setFlags(Uint32 &flags);
		Renderer *setIndex(int &index);
	};
}

#endif
