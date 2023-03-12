#include "Engine.h"

Engine::Engine()
{
}

void Engine::setActiveLine(int nLine)
{
	activeLine = nLine;
}

void Engine::draw(HDC hdc)
{
	MoveToEx(hdc, line[1][0].x, line[1][0].y, NULL);
	LineTo(hdc, line[1][1].x, line[1][1].y);

	createLine(line[0][0].x, line[0][0].y, line[0][1].x, line[0][1].y, hdc, 0x008000);
}

void Engine::rot(int z)
{
	matrix.setTranslationMatrix(-(line[activeLine][0].x + line[activeLine][1].x) / 2, -(line[activeLine][0].y + line[activeLine][1].y) / 2);
	supMatrix.setTranslationMatrix((line[activeLine][0].x + line[activeLine][1].x) / 2, (line[activeLine][0].y + line[activeLine][1].y) / 2);
	for (int i = 0; i < 2; i++)
		matrix.applyMatrixtoPoint(line[activeLine][i]);
	matrix.setRotationMatrix(z);
	for (int i = 0; i < 2; i++)
		matrix.applyMatrixtoPoint(line[activeLine][i]);
	for (int i = 0; i < 2; i++)
		supMatrix.applyMatrixtoPoint(line[activeLine][i]);
}

void Engine::move(double x, double y)
{
	matrix.setTranslationMatrix(x, y);
	for (int i = 0; i < 2; i++)
		matrix.applyMatrixtoPoint(line[activeLine][i]);
}

void Engine::scale(double x, double y)
{
	matrix.setTranslationMatrix(-(line[activeLine][0].x + line[activeLine][1].x) / 2, -(line[activeLine][0].y + line[activeLine][1].y) / 2);
	supMatrix.setTranslationMatrix((line[activeLine][0].x + line[activeLine][1].x) / 2, (line[activeLine][0].y + line[activeLine][1].y) / 2);
	for (int i = 0; i < 2; i++)
		matrix.applyMatrixtoPoint(line[activeLine][i]);
	matrix.setScaleMatrix(x, y);
	for (int i = 0; i < 2; i++)
		matrix.applyMatrixtoPoint(line[activeLine][i]);
	for (int i = 0; i < 2; i++)
		supMatrix.applyMatrixtoPoint(line[activeLine][i]);
}

void Engine::createLine(double _x1, double _y1, double _x2, double _y2, HDC hdc, COLORREF color)
{
	int x1 = round(_x1);
	int x2 = round(_x2);
	int y1 = round(_y1);
	int y2 = round(_y2);
	int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
	int dy = abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
	int err = (dx > dy ? dx : -dy) / 2;
	int e2 = err;
	for (;;)
	{
		SetPixel(hdc, x1, y1, color);
		if (x1 == x2 && y1 == y2) break;
		e2 = err;
		if (e2 > -dx)
			err -= dy, x1 += sx;
		if (e2 < dy)
			err += dx, y1 += sy;
	}
}