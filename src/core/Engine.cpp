#include "core/Engine.hpp"
#include <chrono>
#include <ctime>
#include "utils/Time.hpp"

namespace Dophyn
{

	Engine::Engine()
	{	
		window = new Renderer::Window(TITLE);
		renderer = new Renderer::Renderer(*window);
		vecPosMouse = new vector::Vec2Float(0.f, 0.f);
		isRunning = false;
		texture = nullptr;
		// timer = new Time::Timer();
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
		
		isRunning = true;


		return SUCCESS;
	}

	void Engine::updateMousePos(SDL_Event& event)
	{
		vecPosMouse->x = event.motion.x;
		vecPosMouse->y = event.motion.y;
		// vecPosMouse->print(); // affiche les coordonées de la souris sur l'ecran
	}

	void Engine::launch()
	{	
		while (running())
		{	
			handleEvents();
			update();
			render();
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
			isRunning = false;
			break;

		case SDL_MOUSEMOTION:
			updateMousePos(event);
			break;
		default:
			break;
		}
	}

	void Engine::render()
	{
		SDL_RenderClear(renderer->getRenderer());
		SDL_RenderPresent(renderer->getRenderer());
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

