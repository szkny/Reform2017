#ifndef Object_h_
#define Object_h_

/*************************************/

#include<GL/glut.h>
#include"MyGLUT.h"
#include"Colors.h"

bool NFLAG = true;

const double UNIT    = 95.5/2;
const double height  = UNIT*2;
const double ceiling = UNIT*8;

/*************** Tools ****************/

void Tatami1(double x, double z){
	glPushMatrix();
	glTranslated(x,height,z);
	double thickness = 3.0;
	double dT = 0.5;
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_tatami1.specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_tatami1.shininess);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_tatami1.diffuse);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_tatami1.ambient);	
	glRectangular(UNIT*2-thickness,thickness-dT,UNIT*4-2*dT,0,0,0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_tatami2.specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_tatami2.shininess);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_tatami2.diffuse);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_tatami2.ambient);	
	glRectangular(thickness,thickness+dT,UNIT*4-dT,-UNIT+thickness/2+dT,0,0);
	glRectangular(thickness,thickness+dT,UNIT*4-dT, UNIT-thickness/2-dT,0,0);
	glPopMatrix();
}


void Tatami2(double x, double z){
	glPushMatrix();
	glTranslated(x,height,z);
	glRotated(90,0,1,0);
	double thickness = 3.0;
	double dT = 0.5;
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_tatami1.specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_tatami1.shininess);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_tatami1.diffuse);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_tatami1.ambient);	
	glRectangular(UNIT*2-thickness,thickness-dT,UNIT*4-2*dT,0,0,0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_tatami2.specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_tatami2.shininess);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_tatami2.diffuse);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_tatami2.ambient);	
	glRectangular(thickness,thickness+dT,UNIT*4-dT,-UNIT+thickness/2+dT,0,0);
	glRectangular(thickness,thickness+dT,UNIT*4-dT, UNIT-thickness/2-dT,0,0);
	glPopMatrix();
}


void Window(double x, double y, double z){
	double width = 4.0;
	glPushMatrix();
	glTranslated(x,y,z);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_acryl.specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_acryl.shininess);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_acryl.diffuse);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_acryl.ambient);	
	glRectangular(UNIT*3,UNIT*2,1.5,0,0,0);
	glDisable(GL_BLEND);

	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_metal.specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_metal.shininess);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_metal.diffuse);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_metal.ambient);	
	glRectangular(width,UNIT*2,width,0,0,0);
	glRectangular(width,UNIT*2,width, UNIT*3/2-width/2,0,0);
	glRectangular(width,UNIT*2,width,-UNIT*3/2+width/2,0,0);
	glRectangular(UNIT*3,width,width,0, UNIT-width/2,0);
	glRectangular(UNIT*3,width,width,0,-UNIT+width/2,0);
	glPopMatrix();
}


void StoneWall(double l, double r, double x, double z){
	glPushMatrix();
	glTranslated(x,0,z);
	glRotated(r,0,1,0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_stone.specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_stone.shininess);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_stone.diffuse);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_stone.ambient);	
	glRectangular(l,UNIT*6,UNIT,0,UNIT*2,0);
	glPopMatrix();
}

/************* Objects **************/

void StonePaving(void){
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_paving.specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_paving.shininess);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_paving.diffuse);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_paving.ambient);	
	glRectangular(10000,1,10000,0,0,0);
}


void InnerWall(void){
	if(NFLAG){
		/* Window */
		Window( UNIT*2,height+UNIT*3,-UNIT*12);
		Window( UNIT*2,height+UNIT*3, UNIT*9.4);
		Window(-UNIT*2,height+UNIT*3, UNIT*9.4);
		Window(-UNIT*6,height+UNIT*3, UNIT*9.4);
		/* Grain Wall */
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_grain0.specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_grain0.shininess);	
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_grain0.diffuse);	
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_grain0.ambient);
		glRectangular(UNIT*9 ,ceiling*0.4,1.0,-UNIT*9/2,ceiling*0.8,-UNIT*11);	
		glRectangular(UNIT*2 ,ceiling,1.0,-UNIT*5,ceiling/2,-UNIT*11);	
		glRectangular(UNIT   ,ceiling,1.0,-UNIT*8.5,ceiling/2,-UNIT*11);	
		glRectangular(UNIT*6 ,ceiling,1.0, UNIT*3,ceiling/2,-UNIT*12);	
		glRectangular(UNIT   ,ceiling,1.0,-UNIT*8.5,ceiling/2,UNIT*8);	
		glRectangular(UNIT*14,ceiling,1.0,-UNIT,ceiling/2,UNIT*9.4);	
		glRectangular(1.0,ceiling,UNIT*19,-UNIT*9,ceiling/2,-UNIT*1.5);
		glRectangular(1.0,ceiling,UNIT,0.0,ceiling/2,-UNIT*11.5);
		glRectangular(1.0,ceiling,UNIT*2,UNIT*6,ceiling/2,-UNIT*11);
		glRectangular(1.0,ceiling,UNIT*1.4,-UNIT*8,ceiling/2,UNIT*8.7);
		/* Pillar */
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_grain0.specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_grain0.shininess);	
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_grain0.diffuse);	
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_grain0.ambient);
		glRectangular(UNIT/2,ceiling,UNIT/2,-UNIT*4,ceiling/2, UNIT*9/4);
		glRectangular(UNIT/2,ceiling,UNIT/2,-UNIT*4,ceiling/2, UNIT*23/4);
		glRectangular(UNIT/4,ceiling,UNIT/4,0,ceiling/2,0);
		glRectangular(UNIT/4,ceiling,UNIT/4,0,ceiling/2, UNIT*8);
		glRectangular(UNIT/4,ceiling,UNIT/4, UNIT*4,ceiling/2, UNIT*8);
		glRectangular(UNIT/4,ceiling,UNIT/4, UNIT*6,ceiling/2, UNIT*8);
		glRectangular(UNIT/4,ceiling,UNIT/4,-UNIT*2,ceiling/2,0);
		glRectangular(UNIT/4,ceiling,UNIT/4,-UNIT*4,ceiling/2,0);
		glRectangular(UNIT/4,ceiling,UNIT/4,-UNIT*2,ceiling/2,-UNIT*6);
		glRectangular(UNIT/4,ceiling,UNIT/4,-UNIT*4,ceiling/2,-UNIT*6);
		glRectangular(UNIT/4,ceiling,UNIT/4,-UNIT*4,ceiling/2,-UNIT*8);
		glRectangular(UNIT/4,ceiling,UNIT/4, UNIT*6,ceiling/2,0);
		glRectangular(UNIT/4,ceiling,UNIT/4, UNIT*6,ceiling/2,-UNIT*8);
		glRectangular(UNIT/4,ceiling,UNIT/4,0,ceiling/2,-UNIT*8);
		glRectangular(UNIT/4,ceiling,UNIT/4, UNIT*14,ceiling/2,0);
		glRectangular(UNIT/4,ceiling,UNIT/4, UNIT*14,ceiling/2,-UNIT*8);
		/* Main Door */
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_grain0.specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_grain0.shininess);	
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_grain0.diffuse);	
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_grain0.ambient);
		glRectangular(UNIT*4,6.0,3.0,-UNIT*2,ceiling*0.6,-UNIT*11);
		glRectangular(UNIT*4,10.0,3.0,-UNIT*2,ceiling*0.3,-UNIT*11);
		glRectangular(UNIT*4,20.0,3.0,-UNIT*2,10.0,-UNIT*11);
		for(int i=0;i<11;++i){
			glRectangular(3.0,ceiling*0.6,3.0,-UNIT*i*2/5,ceiling*0.6/2,-UNIT*11);
		}
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_acryl.specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_acryl.shininess);	
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_acryl.diffuse);	
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_acryl.ambient);	
		glRectangular(UNIT*4,ceiling*0.6,1.0,-UNIT*2,ceiling*0.3,-UNIT*11);
		/* Sub Door */
		glRectangular(UNIT*1.6,UNIT*1.8,2.0,-UNIT*7,UNIT*3.5,-UNIT*11);
		glDisable(GL_BLEND);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_Aluminium.specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_Aluminium.shininess);	
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_Aluminium.diffuse);	
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_Aluminium.ambient);	
		glRectangular(UNIT*2,ceiling*0.6,1.0,-UNIT*7,ceiling*0.6/2,-UNIT*11);
	}
}


void OuterWall(void){
	if(NFLAG){
		StoneWall(UNIT*4,0,-UNIT*8,-UNIT*28);
		StoneWall(UNIT,-45,-UNIT*6,-UNIT*27.8);
		StoneWall(UNIT*25,0,UNIT*15.5,-UNIT*28);
		StoneWall(UNIT, 45, UNIT*3,-UNIT*27.8);
		StoneWall(UNIT*40,90,UNIT*27.6,-UNIT*8);
	}
}




void Drawing(void){
	Tatami1(UNIT,-UNIT*10);
	Tatami1(UNIT*3,-UNIT*10);
	Tatami1(UNIT*5,-UNIT*10);
	
	Tatami1(UNIT,-UNIT*2);
	Tatami1(UNIT,-UNIT*6);
	Tatami1(UNIT*3,-UNIT*4);
	Tatami1(UNIT*5,-UNIT*4);
	Tatami2(UNIT*4,-UNIT);
	Tatami2(UNIT*4,-UNIT*7);
	
	Tatami1(UNIT,UNIT*4);
	Tatami1(UNIT*3,UNIT*4);
	Tatami1(UNIT*5,UNIT*2);
	Tatami1(UNIT*5,UNIT*6);
	Tatami2(UNIT*2,UNIT*7);
	Tatami2(UNIT*2,UNIT);

	Tatami1(UNIT*7,-UNIT*4);
	Tatami1(UNIT*13,-UNIT*4);
	Tatami2(UNIT*10,-UNIT*3);
	Tatami2(UNIT*10,-UNIT*5);
	Tatami2(UNIT*8,-UNIT);
	Tatami2(UNIT*12,-UNIT);
	Tatami2(UNIT*8,-UNIT*7);
	Tatami2(UNIT*12,-UNIT*7);

	/* kotatsu */
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_stone.specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_stone.shininess);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_stone.diffuse);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_stone.ambient);	
	glRectangular(UNIT*3.5,UNIT*2/3,UNIT*2,-UNIT*1.75,UNIT/3,UNIT*4);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_grain0.specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_grain0.shininess);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_grain0.diffuse);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_grain0.ambient);
	glRectangular(UNIT*3.5,UNIT*2/3,1.0,-UNIT*1.75,height-UNIT,UNIT*3);
	glRectangular(UNIT*3.5,UNIT*2/3,1.0,-UNIT*1.75,height-UNIT,UNIT*5);
	glRectangular(1.0,UNIT*2/3,UNIT*2,0.0,height-UNIT,UNIT*4);
	glRectangular(1.0,UNIT*2/3,UNIT*2,-UNIT*3.5,height-UNIT,UNIT*4);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_grain2.specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_grain2.shininess);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_grain2.diffuse);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_grain2.ambient);
	glRectangular(UNIT*3,5.0,UNIT*2,-UNIT*2,height+UNIT/3,UNIT*4);
	for(int i=0;i<4;++i){
		glRectangular(UNIT/4,UNIT*5/3,UNIT/4,-UNIT*2+pow(-1,i)*UNIT*1.2,height-UNIT/2,UNIT*4+pow(-1,i/2)*UNIT*0.8);
	}

	/* TV */
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_black_plastic.specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_black_plastic.shininess);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_black_plastic.diffuse);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_black_plastic.ambient);	
	glRectangular(4,60,100,-UNIT*4,height+UNIT/3+40,UNIT*4);
	glRectangular(10,10,50,-UNIT*4,height+UNIT/3+5,UNIT*4);

	/* piano */
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_black_plastic.specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_black_plastic.shininess);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_black_plastic.diffuse);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_black_plastic.ambient);	
	glRectangular(UNIT,UNIT*3,UNIT*3.6,UNIT/2,height+UNIT*3/2,-UNIT*6);
	glRectangular(UNIT/2,UNIT/3,UNIT*3.6,UNIT*5/4,height+UNIT*3/2,-UNIT*6);
	glRectangular(UNIT/6,UNIT*3/2,UNIT/6,UNIT*4/3,height+UNIT*3/4,-UNIT*4.5);
	glRectangular(UNIT/6,UNIT*3/2,UNIT/6,UNIT*4/3,height+UNIT*3/4,-UNIT*7.5);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_grain2.specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_grain2.shininess);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_grain2.diffuse);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_grain2.ambient);
	glRectangular(UNIT*9/5,2.0,UNIT*4,UNIT*9/10,height+1.0,-UNIT*6);

	/* floor */
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_grain0.specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_grain0.shininess);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_grain0.diffuse);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_grain0.ambient);
	glRectangular(UNIT*6,1.0,UNIT*3,-UNIT*3,height-UNIT*2/3,UNIT*1.5);
	glRectangular(UNIT*6,1.0,UNIT*4.4,-UNIT*3,height-UNIT*2/3,UNIT*7.2);
	glRectangular(UNIT*2.5,1.0,UNIT*2,-UNIT*4.75,height-UNIT*2/3,UNIT*4);
	glRectangular(UNIT*4,1.0,UNIT*8.4,-UNIT*6,height-UNIT*2/3,UNIT*5.2);
	glRectangular(1.0,UNIT*2/3,UNIT*9.4,0.0,height-UNIT/3,UNIT*4.7);
	glRectangular(UNIT*2,UNIT*2/3,1.0,-UNIT,height-UNIT/3,0.0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_grain1.specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_grain1.shininess);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_grain1.diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_grain1.ambient);
	glRectangular(UNIT*6,1.0,UNIT*1.4,UNIT*3,height,UNIT*8.7);
	glRectangular(UNIT*8,1.0,UNIT*2,UNIT*10,height,UNIT*2.5);
	glRectangular(UNIT*2,1.0,UNIT*6,-UNIT,height,-UNIT*3);
	glRectangular(UNIT*4,1.0,UNIT*2,-UNIT*2,height,-UNIT*7);
	glRectangular(UNIT*4,UNIT,1.0,-UNIT*2,height-UNIT/2,-UNIT*8);
	glRectangular(UNIT*8,1.0,UNIT,-UNIT*4,height-UNIT,-UNIT*8.5);
	glRectangular(UNIT*8,UNIT,1.0,-UNIT*4,height-UNIT*3/2,-UNIT*9);

	/* bath room */
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_jade.specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_jade.shininess);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_jade.diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_jade.ambient);
	glRectangular(UNIT*4,UNIT,UNIT*2,-UNIT*4,  height-UNIT/2,-UNIT);
	glRectangular(UNIT*2,UNIT,UNIT*6,-UNIT*5,  height-UNIT/2,-UNIT*5);
	glRectangular(UNIT/2,UNIT,UNIT*4,-UNIT*9/4,height-UNIT/2,-UNIT*4);
	glRectangular(UNIT*2,UNIT,UNIT/2,-UNIT*3,  height-UNIT/2,-UNIT*23/4);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_white_plastic.specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_white_plastic.shininess);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_white_plastic.diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_white_plastic.ambient);
	glRectangular(UNIT*1.5,UNIT/4,UNIT*3.5,-UNIT*3.25,height-UNIT*2/4+UNIT/8,-UNIT*3.75);
	glRectangular(UNIT*1.5,UNIT*1.2,UNIT/4,-UNIT*3.25,height-UNIT*2/4+UNIT*0.6,-UNIT*17/8);
	glRectangular(UNIT*1.5,UNIT*1.2,UNIT/4,-UNIT*3.25,height-UNIT*2/4+UNIT*0.6,-UNIT*43/8);
	glRectangular(UNIT/8,UNIT*1.2,UNIT*3.5,-UNIT*5/2, height-UNIT*2/4+UNIT*0.6,-UNIT*15/4);
	glRectangular(UNIT/8,UNIT*1.2,UNIT*3.5,-UNIT*4,   height-UNIT*2/4+UNIT*0.6,-UNIT*15/4);
	glPushMatrix();
	glTranslated(-UNIT*5,height+UNIT/2,-UNIT*6.8);
	glRotated(90,0,0,1);
	glCylinder(UNIT/2,UNIT,0,0,0);
	glPopMatrix();
	glRectangular(UNIT,UNIT,UNIT,-UNIT*5,height+UNIT/2,-UNIT*7.2);

	/* shelf */
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_grain1.specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_grain1.shininess);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_grain1.diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_grain1.ambient);
	glRectangular(UNIT,UNIT*2,UNIT*2,-UNIT*4.5,UNIT,-UNIT*10);
	glRectangular(UNIT*2,UNIT*4,UNIT*1.4,UNIT*5,height+UNIT*2,UNIT*8.7);
	
	/* stairs */
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_grain1.specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_grain1.shininess);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_grain1.diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_grain1.ambient);
	glPushMatrix();
	glTranslated(-UNIT*4.2,UNIT*4.6,UNIT*3);
	glRotated(45,1,0,0);
	glRectangular(3.8,UNIT/2,UNIT*8,0,0,0);
	glPopMatrix();
	for(int i=0;i<12;++i){
		glRectangular(UNIT*1.6,3.8,UNIT/2,-UNIT*5,height-UNIT*2/3+UNIT*(2*i+2)/4,UNIT*(24-(2*i+1))/4);
	}
	
	/* kitchen */
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_metal.specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_metal.shininess);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_metal.diffuse);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_metal.ambient);
	glRectangular(UNIT*3.5,UNIT/2,UNIT*1.4,-UNIT*7/4,height+UNIT,UNIT*8.5);
	glRectangular(UNIT*1.2,UNIT/4,UNIT*1.4,-UNIT*4.1,height+UNIT*3/4,UNIT*8.5);
	glRectangular(UNIT*1.2,UNIT/2,UNIT*0.2,-UNIT*4.1,height+UNIT,UNIT*7.9);
	glRectangular(UNIT*1.2,UNIT/2,UNIT*0.2,-UNIT*4.1,height+UNIT,UNIT*9.1);
	glRectangular(UNIT*0.3,UNIT/2,UNIT*1.4,-UNIT*4.75,height+UNIT,UNIT*8.5);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_grain2.specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_grain2.shininess);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_grain2.diffuse);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_grain2.ambient);
	glRectangular(UNIT*0.9,UNIT*4/3,1.0,-UNIT*1/2,height,UNIT*7.8);
	glRectangular(UNIT*0.9,UNIT*4/3,1.0,-UNIT*3/2,height,UNIT*7.8);
	glRectangular(UNIT*0.9,UNIT*4/3,1.0,-UNIT*5/2,height,UNIT*7.8);
	glRectangular(UNIT*0.9,UNIT*4/3,1.0,-UNIT*7/2,height,UNIT*7.8);
	glRectangular(UNIT*0.9,UNIT*4/3,1.0,-UNIT*9/2,height,UNIT*7.8);

	/* table2 */
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_mat.specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_mat.shininess);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_mat.diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_mat.ambient);
	glRectangular(UNIT*4,1.0,UNIT*5,UNIT*3,height+2,UNIT*4);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_TUNA.specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_TUNA.shininess);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_TUNA.diffuse);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_TUNA.ambient);
	glRectangular(UNIT*2,10,UNIT*3.2,UNIT*3,height+40,UNIT*4);
	for(int i=0;i<4;++i){
		glRectangular(UNIT/4,35,UNIT/4,UNIT*3+pow(-1,i)*UNIT*0.8,height+35/2,UNIT*4+pow(-1,i/2)*UNIT*1.4);
	}

	/* table3 */
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms_grain3.specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,ms_grain3.shininess);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  ms_grain3.diffuse);	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  ms_grain3.ambient);
	glRectangular(UNIT*2,10,UNIT*3.2,UNIT*4,height+40,-UNIT*4);
	for(int i=0;i<4;++i){
		glRectangular(UNIT/4,35,UNIT/4,UNIT*4+pow(-1,i)*UNIT*0.8,height+35/2,-UNIT*4+pow(-1,i/2)*UNIT*1.4);
	}
}


/*************************************/

#endif // Object_h_
