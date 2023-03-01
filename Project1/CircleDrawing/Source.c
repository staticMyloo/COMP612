#include <freeglut.h>
#include <time.h>
#include <math.h>

void drawCircle(void);

void initializeGL(void)
{
	// set background color to be black
	glClearColor(0.0, 0.0, 0.0, 0.0);
	// set the drawing to be blue
	glColor3f(1.0f, 1.0f, 1.0f);
	// set the dot size to be 4 by 4 pixels
	//glPointSize(1.0);
	// set to projection mode
	glMatrixMode(GL_PROJECTION);
	// load the identity matrix
	glLoadIdentity();
	// set window mode to 2D orthographica and set the window size 
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}


void main(int argc, char** argv)
{
	srand((unsigned int)time(0));
	// initialize the toolkit
	glutInit(&argc, argv);
	// set display mode
	glutInitDisplayMode(GLUT_RGB);
	// set window size
	glutInitWindowSize(600, 600);
	// set window position on screen
	glutInitWindowPosition(0, 0);
	glutCreateWindow("my first attempt");
	// register redraw function
	glutDisplayFunc(drawCircle);
	//initialize the rendering context
	initializeGL();
	// go into a perpetual loop
	glutMainLoop();

}

void drawCircle(void)
{
	float radius = 0.5f;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.5f);

	for (int theta = 0; theta <= 360; theta++)
	{
		float angle = (float)(theta * 3.14f / 180.0f);
		float x = (float)cos(angle) * radius;
		float y = (float)sin(angle) * radius;
		glVertex2f(x, y);
	}
	
	glEnd();
	glFlush();
}