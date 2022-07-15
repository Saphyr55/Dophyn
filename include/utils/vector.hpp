#ifndef VEC_H
#define VEC_H

#include "Point.hpp"

namespace vector 
{
	class Vec2Uint
	{
	public:
		int x, y;

		Vec2Uint(int x, int y);
		Vec2Uint(point::Point2Uint& p1, point::Point2Uint& p2);
		
		vector::Vec2Uint* scaleBy(int a);

		Vec2Uint* operator+ (const Vec2Uint& v) const { return new Vec2Uint(x + v.x, y + v.y); }
		Vec2Uint* operator- (const Vec2Uint& v) const { return new Vec2Uint(x - v.x, y - v.y); }
		Vec2Uint* operator* (const int a) const { return new Vec2Uint(x*a, y*a); }
		void print();

	};

	class Vec2Float
	{
	public:
		float x, y;

	public:
		Vec2Float(float x, float y);
		Vec2Float(point::Point2Float* p1, point::Point2Float* p2);
		vector::Vec2Float* scaleBy(float a);
		void print();

	public:
		Vec2Float* operator+ (const Vec2Float& v) const { return new Vec2Float(x + v.x, y + v.y); }
		Vec2Float* operator- (const Vec2Float& v) const { return new Vec2Float(x - v.x, y - v.y); }
		Vec2Float* operator* (const float a) const { return new Vec2Float(x * a, y * a); }
		
	};

}
#endif
