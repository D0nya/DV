// ZAKPALLINVANIE.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <glut.h>   
#include <math.h>
#include <iostream>

using namespace std;

void fon(){
	glClearColor(0.3, 0.0, 0.4, 1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
}

void figyra(float *x, float *y, int n) {
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < n; i++) {
		glVertex2i(x[i], y[i]);
	}
	glEnd();
	glFlush();
}

void Draw() {
	float xp, yp, *x, *y;
	int n, xmax, ymax;
	cout << "\nВведите количество вершин многоугольника: ";
	cin >> n;
	x = new float[n + 1];
	y = new float[n + 1];

	for (int i = 0; i < n; i++) {
		cout << i+1 << ". enter x: "; cin >> x[i];
		cout << "enter y: "; cin >> y[i];
	}

	glColor3f(1, 1, 1);
	//figyra(x, y, n);
	int xmin = xmax = x[0];
	int ymin = ymax = y[0];
	for (int i = 0; i < n; i++) {
		if (x[i] < xmin) { xmin = x[i]; }
		if (x[i] > xmax) { xmax = x[i]; }
		if (y[i] < ymin) { ymin = y[i]; }
		if (y[i] > ymax) { ymax = y[i]; }
	}
	glPointSize(5);
	glBegin(GL_POINTS);
	glColor3f(1, 1, 0);

	double r, g, b;
	float a, l;
	for (yp = ymax; yp >= ymin; yp += -1) {
		for (xp = xmin + 3; xp <= xmax; xp += 1) {
			int peresech = 0;
			for (int i = 0; i < n; i++) {
				a = (yp - ymin) / (xp - xmin);
				if (x[i] == x[i + 1])
				{
					if ((x[i] < xp) && ((a*x[i] + yp - a * xp) <= (y[i] <= y[i + 1] ? y[i + 1] : y[i]) && (a*x[i] + yp - a * xp) >= (y[i] > y[i + 1] ? y[i + 1] : y[i])))
						peresech++;
				}
				else {
					l = (y[i + 1] - y[i]) / (x[i + 1] - x[i]);
					float xper = (y[i] - l * x[i] - yp + a * xp) / (a - l);
					if ((xper > xmin + 1 && xper <= xp) && ((xper >= (x[i] > x[i + 1] ? x[i + 1] : x[i])) && (xper <= (x[i] < x[i + 1] ? x[i + 1] : x[i])))) {
						peresech++;
					}
				}
			}

			if (peresech % 2 == 1) {
				/*r = rand() % (10);
				g = rand() % (10);
				b = rand() % (10);*/
				glColor3f(1.0,0.0 ,0.0);
				glVertex2f(xp, yp);
			}
		}
	}
	glEnd();
	glFlush();
}

int main(int argc, char **argv){
	setlocale(LC_ALL, "RUS");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 0);
	glutCreateWindow("proj");
	fon();
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}