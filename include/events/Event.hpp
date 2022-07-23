#pragma once 

#ifndef DOPHYN_EVENT_HPP
#define DOPHYN_EVENT_HPP

#include "SDL2/SDL.h"
#include 

namespace Dophyn
{
	namespace Events
	{
		class Event
		{
		public:
			Event() = delete;
			~Event() = delete;

			static SDL_Event getEvent();

		private:
			static SDL_Event event;
		};
	}
}

#endif
