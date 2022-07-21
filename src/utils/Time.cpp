#include "utils/Time.hpp"
#include "SDL2/SDL.h"

namespace Dophyn
{
	namespace Time
	{
		Timer* Timer::instance = nullptr;

		Timer::Timer() { }

		const std::string currentDateTimeLogger()
		{
			time_t     now = time(0);
			struct tm  tstruct;
			char       buf[80];
			tstruct = *localtime(&now);
			strftime(buf, sizeof(buf), "%Y-%m-%d | %X", &tstruct);
			return buf;
		}

		void Timer::tick()
		{
			deltaTime = (SDL_GetTicks() - getLastTime()) * (MAX_FPS / 1000.f);
			if (deltaTime > MAX_DELTA_TIME)
				deltaTime = MAX_DELTA_TIME;

			lastTime = SDL_GetTicks();
		}
	}
}