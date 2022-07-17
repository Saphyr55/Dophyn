#ifndef POINT_HPP
#define POINT_HPP

namespace point
{
	template<typename T>
	class Point2
	{

	public:
		T x, y;
	
	public:
		inline Point2(T x, T y) { this->x = x; this->y = y; };
	
	};

}

#endif
