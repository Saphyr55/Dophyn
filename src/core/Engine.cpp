#include "core/Engine.hpp"
#include "utils/Color.hpp"
#include <SDL2/SDL.h>

using namespace Dophyn;

int setRendererDrawColor(SDL_Renderer *renderer, Color *color);

Engine::Engine()
{
	baseMat2x2 = new matrix::Mat2x2(
		new vector::Vec2Float(0, DEFAULT_HEIGHT),
		new vector::Vec2Float(DEFAULT_WIDTH, 0));
	basePoint2 = new point::Point2Float(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	window = nullptr;
	renderer = nullptr;
	vecPosMouse = new vector::Vec2Float(0.f, 0.f);
	isRunning = false;
}

int Engine::init(std::string title)
{
	return Engine::init(title, this->basePoint2, (*this->baseMat2x2->iVec2 + *this->baseMat2x2->jVec2));
}

int Engine::init(std::string title, point::Point2Uint *p, vector::Vec2Uint *v)
{
	return Engine::init(title, p->x, p->y, v->x, v->y);
}

int Engine::init(std::string title, point::Point2Float *p, vector::Vec2Float *v)
{
	return Engine::init(title, (int)p->x, (int)p->y, (int)v->x, (int)v->y);
}

int Engine::init(std::string title, int xpos, int ypos, int width, int height)
{

	if (SDL_Init(SDL_INIT_EVERYTHING) != SUCCESS)
	{
		logError("Subsystems initialization failed");
		return FAILURE;
	}

	log("Subsystems initialization ");

	if ((window = SDL_CreateWindow(title.c_str(), xpos, ypos, width, height, 0)) == NULL)
		logError("Creation of the window has failed");
	if ((renderer = SDL_CreateRenderer(window, -1, 0)) == NULL)
		logError("Creation of the rendering has failed");
	if (setRendererDrawColor(renderer, new Color(0, 0, 0)) != 0)
		logError("Renderer draw color failed");

	isRunning = true;

	return SUCCESS;
}

void Engine::updateMousePos(SDL_Event &event)
{
	vecPosMouse->x = event.motion.x;
	vecPosMouse->y = event.motion.y;
	// vecPosMouse->print(); affiche les coordonées de la souris sur l'ecran
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
	//SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}

int setRendererDrawColor(SDL_Renderer *renderer, Color *color)
{
	return SDL_SetRenderDrawColor(renderer, color->red, color->green, color->blue, color->transparent);
}
