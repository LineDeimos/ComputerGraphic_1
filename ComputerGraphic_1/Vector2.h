#pragma once
#include <math.h>

class Vector2
{
public:
	double x, y;

	Vector2();
	Vector2(double xx, double yy);
	Vector2(const Vector2& vec);

	void set(double xx, double yy) {
		x = xx;
		y = yy;
	}
	Vector2 operator+(Vector2 vec) {
		return Vector2(x + vec.x, y + vec.y);
	}
	Vector2 operator-(Vector2 vec) {
		return Vector2(x - vec.x, y - vec.y);
	}
	Vector2 operator*(double num) {
		return Vector2(x * num, y * num);
	}
	double operator*(Vector2 vec) {
		return x * vec.x + y * vec.y;
	}
	double length() {
		return sqrt(x*x + y*y);
	}
	bool isZero() {
		return (x == 0.0f) & (y == 0.0f);
	}
	bool equals(Vector2 vec) {
		return (x == vec.x) & (y == vec.y);
	}
	Vector2 normalize();

};