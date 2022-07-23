#include "renderer/Renderer.hpp"
#include "core/Logger.hpp"


namespace Dophyn
{
	namespace Renderer
	{

		Renderer::Renderer(Window& window)
		{
			this->window = &window;
			index = -1;
			flags = RENDERER_SOFTWARE;
			renderer = SDL_CreateRenderer(window.getWindow(), index, flags);

			if (renderer == NULL)
				Logger::Log::Error() << "Creation of the rendering has failed ; " << SDL_GetError();
		}

		void Renderer::render()
		{
			SDL_RenderClear(getRenderer());
			SDL_RenderPresent(getRenderer());
		}

		void Renderer::destroy()
		{
			SDL_DestroyRenderer(renderer);
		}

		void Renderer::setBackgroundColor(Color::Color color)
		{
			if (SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, color.transparent) != 0)
				Logger::Log::Warning() << "Renderer draw color failed";
		}

		SDL_Renderer* Renderer::Renderer::getRenderer()
		{
			return renderer;
		}

		Window& Renderer::Renderer::getWindow()
		{
			return *window;
		}

		int Renderer::Renderer::getIndex()
		{
			return index;
		}

		Uint32 Renderer::Renderer::getFlags()
		{
			return flags;
		}

		Renderer* Renderer::setIndex(int& index)
		{
			this->index = index;
			return this;
		}

		Renderer* Renderer::setFlags(Uint32& flags)
		{
			this->flags = flags;
			return this;
		}

	}
}