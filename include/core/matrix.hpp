#ifndef VECTOR_H
#define VECTOR_H

#include "vector.hpp"

namespace matrix
{
	class Mat2x2
	{

	public:
		vector::Vec2Float *iVec2;
		vector::Vec2Float *jVec2;

		Mat2x2(float a, float c, float b, float d);
		Mat2x2(vector::Vec2Float *iVec2, vector::Vec2Float *jVec2);

		vector::Vec2Float *application(float x, float y);
		float determinant();
		bool isInversible();
		Mat2x2 *inverse();

		Mat2x2 *operator*(const float a) const
		{
			return new Mat2x2(*this->iVec2 * a, *this->jVec2 * a);
		}

		Mat2x2 *operator*(const Mat2x2 *mat) const
		{
			return new Mat2x2(
				*(*this->iVec2 * mat->iVec2->x) + *(*this->jVec2 * mat->iVec2->y),
				*(*this->iVec2 * mat->jVec2->x) + *(*this->jVec2 * mat->jVec2->y));
		}
	};
}

#endif
