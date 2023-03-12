#pragma once
#include <math.h>

class Vector3
{
public:
	double x, y, z;

	Vector3();
	Vector3(double xx, double yy, double zz);
	Vector3(const Vector3& vec);

	void set(double xx, double yy, double zz) {
		x = xx;
		y = yy;
		z = zz;
	}
	Vector3 operator+(Vector3 vec) {
		return Vector3(x + vec.x, y + vec.y, z + vec.z);
	}
	Vector3 operator-(Vector3 vec) {
		return Vector3(x - vec.x, y - vec.y, z - vec.z);
	}
	Vector3 operator*(double num) {
		return Vector3(x * num, y * num, z * num);
	}
	double operator*(Vector3 vec) {
		return x * vec.x + y * vec.y + z * vec.z;
	}
	double length() {
		return sqrt(x * x + y * y + z * z);
	}
	bool isZero() {
		return (x == 0.0f) & (y == 0.0f) & (z == 0.0f);
	}
	bool equals(Vector3 vec) {
		return (x == vec.x) & (y == vec.y) & (z == vec.z);
	}
	Vector3 normalize();

};