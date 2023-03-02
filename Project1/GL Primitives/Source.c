#include <freeglut.h>

void drawShapes(void);

void initializeGL(void)
{
	glClearColor(0, 0, 0, 0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	gluOrtho2D(0.0, 600.0, 0.0, 600.0);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(250, 250);
	glutCreateWindow("Primitives");
	glutDisplayFunc(drawShapes);
	initializeGL();
	glutMainLoop();
}

void drawShapes(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glVertex2i(175, 500);
	glVertex2i(150, 590);
	glVertex2i(125, 500);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor4f(255, 0, 0, 0.5);
	glVertex2i(150, 450);
	glVertex2i(175, 500);
	glVertex2i(125, 500);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor4f(0, 255, 0, 0.5);
	glVertex2i(150, 450);
	glVertex2i(125, 500);
	glVertex2i(50, 420);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor4f(0, 0, 255, 0.5);
	glVertex2i(150, 450);
	glVertex2i(175, 500);
	glVertex2i(240, 420);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glColor4f(0, 0, 255, 0.1);
	glVertex2i(400, 550);//1
	glColor4f(0, 0, 255, 0.2);
	glVertex2i(550, 550);//2
	glColor4f(0, 0, 255, 0.3);
	glVertex2i(410, 480);//3
	glColor4f(0, 0, 255, 0.4);
	glVertex2i(520, 490);//4
	glColor4f(0, 0, 255, 0.5);
	glVertex2i(400, 450);//5
	glColor4f(0, 0, 255, 0.6);
	glVertex2i(510, 420);//6
	glColor4f(0, 0, 255, 0.7);
	glVertex2i(410, 370);//7
	glColor4f(0, 0, 255, 0.8);
	glVertex2i(530, 390);//8
	glColor4f(0, 0, 255, 0.9);
	glVertex2i(420, 335);//9
	glColor4f(0, 0, 255, 1.0);
	glVertex2i(490, 350);//10
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor4f(50, 255, 0, 0.1);
	glVertex2i(50, 250);//1
	glColor4f(75, 225, 0, 0.2);
	glVertex2i(50, 350);//2
	glColor4f(100, 215, 0, 0.3);
	glVertex2i(70, 340);//3
	glColor4f(125, 195, 0, 0.4);
	glVertex2i(90, 340);//4
	glColor4f(0, 175, 0, 0.5);
	glVertex2i(110, 320);//5
	glColor4f(0, 155, 0, 0.6);
	glVertex2i(130, 320);//6
	glColor4f(0, 135, 0, 0.7);
	glVertex2i(150, 300);//7
	glColor4f(20, 115, 0, 0.8);
	glVertex2i(170, 300);//8
	glColor4f(40, 95, 0, 0.9);
	glVertex2i(190, 280);//9
	glColor4f(60, 75, 0, 1);
	glVertex2i(210, 280);//10
	glColor4f(80, 55, 0, 1);
	glVertex2i(230, 260);//11
	glColor4f(100, 35, 0, 1);
	glVertex2i(240, 260);//12
	glColor4f(120, 15, 0, 1);
	glVertex2i(260, 250);//13
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex2i(150, 200);//1
	glColor3f(1, 0.5, 0);
	glVertex2i(200, 150);//2
	glColor3f(1, 1, 0);
	glVertex2i(200, 100);//3
	glColor3f(0.5, 1, 0);
	glVertex2i(150, 50);//4
	glColor3f(0.5, 1, 0.5);
	glVertex2i(100, 100);//5
	glColor3f(0, 1, 1);
	glVertex2i(100, 150);//6
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(1, 1, 0);
	glVertex2i(450,300);
	glColor3f(1, 1, 0);
	glVertex2i(400,300);
	glColor3f(1, 0, 0);
	glVertex2i(450,150);
	glColor3f(0, 0, 1);
	glVertex2i(400,100);
	glColor3f(1, 0, 0);
	glVertex2i(550,150);
	glColor3f(0, 0, 1);
	glVertex2i(550,100);
	glEnd();



	glFlush();
}

