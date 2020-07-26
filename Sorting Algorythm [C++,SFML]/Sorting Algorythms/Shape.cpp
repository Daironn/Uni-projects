#include "pch.h"
#include "Shape.h"


std::ostream & operator<<(std::ostream & os, Shape & obj)
{
	os << obj.size;
	return os;
}

Shape::Vector2f::Vector2f(float x, float y):x(x),y(y)
{
}

float Shape::Vector2f::get_x()
{
	return x;
}

float Shape::Vector2f::get_y()
{
	return y;
}
