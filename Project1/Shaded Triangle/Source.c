#include <freeglut.h>
#include <stdio.h>
#include <math.h>


void drawTriangle();
void drawCircle();
void drawShapes();
void drawSquare();

typedef struct CircleXY {
	float cx;
	float cy;
	float radius;
	int segments;
}CircleXY;

CircleXY c1 = { 125,350,50.0f,360 };
CircleXY c2 = { 250,250,50.0f,360 };
CircleXY c3 = { 350,150,50.0f,360 };

void initializeGL(void)
{
	glClearColor(0, 0, 0, 0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(250, 250);
	glutCreateWindow("Shaders");
	glutDisplayFunc(drawShapes);
	initializeGL();
	glutMainLoop();
}



void drawShapes()
{
	drawTriangle();
	drawSquare();
	drawCircle(c1);
	drawCircle(c2);
	drawCircle(c3);
	glFlush();
}

void drawSquare()
{
	glClearColor(0, 0, 0, 0);
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 1.0f,0.1f);
	glVertex2i(0,500);
	glVertex2i(250,500);
	glVertex2i(250,250);
	glVertex2i(0,250);
	glEnd();
}

void drawCircle(CircleXY c)
{
	float theta = 3.1415926 * 2 / (float)(c.radius);
	float tangetial_factor = tanf(theta);//calculate the tangential factor 

	float radial_factor = cosf(theta);//calculate the radial factor 

	float x = c.radius;//we start at angle = 0 

	float y = 0;
	glLineWidth(2);
	glBegin(GL_TRIANGLE_FAN);
	for (int ii = 0; ii < c.radius; ii++)
	{
		glVertex2f(x + c.cx, y + c.cy);//output vertex 

		//calculate the tangential vector 
		//remember, the radial vector is (x, y) 
		//to get the tangential vector we flip those coordinates and negate one of them 

		float tx = -y;
		float ty = x;

		//add the tangential vector 

		x += tx * tangetial_factor;
		y += ty * tangetial_factor;

		//correct using the radial factor 

		x *= radial_factor;
		y *= radial_factor;
	}
	glEnd();
}

void drawTriangle()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glColor4f(1.0f, 0.0f, 0.0f,0.5);
	glVertex2i(125,500);
	glColor4f(0, 1.0f, 0.0f, 0.5);
	glVertex2i(250,250);
	glColor4f(0, 0.0f, 1.0f, 0.5);
	glVertex2i(0,250);
	glEnd();
	glFlush();
}