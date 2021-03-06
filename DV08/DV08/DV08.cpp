
#include "stdafx.h"
#include <glut.h>  
#include <math.h>
#include <iostream>
#include <stdio.h>
using namespace std;

void Initialize()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
}

void syskoord(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex2f(100, 0);
	glVertex2f(-100, 0);
	glVertex2f(0, 100);
	glVertex2f(0, -100);
	glEnd();
	glFlush();

}

void Circle(void)
{
	syskoord();

	glLineWidth(3);
	int i;
	int x[4] = { -10, 10, 45, 0 };
	int y[4] = { -10, 16, 30, 0 };
	x[3] = x[0];
	y[3] = y[0];
	int xnew[4] = { 0, 0, 0, 0 };
	int ynew[4] = { 0, 0, 0, 0 };
	float ugol;
	xnew[3] = x[0];
	ynew[3] = y[0];
	xnew[0] = x[0];
	ynew[0] = y[0];

	cout << "Roation angle: ";
	cin >> ugol;
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 0);
	for (int i = 0; i < 4; i++)
	{
		glVertex2f(x[i], y[i]);
	}
	glEnd();
	glFlush();
	
	// Поворот //
	for (int i = 1; i < 3; i++)
	{
		xnew[i] = x[0] + (x[i] - x[0])*cos(ugol*3.14 / 180) - (y[i] - y[0])*sin(ugol*3.14 / 180);
		ynew[i] = y[0] + (x[i] - x[0])*sin(ugol*3.14 / 180) + (y[i] - y[0])*cos(ugol*3.14 / 180);
	}

	// Новая фигура // 
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 1);
	for (int i = 0; i < 4; i++)
	{
		glVertex2f(xnew[i], ynew[i]);
	}
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowSize(400, 400);	
	glutInitWindowPosition(0, 0);	
	glutCreateWindow("LABA 1");		
	Initialize();				
	glutDisplayFunc(Circle);
	glutMainLoop(); 
	return 0;
}