#include <math.h>
#include <Windows.h>
#include "Utils.cpp"
#include <vector>
#include "Circle.cpp"
#include "shape.cpp"

class ModifiedMidPointCircle : public Circle {
public:
    void draw(HDC hdc, COLORREF c)
    {
        int radius = Utils::distanceBetweenPoints(points[0], points[1]);
        draw(hdc, points[0].x, points[0].y, radius, c);
    }
    void draw(HDC hdc, int xc, int yc, int R, COLORREF color)
    {
        int x = 0, y = R;
        int d = 1 - R;
        int c1 = 3, c2 = 5 - 2 * R;
        Draw8Points(hdc, xc, yc, x, y, color);
        while (x < y)
        {
            if (d < 0)
            {
                d += c1;
                c2 += 2;
            }
            else
            {
                d += c2;
                c2 += 4;
                y--;
            }
            c1 += 2;
            x++;
            Draw8Points(hdc, xc, yc, x, y, color);
        }
    }
};