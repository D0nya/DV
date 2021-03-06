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
	gluOrtho2D(0.0, 200.0, 0.0, 200.0);

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

void circlePlotPointsRAD(int xc, int yc, int x, int y, int r) {
	setPixel(xc + x, yc + y + r);
	setPixel(xc + x, yc - y - r);
	setPixel(xc - x, yc + y + r);
	setPixel(xc - x, yc - y - r);
	setPixel(xc + y, yc + x + r);
	setPixel(xc + y, yc - x - r);
	setPixel(xc - y, yc + x + r);
	setPixel(xc - y, yc - x - r);
}

void circlePlotPointsrad(int xc, int yc, int x, int y, int r) {
	setPixel(xc + x, yc + y - r );
	setPixel(xc + x, yc - y + r );
	setPixel(xc - x, yc + y - r );
	setPixel(xc - x, yc - y + r );
	setPixel(xc + y, yc + x - r);
	setPixel(xc + y, yc - x + r);
	setPixel(xc - y, yc + x - r );
	setPixel(xc - y, yc - x + r );
}

void drawLines(int xc, int yc, int R, int r) {
	int x = xc - R;
	int y1 = yc + r;
	int y2 = yc - r;
	while (x <= xc + R) {
		setPixel(x, y1);
		setPixel(x, y2);
		x++;
	}
}

void circleMiddlePoint(int xc, int yc, int r, int R) {
	int p1 = 1 - r;
	int p2 = 1 - R;
	int x = 0, y = R;
	while (x <= y)
	{
		circlePlotPointsRAD(xc, yc, x, y, r);
		x++;
		if (p1 < 0)
			p1 += 2 * x + 1;
		else
		{
			y--;
			p1 += 2 * (x - y) + 1;
		}
	}
	x = 0; y = r;
	while (x <= y)
	{
		circlePlotPointsrad(xc, yc, x, y, r);
		x++;
		if (p1 < 0)
			p1 += 2 * x + 1;
		else
		{
			y--;
			p1 += 2 * (x - y) + 1;
		}
	}
	drawLines(xc, yc, R, r);
}


void myDisplay(void) {
	int a, b, c, d, i = 1;
	do {
		cout << "Input R, r: ";
		cin >> d >> c;
		a = 2*c ;
		b = 200 - (d + c);
		if (c <= 0 || d <= 0) cout << "Wrong radius!" << endl;
	} while (c <= 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	circleMiddlePoint(a, b, c, d);
	while (b - i * (2 * d + 2 * c) >= c + d){
		circleMiddlePoint(a, b - i * (2 * d + 2 * c), c, d);
		i++;
	} 
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Пример ");
	init();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}

