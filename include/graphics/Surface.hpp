#pragma once

#ifndef SURFACE_HPP
#define SURFACE_HPP

#include "SDL2/SDL.h"

namespace Dophyn
{
	class Surface
	{
	public:
		Surface();
		~Surface();

	private:
		SDL_Surface surface;

	};
}

#endif
