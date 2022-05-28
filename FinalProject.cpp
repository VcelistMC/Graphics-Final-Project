#include <Windows.h>
#include <math.h>
#include "Shape.h"
#include "Circle.h"
#include "Circle.cpp"
#include "Shape.cpp"
#include <string>
#include "MidPointCircle.h"
#include "MidPointCircle.cpp"
#include "PolarCircle.cpp"
#include "PolarCircle.h"
#include "IterativePolarCircle.h"
#include "IterativePolarCircle.cpp"
#include "ModifiedMidPointCircle.cpp"
#include "ModifiedMidPointCircle.h"

constexpr auto DRAW_BTN = 3;
constexpr auto CLEAR_BTN = 4;

LRESULT WINAPI MyWndProc(HWND hwnd, UINT mcode, WPARAM wp, LPARAM lp)
{
    static HDC hdc;
    static HGLRC glrc;
    static Shape *currShape;
    static int numOfPoints;
    static int currNumOfPoints;
    static bool currentlyDrawing = false;
    static std::vector<POINT> points;
    switch (mcode)
    {
    case WM_CREATE:
        hdc = GetDC(hwnd);
        break;
    case WM_COMMAND:
        switch (wp)
        {
        case DRAW_BTN:
            if (!currentlyDrawing)
            {
                currentlyDrawing = true;
                points.clear();
                currShape = new ModifiedMidPointCircle;
                numOfPoints = currShape->getMinNumOfPoints();
                currNumOfPoints = 0;
                return 0;
            }
        case CLEAR_BTN:
            RedrawWindow(hwnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_UPDATENOW);
            return 0;
        default:
            break;
        }
    case WM_LBUTTONDOWN:
        if (currentlyDrawing)
        {
            if (currNumOfPoints < numOfPoints)
            {
                POINT p;
                GetCursorPos(&p);
                ScreenToClient(hwnd, &p);
                points.push_back(p);
;               currNumOfPoints++;
            }
            if (currNumOfPoints == numOfPoints)
            {
                currShape->setPoints(points);
                currShape->draw(hdc, RGB(255,255,255));
                currentlyDrawing = false;
                //glFlush();
                //SwapBuffers(hdc);
            }
        }
        break;
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
    case WM_DESTROY:
        ReleaseDC(hwnd, hdc);
        PostQuitMessage(0);
        break;
    default: return DefWindowProc(hwnd, mcode, wp, lp);
    }
    return 0;
}
int APIENTRY WinMain(HINSTANCE hinst, HINSTANCE pinst, LPSTR cmd, int nsh)
{
    WNDCLASS wc;
    wc.cbClsExtra = wc.cbWndExtra = 0;
    wc.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hInstance = hinst;
    wc.lpfnWndProc = MyWndProc;
    wc.lpszClassName = L"MyClass";
    wc.lpszMenuName = NULL;
    wc.style = CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&wc);
    HWND hwnd = CreateWindow(L"MyClass", L"My First Window", WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, 0, 0, 800, 600, NULL, NULL, hinst, 0);
    CreateWindowW(
        L"Button",
        L"Draw",
        WS_VISIBLE | WS_CHILD,
        500,
        200,
        100,
        100,
        hwnd,
        (HMENU) DRAW_BTN,
        NULL,
        NULL
    );
    CreateWindowW(
        L"Button",
        L"Clear",
        WS_VISIBLE | WS_CHILD,
        0,
        0,
        100,
        100,
        hwnd,
        (HMENU)CLEAR_BTN,
        NULL,
        NULL
    );
    ShowWindow(hwnd, nsh);
    UpdateWindow(hwnd);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}