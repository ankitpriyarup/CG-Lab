#ifndef Class_3
#define Class_3

#include "helper.h"

void FloodFill(int _x, int _y, Color _oldColor, Color _newColor)
{
    Color color;
    color = getPixelColor(_x, _y);

    if (color == _oldColor)
    {
        setPixelColor(_x, _y, _newColor);
        FloodFill(_x + 1, _y, _oldColor, _newColor);
        FloodFill(_x, _y + 1, _oldColor, _newColor);
        FloodFill(_x - 1, _y, _oldColor, _newColor);
        FloodFill(_x, _y - 1, _oldColor, _newColor);
    }
    return;
}

void BoundaryFill(int _x, int _y, Color _fill_color, Color _boundary_color, bool eightWay = true)
{
	Color color;
    color = getPixelColor(_x, _y);

	if (color != _boundary_color && color != _fill_color)
	{
		setPixelColor(_x, _y, _fill_color);
		BoundaryFill(_x + 1, _y, _fill_color, _boundary_color, eightWay);
		BoundaryFill(_x - 1, _y, _fill_color, _boundary_color, eightWay);
		BoundaryFill(_x, _y + 1, _fill_color, _boundary_color, eightWay);
		BoundaryFill(_x, _y - 1, _fill_color, _boundary_color, eightWay);
		if (eightWay)
		{
			BoundaryFill(_x + 1, _y + 1, _fill_color, _boundary_color, eightWay);
			BoundaryFill(_x - 1, _y + 1, _fill_color, _boundary_color, eightWay);
			BoundaryFill(_x + 1, _y - 1, _fill_color, _boundary_color, eightWay);
			BoundaryFill(_x - 1, _y - 1, _fill_color, _boundary_color, eightWay);
		}
	}
}

#endif