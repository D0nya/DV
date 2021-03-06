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
	gluOrtho2D(0.0, 13.0, 0.0, 13.0);

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
	setPixel(xc + x, yc - y);
	setPixel(xc - x, yc + y);
	setPixel(xc - x, yc - y);
	setPixel(xc + y, yc + x);
	setPixel(xc + y, yc - x);
	setPixel(xc - y, yc + x);
	setPixel(xc - y, yc - x);
}
void circleMiddlePoint(int xc, int yc, int r) {
	int p = 1 - r;
	int x = 0, y = r;
	while (x <= y)
	{
		circlePlotPoints(xc, yc, x, y);
		x++;
		if (p < 0)
			p += 2 * x + 1;
		else
		{
			y--;
			p += 2 * (x - y) + 1;
		}
	}
}


void myDisplay(void) {
	int a, b, c;
	do {
		cout << "Input xc, yc, r: ";
		cin >> a >> b >> c;
		if (c < 0) cout << "Wrong radius!" << endl;
	} while (c < 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	if (c > 0)
	circleMiddlePoint(a, b, c);
	else setPixel(a, b);
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

