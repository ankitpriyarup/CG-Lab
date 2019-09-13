#ifndef Helper
#define Helper

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>

const int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 480;
#define PUT_PIXEL(_x, _y) glVertex2f(_x/(float)SCREEN_WIDTH, _y/(float)SCREEN_HEIGHT);
#define PUT_PIXEL_AROUND(_x0, _y0, _x, _y) glVertex2f((_x0 + _x)/(float)SCREEN_WIDTH, (_y0 + _y)/(float)SCREEN_HEIGHT);

#
#endif