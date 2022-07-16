#ifndef TIME_HPP
#define TIME_HPP

#include <iostream>

namespace Time
{
	class Timer
	{
	public:
		float MAX_FPS = 120.f;
		float MAX_DELTA_TIME = 1.f;

	public:
		void tick();
		inline float getLastTime() { return lastTime; }
		inline float getDeltaTime() { return deltaTime; }
		inline static Timer* timer() 
		{
			return instance = (instance != nullptr) ? instance : new Timer();
		}

	private:
		Timer();
		static Timer* instance;
		float deltaTime;
		float lastTime;
	};

	const std::string currentDateTimeLogger();

}

#endif
