#include "core/vector.hpp"
#include <iostream>

/*
Vector2D Int
*/

vector::Vec2Uint::Vec2Uint(int x, int y)
{
	this->x = x;
	this->y = y;
}

vector::Vec2Uint::Vec2Uint(point::Point2Uint &p1, point::Point2Uint &p2)
{
	this->x = p2.x - p1.x;
	this->y = p2.y - p1.y;
}

vector::Vec2Uint *vector::Vec2Uint::scaleBy(int a)
{
	this->x *= a;
	this->y *= a;
	return this;
}

void vector::Vec2Uint::print()
{
	std::cout << "[ " << this->x << ", " << this->y << " ]\n";
}

/*
Vector2D Float
*/

vector::Vec2Float::Vec2Float(float x, float y)
{
	this->x = x;
	this->y = y;
}

vector::Vec2Float::Vec2Float(point::Point2Float *p1, point::Point2Float *p2)
{
	this->x = p2->x - p1->x;
	this->y = p2->y - p1->y;
}

vector::Vec2Float *vector::Vec2Float::scaleBy(float a)
{
	this->x *= a;
	this->y *= a;
	return this;
}

void vector::Vec2Float::print()
{
	std::cout << "[ " << this->x << ", " << this->y << " ]\n";
}