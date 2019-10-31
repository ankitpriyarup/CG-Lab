#ifndef Main
#define Main

#include "helper.h"
#include "class1.hpp"
#include "class2.hpp"
#include "class3.hpp"

void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
}

void onMouseClick(int button, int state, int x, int y)
{
    if (button == 0)
        FloodFill(101, 199, COLOR_WHITE, COLOR_RED);
    else
        BoundaryFill(101, 199, COLOR_GREEN, COLOR_BLACK, false);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);

    // DrawLineDDA(300, 200, 400, 400);
    // DrawLineBresenham(300, 200, 700, 400);
    // DrawLineBresenham(400, 200, 500, 450);
    // DrawCircleMidPoint(340, 240, 50);
    // DrawEllipseMidPoint(150, 40, 450, 120);

    DrawLineDDA(100, 100, 200, 100);
    DrawLineDDA(200, 100, 200, 200);
    DrawLineDDA(100, 200, 200, 200);
    DrawLineDDA(100, 100, 100, 200);

    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("CG-Lab");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(onMouseClick);
    glutMainLoop();
    return 0;
}

#endif