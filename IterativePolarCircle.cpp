#include "IterativePolarCircle.h"
#include <math.h>
#include <Windows.h>
#include "Utils.cpp"
#include <vector>
#include "Circle.cpp"
#include "shape.cpp"

class IterativePolarCircle : public Circle {
public:
    void draw(HDC hdc, COLORREF c)
    {
        int radius = Utils::distanceBetweenPoints(points[0], points[1]);
        draw(hdc, points[0].x, points[0].y, radius, c);
    }
    void draw(HDC hdc, int xc, int yc, int R, COLORREF color)
    {
        double x = R, y = 0;
        double dtheta = 1.0 / R;
        double cdtheta = cos(dtheta), sdtheta = sin(dtheta);
        Draw8Points(hdc, xc, yc, R, 0, color);
        while (x > y)
        {
            double x1 = x * cdtheta - y * sdtheta;
            y = x * sdtheta + y * cdtheta;
            x = x1;
            Draw8Points(hdc, xc, yc, round(x), round(y), color);
        }
    }
};