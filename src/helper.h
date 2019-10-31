#ifndef Helper
#define Helper

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>

class Color
{
public:
    GLfloat r, g, b;
    bool operator== (Color& a)
    {
        return (a.r == r && a.g == g && a.b == b);
    }
    bool operator!= (Color &a)
    {
        return !operator==(a);
    }
};

const int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 480;
const Color COLOR_RED = {1.0f, 0.0f, 0.0f};
const Color COLOR_GREEN = {0.0f, 1.0f, 0.0f};
const Color COLOR_BLUE = {0.0f, 0.0f, 1.0f};
const Color COLOR_WHITE = {1.0f, 1.0f, 1.0f};
const Color COLOR_BLACK = {0.0f, 0.0f, 0.0f};
#define PUT_PIXEL(_x, _y) glVertex2i(_x, _y);
#define PUT_PIXEL_AROUND(_x0, _y0, _x, _y) glVertex2i(_x0 + _x, _y0 + _y);

Color getPixelColor(GLint x, GLint y)
{
    Color color;
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
    return color;
}

void setPixelColor(GLint x, GLint y, Color color)
{
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

#endif