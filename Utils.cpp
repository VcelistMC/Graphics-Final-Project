#pragma once
#include "Utils.h"
#include <Windows.h>
#include <math.h>
class Utils
{
public:
	static void swap(int& x1, int& y1, int& x2, int& y2)
    {
        int tmp = x1;
        x1 = x2;
        x2 = tmp;
        tmp = y1;
        y1 = y2;
        y2 = tmp;
    }
    static void swap(POINT &p1, POINT &p2)
    {
        int tmp = p1.x;
        p1.x = p2.x;
        p2.x = tmp;
        tmp = p1.y;
        p1.y = p2.y;
        p2.y = tmp;
    }
    static int Round(double x)
    {
        return (int)(x + 0.5);
    }
    static int distanceBetweenPoints(POINT& p1, POINT& p2)
    {
        return Round(sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)));
    }
};