#ifndef VECTOR_H
#define VECTOR_H

#include "vector.hpp"

namespace matrix
{	
	template<typename T>
	class Mat2x2
	{

	public:
		vector::Vec2<T>* application(T x, T y);
		T determinant();
		bool isInversible();
		Mat2x2* inverse();

	public:
		vector::Vec2<T> *iVec2;
		vector::Vec2<T> *jVec2;

		Mat2x2(T a, T c, T b, T d)
		{
			this->iVec2 = new vector::Vec2<T>(a, c);
			this->jVec2 = new vector::Vec2<T>(b, d);
		}
		Mat2x2(vector::Vec2<T>* iVec2, vector::Vec2<T>* jVec2)
		{
			this->iVec2 = iVec2;
			this->jVec2 = jVec2;
		}

		Mat2x2 *operator*(const T a) const { return new Mat2x2(*this->iVec2 * a, *this->jVec2 * a); }
		Mat2x2 *operator*(const Mat2x2 *mat) const
		{
			return new Mat2x2(
				*(*this->iVec2 * mat->iVec2->x) + *(*this->jVec2 * mat->iVec2->y),
				*(*this->iVec2 * mat->jVec2->x) + *(*this->jVec2 * mat->jVec2->y));
		}



	};
}

#endif
