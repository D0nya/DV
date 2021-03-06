// DV04.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <glut.h>
#include <math.h>
#include <iostream>

using namespace std;

void init(void) {
	glClearColor(0, 0, 0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 20.0, 0.0, 20.0);

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

void circlePlotPoints(int xc, int yc, int x, int y) {
	setPixel(xc + x, yc + y);
	setPixel(xc - x, yc + y);
	setPixel(xc + x, yc - y);
	setPixel(xc - x, yc - y);
}
void OVAL(int xc, int yc, int rx, int ry) {
	int p = pow(rx, 2) - pow(rx, 2)*ry + pow(rx, 2) / 4;
	int x = 0, y = ry, constx = 2 * pow(ry, 2), consty = 2 * pow(rx, 2);
	glPointSize(2);
	while (x*constx < y * consty)
	{
		circlePlotPoints(xc, yc, x, y);
		x++;
		if (p < 0) { p += 2 * pow(ry, 2)*x + pow(ry, 2); }
		else
		{
			y--;
			p += 2 * pow(ry, 2)*x - 2 * pow(rx, 2)*y + pow(ry, 2);
		}
		cout << x << " " << y << endl;

	}
	int p2 = pow(ry*(x + 0.5), 2) + pow(rx*(y - 1), 2) - pow(rx*ry, 2);
	while (y >= 0) {
		circlePlotPoints(xc, yc, x, y);
		y--;
		if (p2 > 0)
		{
			p2 += -2 * pow(rx, 2)*y + pow(rx, 2);
		}
		else {
			x++;
			p2 += 2 * pow(ry, 2)*x - 2 * pow(rx, 2)*y + pow(rx, 2);

		}
		cout << x << " " << y << endl;
	}
}

void myDisplay(void) {
	int a, b, c, d;
	do {
		cout << "Input xc, yc, rx, ry: ";
		cin >> a >> b >> c >> d;
	} while (c <= 0 || d <= 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	OVAL(a, b, c, d);
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

