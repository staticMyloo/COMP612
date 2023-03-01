#include <freeglut.h>

void drawTriangle(void);

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
	glutInitWindowPosition(250, 250);
	glutCreateWindow("Colourful T");
	glutDisplayFunc(drawTriangle);
	initializeGL();
	glutMainLoop();
}

void drawTriangle(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	// bottom 'square'
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2i(275, 50);
	glColor3f(1, 0, 0);
	glVertex2i(275, 450);
	glColor3f(1, 0, 0);
	glVertex2i(225, 450); 
	glColor3f(1, 1, 0);
	glVertex2i(225, 50);
	glEnd();
	// top 'square'
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex2i(0, 450);
	glColor3f(0, 0, 1);
	glVertex2i(0, 500);
	glColor3f(0, 0, 1);
	glVertex2i(500, 500);
	glColor3f(1, 0, 0);
	glVertex2i(500, 450);
	glEnd();
	glFlush();
}