#pragma once
#include "Vector2.h"
class Matrix
{
	int nLines;
	int nColumns;
	double** data;

public:
	Matrix();
	Matrix(int nL, int nC);

	void setUnit();
	int getNLines() { return nLines; }
	int getNColumns() { return nColumns; }
	void multiplyMatrices(Matrix& right);
	void setRotationMatrixbySinCos(double sinalpha, double cosalpha);
	void setRotationMatrix(double alpha);
	void applyMatrixtoPoint(Vector2& point);
	void setTranslationMatrix(double tx, double ty);
	void setScaleMatrix(double sx, double sy);
};

