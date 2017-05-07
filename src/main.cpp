/* main.cpp
*
*	main source  
*		(c) S.Suzuki 2017.5.3
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>

#include<GL/glut.h>
#include<Object.h>

/* Number of Windows */
const int WinNum = 1;
int WindowID[WinNum];

/* Flags */
bool MFLAG = false; /* Mouse Flag */
bool RTFLAG = true; /* Rotate Translate Flag */

/* Function Prototype Declaration */
void WindowCanvas(void);
void PopUpMenu(void);
void Controler(void);
void init(void);
void idle(void);
void display(void);
void resize(int w, int h);
void mouse(int button, int state, int x, int y);
void motion(int x, int y);
void menu(int val);
void keyboard(unsigned char key, int x, int y);
void keyboard_sp(int key, int x, int y);


/* main function */
int main(int argc, char *argv[]){
	srand((unsigned) time(NULL));
	
	glutInit(&argc, argv);
	WindowCanvas();
	PopUpMenu();
	Controler();
	
	glutMainLoop();
	return 0;
}

/******** Functions *********/

void WindowCanvas(void){
	//glutInitWindowPosition(350,0);
	//glutInitWindowSize(1200,650);
	glutInitWindowPosition(900,0);
	glutInitWindowSize(500,600);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	WindowID[0] = glutCreateWindow("Reform 2017");
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	init();
}


void PopUpMenu(void){
	glutCreateMenu(menu);
	glutAddMenuEntry("Quit",0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}


void Controler(void){
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboard_sp);
}


void init(void){
	glClearColor( 0.7, 0.7, 1.0, 1.0 );

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_LIGHT4);
	glEnable(GL_LIGHT5);
	glEnable(GL_LIGHT6);
	glEnable(GL_LIGHT7);
}


void idle(void){
	for(int i=0; i<WinNum; ++i){
		glutSetWindow(WindowID[i]);
		glutPostRedisplay();
	}
}


void display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	
	/* Light Color */
	GLfloat LightClr0[]  = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat LightClr1[]  = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat LightClr2[]  = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat LightPos0[]  = {   0.0, 5000.0,-1500.0, 1.0 };
	static GLfloat LightPos1[]  = { 5000.0, 5000.0, 3500.0, 1.0 };
	static GLfloat LightPos2[]  = { 5000.0, 5000.0,-6500.0, 1.0 };
	static GLfloat LightPos3[]  = {-5000.0, 5000.0, 3500.0, 1.0 };
	static GLfloat LightPos4[]  = {-5000.0, 5000.0,-6500.0, 1.0 };
	/* Ambient Light */
	glLightfv(GL_LIGHT0, GL_POSITION, LightPos0);
	glLightfv(GL_LIGHT0, GL_AMBIENT,  LightClr0);
	/* Diffused Light */
	glLightfv(GL_LIGHT1, GL_POSITION, LightPos0);
	glLightfv(GL_LIGHT1, GL_DIFFUSE,  LightClr1);
	glLightfv(GL_LIGHT2, GL_POSITION, LightPos1);
	glLightfv(GL_LIGHT2, GL_DIFFUSE,  LightClr1);
	glLightfv(GL_LIGHT3, GL_POSITION, LightPos2);
	glLightfv(GL_LIGHT3, GL_DIFFUSE,  LightClr1);
	glLightfv(GL_LIGHT4, GL_POSITION, LightPos3);
	glLightfv(GL_LIGHT4, GL_DIFFUSE,  LightClr1);
	glLightfv(GL_LIGHT7, GL_POSITION, LightPos4);
	glLightfv(GL_LIGHT7, GL_DIFFUSE,  LightClr1);
	/* Specular Light */
	glLightfv(GL_LIGHT5, GL_POSITION, LightPos1);
	glLightfv(GL_LIGHT5, GL_SPECULAR, LightClr2);
	glLightfv(GL_LIGHT6, GL_POSITION, LightPos4);
	glLightfv(GL_LIGHT6, GL_SPECULAR, LightClr2);

	StonePaving();
	Drawing();
	OuterWall();
	InnerWall();
	
	glutSwapBuffers();
}

/* parameters for camera */
double dstnc = 1500.0;
double theta = 180*PI/180;
double phi   = 60*PI/180;
double xc    = 0.0;
double yc    = 200.0;
double zc    = 0.0;

void resize(int w, int h){
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, w/(double)h, 1.0, 5000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	double ex = xc+dstnc*cos(phi)*sin(theta);
	double ey = yc+dstnc*sin(phi);
	double ez = zc+dstnc*cos(phi)*cos(theta);
	gluLookAt(ex,ey,ez,xc,yc,zc,0,1,0);
}


/* mouse click */
void mouse(int button, int state, int x, int y){
	switch (button) {
		case GLUT_LEFT_BUTTON:
			if(state==GLUT_UP){
				MFLAG = false;
			}
			glutIdleFunc(idle);
			break;
		default:
			break;
	}
}


/* mouse motion */
void motion(int x, int y){
	const double Rspeed = 0.2; /* Rotate Speed */
	double dTrans = dstnc/400; /* Translate Speed */
	static int xmouse;
	static int ymouse;
	if(MFLAG){
		if(RTFLAG){
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			theta += (xmouse-x)*PI/180*Rspeed;
			if(theta>2*PI) theta -= 2*PI;
			if(theta<0)    theta += 2*PI;
			phi +=-(ymouse-y)*PI/180*Rspeed;
			if(phi>= PI/2) phi = PI/2-0.1*PI/180;
			if(phi<=-PI/2) phi =-PI/2+0.1*PI/180;
			double ex = xc+dstnc*cos(phi)*sin(theta);
			double ey = yc+dstnc*sin(phi);
			double ez = zc+dstnc*cos(phi)*cos(theta);
			if(ey<=10) ey = 10.0;
			gluLookAt(ex,ey,ez,xc,yc,zc,0,1,0);
		}
		else{
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			xc += ((xmouse-x)*cos(-theta)+(ymouse-y)*sin(theta))*dTrans;
			zc += ((xmouse-x)*sin(-theta)+(ymouse-y)*cos(theta))*dTrans;
			double ex = xc+dstnc*cos(phi)*sin(theta);
			double ey = yc+dstnc*sin(phi);
			double ez = zc+dstnc*cos(phi)*cos(theta);
			gluLookAt(ex,ey,ez,xc,yc,zc,0,1,0);
		}
	}
	glutIdleFunc(idle);
	xmouse = x;
	ymouse = y;
	MFLAG  = true;
}


void menu(int val){
	switch(val){
		case 0:  /* Quit */
			exit(0);
		default:
			break;
	}
}


void keyboard(unsigned char key, int x, int y){
	double ex,ey,ez;
	switch(key){
		case 'q': /* Quit */
		case 'Q':
		case '\033':
			exit(0);
		case 'm':
		case 'M':
			if(RTFLAG) RTFLAG = false;
			else RTFLAG = true;
			glutIdleFunc(idle);
			break;
		case 'n':
		case 'N':
			if(NFLAG) NFLAG = false;
			else NFLAG = true;
			glutIdleFunc(idle);
			break;
		case '_':
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			dstnc = 1500.0;
			theta = 180*PI/180;
			phi   = 60*PI/180;
			xc    = 0.0;
			yc    = 200.0;
			zc    = 0.0;
			ex = xc+dstnc*cos(phi)*sin(theta);
			ey = yc+dstnc*sin(phi);
			ez = zc+dstnc*cos(phi)*cos(theta);
			gluLookAt(ex,ey,ez,xc,yc,zc,0,1,0);
			break;
		default:
			break;
	}
}


void keyboard_sp(int key, int x, int y){
	double ex,ey,ez;
	double dDstnc = dstnc/ 50;
	switch (key) {
		case GLUT_KEY_RIGHT:
			break;
		case GLUT_KEY_LEFT:
			break;
		case GLUT_KEY_UP:
			dstnc -= dDstnc;
			if(dstnc<300) dstnc = 300;
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			ex = xc+dstnc*cos(phi)*sin(theta);
			ey = yc+dstnc*sin(phi);
			ez = zc+dstnc*cos(phi)*cos(theta);
			if(ey<=10) ey = 10.0;
			gluLookAt(ex,ey,ez,xc,yc,zc,0,1,0);
			glutIdleFunc(idle);
			break;
		case GLUT_KEY_DOWN:
			dstnc += dDstnc;
			if(dstnc>3000) dstnc = 3000;
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			ex = xc+dstnc*cos(phi)*sin(theta);
			ey = yc+dstnc*sin(phi);
			ez = zc+dstnc*cos(phi)*cos(theta);
			if(ey<=10) ey = 10.0;
			gluLookAt(ex,ey,ez,xc,yc,zc,0,1,0);
			glutIdleFunc(idle);
			break;
		default:
			break;
	}
}


