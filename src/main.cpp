#ifndef Main
#define Main

#include "helper.h"
#include "class1.hpp"
#include "class2.hpp"

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.0, 0.0);

    glBegin(GL_POINTS);
    DrawLineDDA(300, 200, 400, 400);
    DrawLineBresenham(300, 200, 700, 400);
    DrawLineBresenham(400, 200, 500, 450);
    DrawCircleMidPoint(340, 240, 50);
    DrawEllipseMidPoint(150, 40, 450, 120);
    glEnd();

    glFlush();
}

void init (void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (SCREEN_WIDTH, SCREEN_HEIGHT);
    glutCreateWindow ("CG Lab");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

#endif
