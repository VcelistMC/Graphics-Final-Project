#include "PolarCircle.h"
#include <math.h>
#include <Windows.h>
#include "Utils.cpp"
#include <vector>
#include "Circle.cpp"
#include "shape.cpp"

class PolarCircle : public Circle {
public:
    void draw(HDC hdc, COLORREF c)
    {
        int radius = Utils::distanceBetweenPoints(points[0], points[1]);
        draw(hdc, points[0].x, points[0].y, radius, c);
    }
    void draw(HDC hdc, int xc, int yc, int R, COLORREF color)
    {
        int x = R, y = 0;
        double theta = 0, dtheta = 1.0 / R;
        Draw8Points(hdc, xc, yc, x, y, color);
        while (x > y)
        {
            theta += dtheta;
            x = round(R * cos(theta));
            y = round(R * sin(theta));
            Draw8Points(hdc, xc, yc, x, y, color);
        }
    }

};
