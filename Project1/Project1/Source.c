/* include the library header files */
#include <freeglut.h>
#include <stdio.h>
/************************************************************************
Function: initializeGL
Description: Initializes the OpenGL rendering context for display.
*************************************************************************/
void initializeGL(void)
{
	// set background color to be black
	glClearColor(0.0, 0.0, 0.0, 0.0);
	// set the drawing to be blue
	glColor3f(1.0f, 1.0f, 1.0f);
	// set the dot size to be 4 by 4 pixels
	glPointSize(1.0);
	// set to projection mode
	glMatrixMode(GL_PROJECTION);
	// load the identity matrix
	glLoadIdentity();
	// set window mode to 2D orthographica and set the window size 
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

void display(void)
{
	// clear the screen 
	glClear(GL_COLOR_BUFFER_BIT);
	// draw three points
	glBegin(GL_POLYGON);
	glColor3f(1, 0.0, 0.0);
	glVertex2f(0.5, -0.5);
	glColor3f(0.0, 0.0, 1);
	glVertex2f(-1, 0.7);
	glColor3f(1, 0.0, 0.0);
	glVertex2f(-1, -0.5);
	glEnd();
	// send all output to display 
	glFlush();
}
/************************************************************************
Function: main
Description: Sets up the openGL rendering context and the windowing
system, then begins the display loop.
*************************************************************************/
void main(int argc, char** argv)
{
	
	// initialize the toolkit
	glutInit(&argc, argv);
	// set display mode
	glutInitDisplayMode(GLUT_RGB);
	// set window size
	glutInitWindowSize(500, 500);
	// set window position on screen
	glutInitWindowPosition(0, 0);
	// open the screen window
	glutCreateWindow("ColourFulTriangle");
	// register redraw function
	glutDisplayFunc(display);
	//initialize the rendering context
	initializeGL();
	// go into a perpetual loop
	glutMainLoop();
}