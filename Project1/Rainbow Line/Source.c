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
	glutInitWindowPosition(0.5,0.5);
	glutCreateWindow("Rainbow Line");
	glutDisplayFunc(drawRainbowLine);
	initializeGL();
	glutMainLoop();
}

void drawRainbowLine(void)
{



}

