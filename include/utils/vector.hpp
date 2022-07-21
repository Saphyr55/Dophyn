#ifndef VEC_H
#define VEC_H

#include "utils/Point.hpp"

namespace Dophyn
{
	namespace vector
	{
		template<typename T>
		class Vec2
		{

		public:
			// void vector::Vec2<T>::scaleBy(T a) { this->x *= a; this->y *= a; }
			inline Vec2<T>* operator+ (const Vec2<T>& v) const { return new Vec2<T>(x + v.x, y + v.y); }
			inline Vec2<T>* operator- (const Vec2<T>& v) const { return new Vec2<T>(x - v.x, y - v.y); }
			inline Vec2<T>* operator* (const int a) const { return new Vec2<T>(x * a, y * a); }

		public:
			inline Vec2<T>(point::Point2<T>& p1, point::Point2<T>& p2) { this->x = p2.getX() - p1.getX(); this->y = p2.getY() - p1.getY(); }
			inline Vec2<T>(T x, T y) { this->x = x; this->y = y; };

		public:
			T x, y;

		};

	}
}

#endif
