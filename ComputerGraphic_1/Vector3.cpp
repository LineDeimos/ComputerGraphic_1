#include "Vector3.h"

Vector3::Vector3() :x(0), y(0), z(0) {}

Vector3::Vector3(double xx, double yy, double zz):x(xx),y(yy),z(zz) {}

Vector3::Vector3(const Vector3& vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
}

Vector3 Vector3::normalize()
{
	double len = length();
	if (len == 0.0f) Vector3(0.0f, 0.0f, 0.0f);
	return Vector3(x/len, y/len, z/len);
}

