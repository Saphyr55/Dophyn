#include "core/Engine.hpp"

namespace Dophyn
{
	int setRendererDrawColor(SDL_Renderer* renderer, Color* color);

	Engine::Engine()
	{	
		window = new Renderer::Window(TITLE);
		renderer = nullptr;
		vecPosMouse = new vector::Vec2Float(0.f, 0.f);
		isRunning = false;
		texture = nullptr;
	}

	int Engine::init()
	{

		if (SDL_Init(SDL_INIT_EVERYTHING) != SUCCESS)
		{
			Logger::Log::Error("Subsystems initialization failed");
			return FAILURE;
		}

		Logger::Log::Error("Subsystems initialization");

		if ((renderer = SDL_CreateRenderer(window->getWindow(), -1, 0)) == NULL)
			Logger::Log::Error("Creation of the rendering has failed");
		if (setRendererDrawColor(renderer, new Color(0, 0, 0)) != 0)
			Logger::Log::Error("Renderer draw color failed");

		isRunning = true;

		launch();

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
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}

	void Engine::update()
	{

	}

	int Engine::clean()
	{
		if (texture != nullptr)
			SDL_DestroyTexture(texture);
		if (renderer != nullptr)
			SDL_DestroyRenderer(renderer);

		if (window->getWindow() != nullptr)
			window->destroy();

		SDL_Quit();
		return EXIT_SUCCESS;
	}

	int setRendererDrawColor(SDL_Renderer* renderer, Color* color)
	{
		return SDL_SetRenderDrawColor(renderer, color->red, color->green, color->blue, color->transparent);
	}

}

