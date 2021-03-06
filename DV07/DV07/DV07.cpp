// DV04.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <glut.h>
#include <math.h>
#include <iostream>

using namespace std;

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-250.0, 250.0, -250.0, 250.0);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
}

void smooth(void) {
	glShadeModel(GL_SMOOTH);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2i(-80, 130);
	glVertex2i(80, 130);

	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(80, 240);
	glVertex2i(-80, 240);

	glEnd();
	glFlush();
}

void pattern(void) {
	glLineWidth(7);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(2, 58360);

	glBegin(GL_LINE_STRIP);

	glColor3f(1.0, 1.0, 0.0);
	glVertex2i(0, -100);
	glVertex2i(100, 0);
	glVertex2i(140, 40);
	glVertex2i(120, 100);
	glVertex2i(80, 120);
	glVertex2i(40, 120);
	glVertex2i(0, 100);



	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(0, -100);
	glVertex2i(-100, 0);
	glVertex2i(-140, 40);
	glVertex2i(-120, 100);
	glVertex2i(-80, 120);
	glVertex2i(-40, 120);
	glVertex2i(0, 100);

	glEnd();
	glFlush();

	glLineWidth(5);
	glDisable(GL_LINE_STIPPLE);
}

void myDisplay(void) {
	pattern();
	smooth();
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Пример ");
	init();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}

