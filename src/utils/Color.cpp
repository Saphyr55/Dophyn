#include "utils/Color.hpp"
#include <SDL2/SDL.h>


namespace Color
{	
	char* convertToASCII(ColorLogger color)
	{
		switch (color)
		{
		case ColorLogger::WHITE:
			return "\033[0;37m";
		case ColorLogger::YELLOW:
			return "\033[0;33m";
		case ColorLogger::RED:
			return "\033[0;31m";
		case ColorLogger::GREEN:
			return "\033[0;32m";
		default:
			return "\033[0;37m";
		}
	}

	int convertToWin32(ColorLogger color)
	{
		switch (color)
		{
		case ColorLogger::YELLOW:
			return 6;
		case ColorLogger::RED:
			return 4;
		case ColorLogger::WHITE:
			return 15;
		case ColorLogger::GREEN:
			return 2;
		default:
			return 15;
		}
	}

	Color::Color(Uint8 red, Uint8 green, Uint8 blue)
	{
		this->red = red;
		this->green = green;
		this->blue = blue;
		this->transparent = 255;
	}

	Color::Color(Uint8 red, Uint8 green, Uint8 blue, Uint8 transparent)
	{
		this->red = red;
		this->green = green;
		this->blue = blue;
		this->transparent = transparent;
	}

	Color::Color(Color& cp)
	{
		this->blue = cp.blue;
		this->green = cp.green;
		this->red = cp.red;
		this->transparent = cp.transparent;
	}
}
