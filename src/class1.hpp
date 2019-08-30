#ifndef Class_1
#define Class_1

#include "helper.h"

void DrawLineDDA(int _x1, int _y1, int _x2, int _y2)
{
    int dx = std::abs(_x2 - _x1);
    int dy = std::abs(_y2 - _y1);
    int steps = std::max(dx, dy);
    float x_inc = dx / (float) steps;
    float y_inc = dy / (float) steps;
    float x = _x1, y = _y1;
    while (steps--)
    {
        x += x_inc, y += y_inc;
        PUT_PIXEL(x, y);
    }
}

void DrawLineBresenham(int _x1, int _y1, int _x2, int _y2)
{
    int dx = std::abs(_x2 - _x1);
    int dy = std::abs(_y2 - _y1);
    float m = dy / (float)dx;
    if (m < 1)
    {
        int p = (2 * dy) - dx;
        int x = _x1, y = _y1;
        while (x < _x2)
        {
            PUT_PIXEL(x, y);
            if (p < 0) p = p + (2 * dy);
            else y++, p = p + (2 * dy) - (2 * dx);
            x++;
        }
    }
    else if (m > 1)
    {
        int p = (2 * dx) - dy;
        int x = _x1, y = _y1;
        while (y < _y2)
        {
            PUT_PIXEL(x, y);
            if (p < 0) p = p + (2 * dx);
            else x++, p = p + (2 * dx) - (2 * dy);
            y++;
        }
    }
    else DrawLineDDA(_x1, _y1, _x2, _y2);
}

#endif