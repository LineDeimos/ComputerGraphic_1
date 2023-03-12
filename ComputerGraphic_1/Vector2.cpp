#include "Vector2.h"

Vector2::Vector2() :x(0), y(0) {}

Vector2::Vector2(double xx, double yy) :x(xx), y(yy) {}

Vector2::Vector2(const Vector2& vec)
{
	x = vec.x;
	y = vec.y;
}

Vector2 Vector2::normalize()
{
	double len = length();
	if (len == 0.0f) return Vector2(0.0f, 0.0f);
	return Vector2(x/len, y/len);
}
