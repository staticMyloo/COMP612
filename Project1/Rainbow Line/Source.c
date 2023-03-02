#include <freeglut.h>

void drawRainbowLine(void);

void initializeGL(void)
{
	glClearColor(0, 0, 0, 0);
	glColor3f(1.0f, 1.0f, 1.0f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Rainbow Line");
	glutDisplayFunc(drawRainbowLine);
	initializeGL();
	glutMainLoop();
}

void drawRainbowLine(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(6);
	glBegin(GL_LINES);
	glColor3f(255, 0, 0);
	glVertex2f(5, 250);//line1
	glVertex2f(75, 250);
	glColor3f(255, 127, 0);
	glVertex2f(75, 250);//line2
	glVertex2f(145, 250);
	glColor3f(255, 255, 0);
	glVertex2f(145, 250);//line3
	glVertex2f(215, 250);
	glColor3f(0, 255, 0);
	glVertex2f(215, 250);//line4
	glVertex2f(285, 250);
	glColor3f(0, 0, 255);
	glVertex2f(285, 250);//line 5
	glVertex2f(355, 250);
	glColor3f(75, 0, 130);
	glVertex2f(355, 250);//line6
	glVertex2f(425, 250);
	glColor3f(148, 0, 211);
	glVertex2f(425, 250);//line7
	glVertex2f(495, 250);
	glEnd();
	glFlush();
}

