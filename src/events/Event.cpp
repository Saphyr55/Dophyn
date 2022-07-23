#include "events/Event.hpp"

namespace Dophyn
{
	namespace Events
	{
		SDL_Event Event::getEvent()
		{
			return event;
		}
	}
}