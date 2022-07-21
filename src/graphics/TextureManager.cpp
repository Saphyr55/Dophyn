#include "graphics/TextureManager.hpp"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "core/Logger.hpp"

namespace Dophyn
{
	void TextureManager::load(std::string id, std::string filename)
	{
		SDL_Surface* s = IMG_Load(filename.c_str());
		if (s != nullptr)
		{
			Logger::Log::Info() << "The file " << filename << " was loaded";
		}
		else
			Logger::Log::Warning() << "The file " << filename << "wasn't loaded " << SDL_GetError();


	}

	void TextureManager::drop(std::string id)
	{
	}
}
