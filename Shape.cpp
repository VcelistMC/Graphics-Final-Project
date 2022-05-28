#pragma once
#include "Shape.h"
#include <vector>
#include <Windows.h>

class Shape
{
protected:
	std::vector<POINT> points;
public:
	void setPoints(std::vector<POINT> points) {
		this->points = points;
	}

	virtual int getMinNumOfPoints() = 0;
	virtual void draw(HDC hdc, COLORREF c) = 0;
};
