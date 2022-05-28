#include "MidPointCircle.h"
#include <math.h>
#include <Windows.h>
#include "Utils.cpp"
#include <vector>
#include "Circle.cpp"
#include "shape.cpp"

class MidPointCircle : public Circle {
public:
    void draw(HDC hdc, COLORREF c)
    {
        int radius = Utils::distanceBetweenPoints(points[0], points[1]);
        draw(hdc, points[0].x, points[0].y, radius, c);
    }
    virtual void draw(HDC hdc, int xc, int yc, int R, COLORREF color)
    {
        int x = 0, y = R;
        int d = 1 - R;
        Draw8Points(hdc, xc, yc, x, y, color);
        while (x < y)
        {
            if (d < 0)
                d += 2 * x + 2;
            else
            {
                d += 2 * (x - y) + 5;
                y--;
            }
            x++;
            Draw8Points(hdc, xc, yc, x, y, color);
        }
    }
};

