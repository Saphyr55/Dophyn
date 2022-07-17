#include "utils/matrix.hpp"

namespace matrix
{

	template<typename T>
	vector::Vec2<T>* matrix::Mat2x2<T>::application(T x, T y)
	{
		return new vector::Vec2<T>(
			this->iVec2->x * x + this->iVec2->y * x,
			this->iVec2->x * y + this->iVec2->y * y
			);
	}

	template<typename T>
	Mat2x2<T>* matrix::Mat2x2<T>::inverse()
	{
		return
			Mat2x2(
				this->jVec2->y, -this->iVec2->y,
				-this->jVec2->x, this->iVec2->x
			) * (1 / this->determinant()
				);
	}

	template<typename T>
	bool Mat2x2<T>::isInversible()
	{
		return this->determinant() != 0;
	}

	template<typename T>
	T Mat2x2<T>::determinant()
	{
		return (this->iVec2->x * this->jVec2->y) -
			(this->jVec2->x * this->iVec2->y);
	}
}