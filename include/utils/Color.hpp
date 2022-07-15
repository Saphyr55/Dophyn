#ifndef COLOR_H
#define COLOR_H
#include <SDL2/SDL.h>

class Color
{

public:
	Uint8 red, green, blue, transparent;

	Color(Uint8 red, Uint8 green, Uint8 blue);
	Color(Uint8 red, Uint8 green, Uint8 blue, Uint8 transparent);
	Color(Color &cp);
};

#endif
