// DV2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <glut.h>
#include <cmath>
#include <iostream>

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
inline int round_k(const float a) {
	return int(a + 0.5);
}
void lineCDA(int x0, int y0, int xend, int yend) {
	int dx = xend - x0, dy = yend - y0, step, k;
	float xInc, yInc, x = x0, y = y0;
	step = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
	xInc = float(dx) / float(step);
	yInc = float(dy) / float(step);
	setPixel(round_k(x), round_k(y));
	for (k = 0; k < step; k++) {
		x += xInc;
		y += yInc;
		setPixel(round_k(x), round_k(y));
		std::cout << k + 1 << ".  " << "x  " << round_k(x) << "    " << "Y  " << round_k(y) << std::endl;
	}
}
void myDisplay(void) {
	int a, b, c, d;
	std::cout << "Input x0, y0, xend, yend: ";
	std::cin >> a >> b >> c >> d;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	lineCDA(a, b , c ,d);
}
void main(int argc, char** argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 100);
	glutInitWindowSize(400, 300);
	glutCreateWindow("Пример ");
	init();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}
