#ifndef Class_2
#define Class_2

#include "helper.h"

void DrawCircleMidPoint(int _x, int _y, int _r)
{
    int p = 1 - _r;
    int x = 0, y = _r;
    while (x < y)
    {
        PUT_PIXEL_AROUND(_x, _y, x, y);
        PUT_PIXEL_AROUND(_x, _y, y, x);
        PUT_PIXEL_AROUND(_x, _y, y, -x);
        PUT_PIXEL_AROUND(_x, _y, x, -y);
        PUT_PIXEL_AROUND(_x, _y, -x, -y);
        PUT_PIXEL_AROUND(_x, _y, -y, -x);
        PUT_PIXEL_AROUND(_x, _y, -y, x);
        PUT_PIXEL_AROUND(_x, _y, -x, y);

        if (p < 0)
            p = p + (2 * x) + 3;
        else
            y--, p = p + (2 * x) - (2 * y) + 5;
        x++;
    }
}

void DrawEllipseMidPoint(int _a, int _b, int _x, int _y)
{
    int x = 0, y = _b;
    double p1 = (_b * _b) - (_a * _a * _b) + (0.25 * _a * _a);
    while ((2 * _b * _b * x) <= (2 * _a * _a * y))
    {
        PUT_PIXEL_AROUND(_x, _y, x, y);
        PUT_PIXEL_AROUND(_x, _y, -x, y);
        PUT_PIXEL_AROUND(_x, _y, x, -y);
        PUT_PIXEL_AROUND(_x, _y, -x, -y);

        if (p1 < 0)
        {
            x++;
            p1 += (2 * _b * _b * x) + (_b * _b);
        }
        else
        {
            x++;
            y--;
            p1 += (2 * _b * _b * x) - (2 * _a * _a * y) - (_b * _b);
        }
    }

    double p2 = ((_b * _b) * (x + 0.5) * (x + 0.5)) + ((_a * _a) * (y - 1) * (y - 1)) - (_a * _a * _b * _b);
    while (y > 0)
    {
        PUT_PIXEL_AROUND(_x, _y, x, y);
        PUT_PIXEL_AROUND(_x, _y, -x, y);
        PUT_PIXEL_AROUND(_x, _y, x, -y);
        PUT_PIXEL_AROUND(_x, _y, -x, -y);

        if (p2 > 0)
        {
            y--;
            p2 += (-2 * _a * _a * y) + (_a * _a);
        }
        else
        {
            x++;
            y--;
            p2 += (2 * _b * _b * x) - (2 * _a * _a * y) + (_a * _a);
        }
    }
}

#endif