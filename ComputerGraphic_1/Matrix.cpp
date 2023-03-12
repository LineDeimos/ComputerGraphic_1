#include "Matrix.h"
#include <math.h>
#include <memory.h>

Matrix::Matrix() :nLines(0), nColumns(0) {}

Matrix::Matrix(int nL, int nC):nLines(nL),nColumns(nC)
{
	data = new double*[nL];

	for (int i = 0; i < nL; i++) {
		data[i] = new double[nC];
		for (int j = 0; j < nC; j++) {
			data[i][j] = 0.0;
		}
	}

	for (int i = 0; i < fmin(nL, nC); i++) {
		data[i][i] = 1.0;
	}
}

void Matrix::setUnit() {
	for (int i = 0; i < nLines; i++) {
		for (int j = 0; j < nColumns; j++) {
			data[i][j] = 0.0;
		}
	}
	for (int i = 0; i < fmin(nLines, nColumns); i++) {
		data[i][i] = 1.0;
	}
}

void Matrix::setRotationMatrixbySinCos(double sinalpha, double cosalpha) {
	setUnit();
	data[0][0] = cosalpha;
	data[0][1] = sinalpha;
	data[1][0] = -sinalpha;
	data[1][1] = cosalpha;
}

void Matrix::setRotationMatrix(double alpha) {
	setRotationMatrixbySinCos(sin(alpha), cos(alpha));
}

void Matrix::multiplyMatrices(Matrix& right) {
	if (nColumns != right.getNLines()) return;
	double temp[3][3];
	double val;
	memcpy(temp, data, sizeof(data));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			val = 0;
			for (int v = 0; v < 3; v++) {
				val += temp[i][v] * right.data[v][j];
			}
			data[i][j] = val;
		}
	}
}

void Matrix::applyMatrixtoPoint(Vector2& point) {
	double _x, _y;
	_x = point.x;
	_y = point.y;
	point.x = _x * data[0][0] + _y * data[1][0] + data[2][0];
	point.y = _x * data[0][1] + _y * data[1][1] + data[2][1];
}

void Matrix::setTranslationMatrix(double tx, double ty) {
	setUnit();
	data[2][0] = tx;
	data[2][1] = ty;
}

void Matrix::setScaleMatrix(double sx, double sy)
{
	setUnit();
	data[0][0] = sx;
	data[1][1] = sy;
}
