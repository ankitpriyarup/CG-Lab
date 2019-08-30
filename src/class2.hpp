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

        if (p < 0) p = p + (2 * x) + 3;
        else y--, p = p + (2 * x) - (2 * y) + 5;
        x++;
    }
}

#endif