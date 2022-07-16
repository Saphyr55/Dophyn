#include "renderer/Renderer.hpp";
#include "core/Logger.hpp"

namespace Renderer
{	

	Renderer::Renderer(Window &window)
	{	
		this->window = &window;
		index = -1;
		flags = RENDERER_ACCELERATED;
		renderer = SDL_CreateRenderer(window.getWindow(), index, flags);

		if (renderer == NULL)
			Logger::Log::Error("Creation of the rendering has failed");

	}

	SDL_Renderer* Renderer::Renderer::getRenderer()
	{
		return renderer;
	}

	Window* Renderer::Renderer::getWindow()
	{
		return window;
	}

	int  Renderer::Renderer::getIndex()
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