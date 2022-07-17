#include "core/Engine.hpp"
#include <chrono>
#include <ctime>
#include "utils/Time.hpp"

namespace Dophyn
{
	Engine* Engine::engine = nullptr;

	Engine::Engine()
	{	
		window = new Renderer::Window(TITLE);
		renderer = new Renderer::Renderer(*window);
		vecPosMouse = new vector::Vec2<float>(0.f, 0.f);
		running = false;
		texture = nullptr;
	}

	int Engine::init()
	{

		if (SDL_Init(SDL_INIT_EVERYTHING) != SUCCESS)
		{
			Dophyn::Log::Error("Subsystems initialization failed");
			return FAILURE;
		}

		Dophyn::Log::Info("Subsystems initialization");
		
		renderer->setBackgroundColor(Color::Color(255, 255, 0));
		
		running = true;


		return SUCCESS;
	}

	void Engine::updateMousePos(SDL_Event& event)
	{
		vecPosMouse->x = event.motion.x;
		vecPosMouse->y = event.motion.y;
	}

	void Engine::launch()
	{	
		while (isRunning())
		{	
			handleEvents();
			update();
			renderer->render();
			Time::Timer::timer()->tick();
		}
	}

	void Engine::handleEvents()
	{
		SDL_Event event;
		SDL_PollEvent(&event);

		switch (event.type)
		{
		case SDL_QUIT:
			running = false;
			break;

		case SDL_MOUSEMOTION:
			updateMousePos(event);
			break;
		default:
			break;
		}
	}



	void Engine::update()
	{
		

	}

	int Engine::clean()
	{
		if (texture != nullptr)
			SDL_DestroyTexture(texture);

		if (renderer->getRenderer() != nullptr)
			renderer->destroy();

		if (window->getWindow() != nullptr)
			window->destroy();

		SDL_Quit();
		return EXIT_SUCCESS;
	}

	int setRendererDrawColor(Renderer::Renderer& renderer, Color::Color* color)
	{
		return SDL_SetRenderDrawColor(renderer.getRenderer(), color->red, color->green, color->blue, color->transparent);
	}

}

