#include "core/matrix.hpp"

matrix::Mat2x2::Mat2x2(vector::Vec2Float *iVec2, vector::Vec2Float *jVec2)
{
	this->iVec2 = iVec2;
	this->jVec2 = jVec2;
}

matrix::Mat2x2::Mat2x2(float a, float c, float b, float d)
{
	this->iVec2 = new vector::Vec2Float(a, c);
	this->jVec2 = new vector::Vec2Float(b, d);
}

vector::Vec2Float* matrix::Mat2x2::application(float x, float y)
{
	return new vector::Vec2Float(
		this->iVec2->x * x + this->iVec2->y * x,
		this->iVec2->x * y + this->iVec2->y * y
	);
}

matrix::Mat2x2* matrix::Mat2x2::inverse()
{
	return
		Mat2x2(	
			this->jVec2->y, -this->iVec2->y,
			-this->jVec2->x, this->iVec2->x
		) * (1 / this->determinant()
	);
}

bool matrix::Mat2x2::isInversible()
{
	return this->determinant() != 0;
}

float matrix::Mat2x2::determinant()
{
	return (this->iVec2->x * this->jVec2->y) - 
		   (this->jVec2->x * this->iVec2->y);
}