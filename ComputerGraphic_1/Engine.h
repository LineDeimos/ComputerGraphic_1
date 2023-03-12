#pragma once
#include <windows.h>
#include "Vector2.h"
#include "Matrix.h"

class Engine
{
	Vector2 line[2][2] = { { {50, 50}, {150, 50} },
						 { {50, 100}, {150, 100} } };

	Matrix matrix = { 3, 3 };
	Matrix supMatrix = { 3, 3 };
	int activeLine = 0;

public:

	Engine();

	void setActiveLine(int nLine);
	void draw(HDC hdc);
	void rot(int z);
	void move(double x, double y);
	void scale(double x, double y);
	void createLine(double _x1, double _y1, double _x2, double _y2, HDC hdc, COLORREF color);
};

