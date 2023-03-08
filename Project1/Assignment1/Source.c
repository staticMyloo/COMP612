/******************************************************************************
 *
 * Animation v1.0 (23/02/2021)
 *
 * This template provides a basic FPS-limited render loop for an animated scene.
 *
 ******************************************************************************/
#include <Windows.h>
#include <freeglut.h>
#include <math.h>
#include <stdio.h>
 /******************************************************************************
  * Animation & Timing Setup
  ******************************************************************************/
  // Target frame rate (number of Frames Per Second).
#define TARGET_FPS 60
#define TRUE 1
#define FALSE 0
#define PI 3.141592653589793238



// Ideal time each frame should be displayed for (in milliseconds).
const unsigned int FRAME_TIME = 1000 / TARGET_FPS;
// Frame time in fractional seconds.
// Note: This is calculated to accurately reflect the truncated integer value of
// FRAME_TIME, which is used for timing, rather than the more accurate fractional
// value we'd get if we simply calculated "FRAME_TIME_SEC = 1.0f / TARGET_FPS".
const float FRAME_TIME_SEC = (1000 / TARGET_FPS) / 1000.0f;
// Time we started preparing the current frame (in milliseconds since GLUT was initialized).
unsigned int frameStartTime = 0;
/******************************************************************************
 * Keyboard Input Handling Setup
 ******************************************************************************/
 // Define all character keys used for input (add any new key definitions here).
 // Note: USE ONLY LOWERCASE CHARACTERS HERE. The keyboard handler provided converts all
// characters typed by the user to lowercase, so the SHIFT key is ignored.
#define KEY_EXIT 27 // Escape key.
/******************************************************************************
 * GLUT Callback Prototypes
 ******************************************************************************/

typedef struct {
	float r;
	float g;
	float b;
	float alpha;
}Color;

typedef struct {
	float cx;
	float cy;
	float radius;
}Circle;

void display(void);
void reshape(int width, int h);
void keyPressed(unsigned char key, int x, int y);
void idle(void);
void drawCircle(Circle c, Color color, int isClear);
void drawBase(void);
void drawBackGround(void);
void drawFace(Circle c);
/******************************************************************************
 * Animation-Specific Function Prototypes (add your own here)
 ******************************************************************************/
void main(int argc, char** argv);
void init(void);
void think(void);
/******************************************************************************
 * Animation-Specific Setup (Add your own definitions, constants, and globals here)
 ******************************************************************************/

Circle globeCircle = { 0.0f, 0.0f, 1 };
Circle c1 = { -0.3f, -0.61f, 0.1f };
Circle c2 = { -0.3f, -0.5f, 0.075f };
Circle c3 = { -0.3f, -0.45f, 0.06f };//Circle responsible for head
const float windowWidth = 800.0f;
const float windowHeight = 800.0f;

 /******************************************************************************
  * Entry Point (don't put anything except the main function here)
  ******************************************************************************/
void main(int argc, char** argv)
{
	// Initialize the OpenGL window.
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize((int)windowWidth, (int)windowHeight);
	glutCreateWindow("Animation");
	// Set up the scene.
	init();
	// Disable key repeat (keyPressed or specialKeyPressed will only be called once when a key is first pressed).
	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
	// Register GLUT callbacks.
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyPressed);
	glutIdleFunc(idle);
	// Record when we started rendering the very first frame (which should happen after we call glutMainLoop).
	frameStartTime = (unsigned int)glutGet(GLUT_ELAPSED_TIME);
	// Enter the main drawing loop (this will never return).
	glutMainLoop();
}
/******************************************************************************
 * GLUT Callbacks (don't add any other functions here)
 ******************************************************************************/
 /*
 Called when GLUT wants us to (re)draw the current animation frame.
 Note: This function must not do anything to update the state of our
simulated
 world. Animation (moving or rotating things, responding to keyboard input,
 etc.) should only be performed within the think() function provided below.
 */
void display(void)
{
	/*
	TEMPLATE: REPLACE THIS COMMENT WITH YOUR DRAWING CODE
	Separate reusable pieces of drawing code into functions, which you can
	add
	to the "Animation-Specific Functions" section below.
	Remember to add prototypes for any new functions to the "Animation-
	Specific
	Function Prototypes" section near the top of this template.
	*/
	drawBackGround();
	Color globeColor = { 1,1,1, 0.5f };
	drawCircle(globeCircle, globeColor, TRUE);
	drawBase();
	Color snowManColor = { 124.0f, 229.0f, 252.0f, 0.8f };
	drawCircle(c1, snowManColor, FALSE);
	drawCircle(c2, snowManColor, FALSE);
	drawCircle(c3, snowManColor, FALSE);
	drawFace(c3);

	glutSwapBuffers();
}
/*
Called when the OpenGL window has been resized.
*/
void reshape(int width, int h)
{
}
/*
Called each time a character key (e.g. a letter, number, or symbol) is
pressed.
*/
void keyPressed(unsigned char key, int x, int y)
{
	switch (tolower(key)) {
		/*
		TEMPLATE: Add any new character key controls here.
		Rather than using literals (e.g. "d" for diagnostics), create a
		new KEY_
		definition in the "Keyboard Input Handling Setup" section of this
		file.
		*/
	case KEY_EXIT:
		exit(0);
		break;
	}
}
/*
Called by GLUT when it's not rendering a frame.
Note: We use this to handle animation and timing. You shouldn't need to
modify
this callback at all. Instead, place your animation logic (e.g. moving or
rotating
things) within the think() method provided with this template.
*/
void idle(void)
{
	// Wait until it's time to render the next frame.
	unsigned int frameTimeElapsed = (unsigned int)glutGet(GLUT_ELAPSED_TIME) -
		frameStartTime;
	if (frameTimeElapsed < FRAME_TIME)
	{
		// This frame took less time to render than the ideal FRAME_TIME: we'll suspend this thread for the remaining time,
			// so we're not taking up the CPU until we need to render another frame.
		unsigned int timeLeft = FRAME_TIME - frameTimeElapsed;
		Sleep(timeLeft);
	}
	// Begin processing the next frame.
	frameStartTime = glutGet(GLUT_ELAPSED_TIME); // Record when we started work on the new frame.
	think(); // Update our simulated world before the next call to display().
	glutPostRedisplay(); // Tell OpenGL there's a new frame ready to be drawn.
}
/******************************************************************************
 * Animation-Specific Functions (Add your own functions at the end of this section)
 ******************************************************************************/
 /*
 Initialise OpenGL and set up our scene before we begin the render loop.
 */
void init(void)
{
	// set background color to be black
	glClearColor(0.0, 0.0, 0.0, 0.0);
	// set the drawing to be blue
	glColor3f(0.0f, 0.0f, 0.0f);
	// set to projection mode
	glMatrixMode(GL_PROJECTION);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	// load the identity matrix
	glLoadIdentity();
	// set window mode to 2D orthographica and set the window size 
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}
/*
Advance our animation by FRAME_TIME milliseconds.
Note: Our template's GLUT idle() callback calls this once before each new
frame is drawn, EXCEPT the very first frame drawn after our application
starts. Any setup required before the first frame is drawn should be placed
in init().
*/
void think(void)
{
	/*
	TEMPLATE: REPLACE THIS COMMENT WITH YOUR ANIMATION/SIMULATION CODE
	In this function, we update all the variables that control the animated
	parts of our simulated world. For example: if you have a moving box,
	this is
	where you update its coordinates to make it move. If you have something
	that
	spins around, here's where you update its angle.
	NOTHING CAN BE DRAWN IN HERE: you can only update the variables that
	control
	how everything will be drawn later in display().
	How much do we move or rotate things? Because we use a fixed frame
	rate, we
	assume there's always FRAME_TIME milliseconds between drawing each
	frame. So,
	every time think() is called, we need to work out how far things should
	have
	moved, rotated, or otherwise changed in that period of time.
	Movement example:
	* Let's assume a distance of 1.0 GL units is 1 metre.
	* Let's assume we want something to move 2 metres per second on the x
	axis
	* Each frame, we'd need to update its position like this:
	x += 2 * (FRAME_TIME / 1000.0f)
	* Note that we have to convert FRAME_TIME to seconds. We can skip this
	by
	  using a constant defined earlier in this template:
	x += 2 * FRAME_TIME_SEC;
	Rotation example:
	* Let's assume we want something to do one complete 360-degree rotation
	every
	  second (i.e. 60 Revolutions Per Minute, or RPM).
	* Each frame, we'd need to update our object's angle like this (we'll
	use the
	  FRAME_TIME_SEC constant as per the example above):
	a += 360 * FRAME_TIME_SEC;
	This works for any type of "per second" change: just multiply the
	amount you'd
	want to move in a full second by FRAME_TIME_SEC, and add or subtract
	that
	from whatever variable you're updating.
	You can use this same approach to animate other things like color,
	opacity,
	brightness of lights, etc.
	*/
}

void drawCircle(Circle c, Color color, int isClear)
{
	float alphaValue = isClear ? 0.5 : 1;
	glColor4f(color.r, color.g, color.b, alphaValue);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(c.cx, c.cy);
	if(!isClear) { glColor3f(0.5, 0.5, 1); }
	
	for (int theta = 0; theta <= 360; theta++)
	{
		float angle = (float)(theta * PI / 180.0f);
		float x = (float)cos(angle) * c.radius + c.cx;
		float y = (float)sin(angle) * c.radius + c.cy;
		glVertex2f(x, y);
	}

	glEnd();
}

void drawBase(void)
{
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2f(1.0f, -1.0f);
	glVertex2f(0.71f, -0.71f);
	glVertex2f(-0.71f, -0.71f);
	glVertex2f(-1.0f, -1.0f);
	glEnd();
}

void drawBackGround(void)
{
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(1.0f, -1.0f);
	glVertex2f(1.0f, 1.0f);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(-1.0f, -1.0f);
	glEnd();
}

void drawFace(Circle c)
{
	glColor3f(0, 0, 0);
	glPointSize(8.0f);
	glBegin(GL_POINTS);
	glVertex2f(c3.cx - 0.05f, c3.cy+0.025f);
	glVertex2f(c3.cx + 0.05f, c3.cy+0.025f);
	glEnd();
}

/******************************************************************************/