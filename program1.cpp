Bresenham’s line drawing technique
Develop a program to draw a line using Bresenham’s line drawing technique

#include <GL/glut.h>
#include <stdio.h>
int x1, y1, x2, y2;

void myInit()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

void draw_pixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void draw_line(int x1, int x2, int y1, int y2)
{
    int dx, dy, i, e, x, y, incx, incy, inc1, inc2;
    dx = x2-x1;
    dy = y2-y1;
    if (dx < 0)
        dx = -dx;
    if (dy < 0)
        dy = -dy;
    
    incx = 1;
    if (x2 < x1)
        incx = -1;
    
    incy = 1;
    if (y2 < y1)
        incy = -1;
    
    x = x1; y = y1;

    if (dx > dy) 
    {
        draw_pixel(x, y);
        e = 2 * dy-dx;
        inc1 = 2*(dy-dx);
        inc2 = 2*dy;
        for (i=0; i<dx; i++) 
        {
            if (e >= 0) 
            {
                y += incy;
                e += inc1;
            }
            else
                e += inc2;
            x += incx;
            draw_pixel(x, y);
        }
    }
    else
    {
        draw_pixel(x, y);
        e = 2*dx-dy;
        inc1 = 2*(dx-dy);
        inc2 = 2*dx;
        for (i=0; i<dy; i++)
        {
            if (e >= 0)
            {
                x += incx;
                e += inc1;
            }
            else
                e += inc2;
            y += incy;
            draw_pixel(x, y);
        }
    }
}

void myDisplay() 
{
    draw_line(x1, x2, y1, y2);
    glFlush();
}

int main(int argc, char **argv)
{
    printf( "Enter (x1, y1, x2, y2)\n");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham's Line Drawing");
    myInit();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}

ALternative Code :
#include<stdio.h>
#include<math.h>
#include<iostream>
#include<GL/glut.h>

int xstart, ystart, xend, yend;
void init()
{
    gluOrtho2D(0, 500, 0, 500);
}

void draw_pixel(int x, int y)
{
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void LineBres(int xstart, int ystart, int xend, int yend)
{
    int dx = abs(xend - xstart);
    int dy = abs(yend - ystart);
    int twody = 2 * dy, twodyminusdx = 2 * (dy - dx);
    int p = 2 * dy - dx;
    int x, y;
    if (xstart > xend)
    {
        x = xend;
        y = yend;
        xend = xstart;
    }
    else
    {
        x = xstart;
        y = ystart;

    }
    draw_pixel(x, y);
    while (x < xend)
    {
        x++;
        if (p < 0)
            p += twody;
        else
        {
            y++;
            p += twodyminusdx;
        }
        draw_pixel(x, y);
    }
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0, 0, 0, 1);
    LineBres(xstart, ystart, xend, yend);
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    printf("Enter (x1, y1, x2, y2)\n");
    scanf("%d%d%d%d", &xstart, &ystart, &xend, &yend);
    glutInit(&argc, argv);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham's Line Drawing");
    init();
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}
