#include "utils/Color.hpp"
#include <SDL2/SDL.h>

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

Color::Color(Color &cp)
{
	this->blue = cp.blue;
	this->green = cp.green;
	this->red = cp.red;
	this->transparent = cp.transparent;
}
