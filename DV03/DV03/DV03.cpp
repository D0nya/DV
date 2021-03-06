// DV03.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <glut.h>
#include <math.h>
#include <iostream>

using namespace std;

void init(void) {
	glClearColor(0, 0, 0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
	
	

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

}
void setPixel(int x, int y) {
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void linesBrasenhem(int x0, int y0, int xend, int yend) {
	int dx = abs(xend - x0), dy = abs(yend - y0);
	int p;
	int x, y;

	if (dy <= dx) {
		p = 2 * dy - dx;
		if (x0 > xend) {
			x = xend;
			y = yend;
			xend = x0;
		}
		else
		{
			x = x0;
			y = y0;
		}
		setPixel(x, y);
		while (x < xend) {
			x++;
			if (p < 0)
				p += 2 * dy;
			else
			{
				y++;
				p += 2 * (dy - dx);
			}
			setPixel(x, y);
		}
	}

	else if (dy > dx) {
		p = 2 * dx - dy;
		if (y0 > yend) {
			x = xend;
			y = yend;
			yend = y0;
		}
		else {
			x = x0;
			y = y0;
		}
		setPixel(x, y);
		while (y < yend) {
			y++;
			if (p < 0)
				p += 2 * dx;
			else
			{
				if (y0 == yend) x--;
				else x++;
				p += 2 * (dx - dy);
			}
			setPixel(x, y);
		}
	}

	else if (dy == 0) {
		x = x0; y = y0;
		while (x < xend) {
			setPixel(x, y);
			x++;
		}
	}

	else if (dx == 0) {
		x = x0; y = y0;
		while (y < yend) {
			setPixel(x, y);
			y++;
		}
	}
}

void myDisplay(void) {
	int a, b, c, d;
	cout << "Input x0, y0, xend, yend: ";
	cin >> a >> b >> c >> d;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	linesBrasenhem(a, b, c, d);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 100);
	glutInitWindowSize(300, 300);
	glutCreateWindow("Пример ");
	init();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}

