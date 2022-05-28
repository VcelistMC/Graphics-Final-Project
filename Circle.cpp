#pragma once
#include "Circle.h"
#include <math.h>
#include <Windows.h>
#include "Utils.cpp"
#include <vector>
#include "Shape.cpp"


class Circle : public Shape
{
protected:
    void Draw8Points(HDC hdc, int xc, int yc, int x, int y, COLORREF c)
    {
        SetPixel(hdc, xc + x, yc + y, c);
        SetPixel(hdc, xc + x, yc - y, c);
        SetPixel(hdc, xc - x, yc - y, c);
        SetPixel(hdc, xc - x, yc + y, c);
        SetPixel(hdc, xc + y, yc + x, c);
        SetPixel(hdc, xc + y, yc - x, c);
        SetPixel(hdc, xc - y, yc - x, c);
        SetPixel(hdc, xc - y, yc + x, c);
    }
public:
    int getMinNumOfPoints() { return 2; }
    virtual void draw(HDC hdc, COLORREF c)
    {
        int radius = Utils::distanceBetweenPoints(points[0], points[1]);
        draw(hdc, points[0].x, points[0].y, radius, c);
    }
    void draw(HDC hdc, int xc, int yc, int R, COLORREF c)
    {
        int x = 0;
        double y = R;
        Draw8Points(hdc, xc, yc, 0, R, c);
        while (x < y)
        {
            x++;
            y = sqrt((double)R * R - x * x);
            Draw8Points(hdc, xc, yc, x, Utils::Round(y), c);
        }
    }
};