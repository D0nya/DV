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
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

}
void setPixel(int x, int y, int size) {
	glPointSize(size);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void circlePlotPoints(int xc, int yc, int x, int y, int key) {
	switch (key) {
	case 0:	setPixel(xc + x, yc + y, 3);
		break;
	case 1: setPixel(xc - x, yc - y, 3);
		break;
	case 2:	setPixel(xc + x, yc - y, 3);
		break;
	case 3: setPixel(xc - x, yc + y, 3);
		break;
	}
}
void OVAL(int xc, int yc, int rx, int ry, int key) {
	int p = pow(rx, 2) - pow(rx, 2)*ry + pow(rx, 2) / 4;
	int x = 0, y = ry, constx = 2 * pow(ry, 2), consty = 2 * pow(rx, 2);
	glPointSize(2);
	while (x*constx < y * consty)
	{
		circlePlotPoints(xc, yc, x, y, key);
		x++;
		if (p < 0) { p += 2 * pow(ry, 2)*x + pow(ry, 2); }
		else
		{
			y--;
			p += 2 * pow(ry, 2)*x - 2 * pow(rx, 2)*y + pow(ry, 2);
		}

	}
	int p2 = pow(ry*(x + 0.5), 2) + pow(rx*(y - 1), 2) - pow(rx*ry, 2);
	while (y >= 0) {
		circlePlotPoints(xc, yc, x, y, key);
		y--;
		if (p2 > 0)
		{
			p2 += -2 * pow(rx, 2)*y + pow(rx, 2);
		}
		else {
			x++;
			p2 += 2 * pow(ry, 2)*x - 2 * pow(rx, 2)*y + pow(rx, 2);

		}
	}
}


void myDisplay(void) {
	int x, y, r1, r2, key = 0, i = 0;
	const float pi = 3.1415926535;

	cout << "Masstab: "; cin >> x;
	r2 = x * pi;
	r1 = (pi / 2) * x;


	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	x = 250; y = 250;

	while (x + i * r1 <= 500) {
		switch (key) {
		case 0: case 2:	OVAL(x + i * r1, y, r1, r2, key);
			break;
		case 3: case 1:	OVAL(x + i * r1 + r1, y, r1, r2, key);
			break;
		}

		key++; i++;

		if (key > 3)
			key = 0;
	}

	i = 0; x = 250; key = 3;
	while (x + i * r1 <= 500) {
		switch (key) {
		case 0: case 2:	OVAL(x - i * r1 - r1, y, r1, r2, key);
			break;
		case 3: case 1:	OVAL(x - i * r1, y, r1, r2, key);
			break;
		}

		key--; i++;

		if (key < 0)
			key = 3;
	}


	x = 0; y = 250;
	while (x <= 500) {
		setPixel(x, y, 1);
		x++;
	}
	x = 250; y = 0;
	while (y <= 500) {
		setPixel(x, y, 1);
		y++;
	}

}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 100);
	glutInitWindowSize(500, 300);
	glutCreateWindow("Пример ");
	init();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}

