#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include<iostream>
using namespace std;
#include<Windows.h>
#include<MMSystem.h>
float c = 45;
float pl = 0;
float rain1 = -23.50;
float rain2 = rain1 - 3;
float rain3 = rain1 - 6;
float as = -5.4;
float p=-45.0;
float swingx = -8.59;
float swingy = -22;
float horse1y=-3.0;
float horse2y=3.0;
float horse3y=-3.8;
static GLfloat spin =  0.0;//spin korar jonne initial degree
static float	tx	=  00;
static float	ty	=  0.0;
float hrs1 = 3;
float hrs3 = 3;
float hrs2 = -4;
float r = 0.15, g = 0.6, b = 0.81;
float trnx = 50;
float trny = -25;
float trnxx = 50;
float trnyy = -25;
float trn_limit = 35;
float trn_limit1 = 35;
float trn_limit2 = 31.6;
float trn_limit3 = 0;
float trn_limit4 = -4;
void spe_key(int key, int x, int y)
{

	switch (key) {

		case GLUT_KEY_LEFT:
				tx -=5;
                //glutPostRedisplay();
				break;

		case GLUT_KEY_RIGHT:
				tx +=5;

				//glutPostRedisplay();
				break;

        case GLUT_KEY_DOWN:
				ty -=5;

				//glutPostRedisplay();
				break;

		case GLUT_KEY_UP:
				ty +=5;

				//glutPostRedisplay();
				break;
	  default:
			break;
	}
}

void spinDisplay_right(void)
{
   spin = spin - 1;
   if (spin > 360.0)
      spin = spin - 360.0;
   //glutPostRedisplay();
}

void spinDisplay_left(void)   //void spinDisplay_left(int val) likhbo jodi cont. rotate chai
{
   spin = spin + 1; //speed control
   if (spin > 360.0)
      spin = spin - 360.0;
   //glutPostRedisplay(); //bar bar bivinno angle a aka hochhe
   //glutTimerFunc(25,spinDisplay_left,0); //continuously rotate er jonno
}

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glOrtho(-50,50,-50,50,-50,50);
}


void my_keyboard(unsigned char key, int x, int y)
{

	switch (key) {

		case 'l':
		spinDisplay_left();
			break;

		case 'r':
			spinDisplay_right();
			break;

        case 's':
			 glutIdleFunc(NULL);
			 break;
	}
}

void my_mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
         glutIdleFunc(spinDisplay_left);
         break;
      case GLUT_MIDDLE_BUTTON:
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
			glutIdleFunc(spinDisplay_right);
       //glutIdleFunc(NULL); // make idle function inactive
      //break;
     //default:
    //break;
   }
}



void circle(GLfloat rx,GLfloat ry,GLfloat x,GLfloat y)//radius_x,radius_y,certre_position_x,centre_position_y
{
    int i=0;
    float angle;
    GLfloat PI = 3.1416;
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i=0;i<361;i++)
    {
        angle = i * (PI/180); //conversion from degree to radian
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)*ry));
    }
    glEnd();
}


void halfcircle(GLfloat rx,GLfloat ry,GLfloat x,GLfloat y)//radius_x,radius_y,certre_position_x,centre_position_y
{
    int i=0;
    float angle;
    GLfloat PI = 3.1416;
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i=0;i<181;i++)
    {
        angle = i * (PI/180); //conversion from degree to radian
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)*ry));
    }
    glEnd();
}

void halfcircle_moon(GLfloat rx,GLfloat ry,GLfloat x,GLfloat y)//radius_x,radius_y,certre_position_x,centre_position_y
{
    int i=0;
    float angle;
    GLfloat PI = 3.1416;
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i=180;i<361;i++)
    {
        angle = i * (PI/180); //conversion from degree to radian
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)*ry));
    }
    glEnd();
}


void halfcircle_tower(GLfloat rx,GLfloat ry,GLfloat x,GLfloat y)//radius_x,radius_y,certre_position_x,centre_position_y
{
    int i=0;
    float angle;
    GLfloat PI = 3.1416;
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i=190;i<351;i++)
    {
        angle = i * (PI/180); //conversion from degree to radian
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)*ry));
    }
    glEnd();
}

void cloud()
{
    //sky__sun
    glColor3f(1,0.8,0.2);
    circle(5,6,-40,40);


    //cloud
    glColor3f(1,1,1);
    circle(3,5,c-14,39);
    glColor3f(1,1,1);
    circle(3,3,c-11,33);
    glColor3f(1,1,1);
    circle(3,4,c-9,39);
    glColor3f(1,1,31);
    circle(4,3,c-7,38);
    glColor3f(1,1,1);
    circle(3,7,c-9,39);
    glColor3f(1,1,1);
    circle(3,3,c-6,33);
    glColor3f(1,1,1);
    circle(3,4,c-4,39);
    glColor3f(1,1,31);
    circle(4,3,c-2,38);

    glColor3f(1,1,1);
    circle(3,5,c+44,39);
    glColor3f(1,1,1);
    circle(3,3,c+41,33);
    glColor3f(1,1,1);
    circle(3,4,c+39,39);
    glColor3f(1,1,31);
    circle(4,3,c+37,38);
    glColor3f(1,1,1);
    circle(3,7,c+39,39);
    glColor3f(1,1,1);
    circle(3,3,c+36,33);
    glColor3f(1,1,1);
    circle(3,4,c+34,39);
    glColor3f(1,1,31);
    circle(4,3,c+32,38);




}

void fountain(){


        ////foara
        //foara stand 1 1
        glBegin(GL_POLYGON);
        glColor3f(0.36,0.21,0.07);
        glVertex3f(-42.9,-37,0);
        glVertex3f(-43,-35,0);
        glVertex3f(-36,-37,0);
        glVertex3f(-36,-38.5,0);
        glEnd();
        //foara stand 1 2
        glBegin(GL_POLYGON);
        glColor3f(0.36,0.21,0.07);
        glVertex3f(-36,-38.5,0);
        glVertex3f(-36,-37,0);
        glVertex3f(-32,-32,0);
        glVertex3f(-32,-33.8,0);
        glEnd();
        //foara stand 2 1
        glBegin(GL_POLYGON);
        glColor3f(0.99,0.5,0.99);
        glVertex3f(-43,-35,0);
        glVertex3f(-42,-34,0);
        glVertex3f(-36.5,-35.5,0);
        glVertex3f(-36,-37,0);
        glEnd();
        //foara stand 2 2
        glBegin(GL_POLYGON);
        glColor3f(0.99,0.5,0.99);
        glVertex3f(-36,-37,0);
        glVertex3f(-36.5,-35.5,0);
        glVertex3f(-33,-32,0);
        glVertex3f(-32,-32,0);
        glEnd();
        //foara stand 2 3
        glBegin(GL_POLYGON);
        glColor3f(0.99,0.5,0.99);
        glVertex3f(-32,-32,0);
        glVertex3f(-33,-32,0);
        glVertex3f(-36,-30,0);
        glVertex3f(-36,-29,0);
        glEnd();
        //foara stand 2 4
        glBegin(GL_POLYGON);
        glColor3f(0.99,0.5,0.99);
        glVertex3f(-36,-29,0);
        glVertex3f(-36,-30,0);
        glVertex3f(-40,-30,0);
        glVertex3f(-40,-29,0);
        glEnd();
        //foara stand 2 5
        glBegin(GL_POLYGON);
        glColor3f(0.99,0.5,0.99);
        glVertex3f(-40,-29,0);
        glVertex3f(-40,-30,0);
        glVertex3f(-41.5,-31,0);
        glVertex3f(-43,-31,0);
        glEnd();
        //foara stand 2 6
        glBegin(GL_POLYGON);
        glColor3f(0.99,0.5,0.99);
        glVertex3f(-42.7,-31,0);
        glVertex3f(-41.7,-31,0);
        glVertex3f(-42,-34,0);
        glVertex3f(-43,-35,0);
        glEnd();



        //water
        glBegin(GL_TRIANGLES);
        glColor3f(0.24,0.18,0.38);
        glVertex3f(-36.5,-35.5,0);
        glColor3f(0.5,1,0);
        glVertex3f(-33,-32,0);
        glColor3f(0.24,0.18,0.38);
        glVertex3f(-36,-30,0);
        glEnd();

         //water 2
        glBegin(GL_TRIANGLES);
        glColor3f(0.24,0.18,0.38);
        glVertex3f(-36.5,-35.5,0);
        glColor3f(0.24,0.18,0.38);
        glVertex3f(-36,-30,0);
        glColor3f(0.5,1,0);
        glVertex3f(-42,-34,0);
        glEnd();
        //wwater 3
        glBegin(GL_POLYGON);
        glColor3f(0.5,1,0);
        glVertex3f(-42,-34,0);
        glColor3f(0.5,0.7,0);
        glVertex3f(-41.7,-31,0);
        glColor3f(0.5,0.7,0);
        glVertex3f(-40,-30,0);
        glColor3f(0.24,0.15,0.3);
        glVertex3f(-36,-30,0);
        glEnd();


        //foara 1
        glBegin(GL_POLYGON);
        glColor3f(0.9,0.9,0.9);
        glVertex3f(-38,-33,0);
        glColor3f(0.7,0.7,0.7);
        glVertex3f(-37.7,-26,0);
        glColor3f(0.9,0.9,0.9);
        glVertex3f(-37.62,-26,0);
        glColor3f(0.6,0.6,0.6);
        glVertex3f(-37.5,-33,0);
        glEnd();
        //water point
        //25.50


        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-25.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-25.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-25.50,0);
        glEnd();

        //water point
        //24
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.45,-24.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.55,-24.75,0);
        glEnd();
        //water point
        //24
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.40, rain1 + 0.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.60, rain1 + 0.250,0);
        glEnd();
        //water point
        //25
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-25,0);
        glEnd();


        //water point
        //25.25


        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.35,-25.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-25.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.65,-25.25,0);
        glEnd();

        //water point
        //25.75
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-25.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-25.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-25.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38,-25.75,0);
        glEnd();

        //water point
        //26
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.9,-26,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37,-26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38,-26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.15,-26,0);
        glEnd();

         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75,-26.250,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-26.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37,-26.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-26.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-26.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38,-26.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25,-26.250,0);
        glEnd();

        //water point
        //26.50
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.5,-26.50,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75,-26.50,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-26.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37,-26.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-26.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-26.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38,-26.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25,-26.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.5,-26.50,0);
        glEnd();
        //water point
        //26.250//26.250
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75, rain1 - 1.250,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25, rain1 - 1.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37, rain1 - 1.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5, rain1 - 1.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75, rain1 - 1.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38, rain1 - 1.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25, rain1 - 1.250,0);
        glEnd();

        //water point
        //26.50
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.5,-26.50,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75,-26.50,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-26.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37,-26.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-26.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-26.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38,-26.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25,-26.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.5,-26.50,0);
        glEnd();


        //26.75
        ///water point

        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.25,-26.75,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.5,-26.75,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75,-26.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37,-26.75,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-26.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-26.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-26.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38,-26.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25,-26.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.5,-26.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.75,-26.75,0);
        glEnd();

        ///27
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36,-27,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.25,-27,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.5,-27,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75,-27,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37,-27,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-27,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-27,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-27,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38,-27,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25,-27,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.5,-27,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.75,-27,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39,-27,0);
        glEnd();


        ///27.25
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.90,-27.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36,-27.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.25,-27.25,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.5,-27.25,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75,-27.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37,-27.25,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-27.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-27.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-27.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38,-27.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25,-27.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.5,-27.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.75,-27.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39,-27.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.10,-27.25,0);
        glEnd();
        ///27.5
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.90,-27.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36,-27.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.25,-27.5,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.5,-27.5,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75,-27.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37,-27.5,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-27.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-27.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-27.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38,-27.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25,-27.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.5,-27.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.75,-27.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39,-27.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.10,-27.5,0);
        glEnd();
        ///27.75
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.90,-27.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36,-27.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.25,-27.75,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.5,-27.75,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75,-27.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37,-27.75,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-27.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-27.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-27.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38,-27.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25,-27.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.5,-27.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.75,-27.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39,-27.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.10,-27.75,0);
        glEnd();
        ///28
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.90,-28,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36,-28,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.25,-28,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.5,-28,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75,-28,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37,-28,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-28,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-28,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-28,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38,-28,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25,-28,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.5,-28,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.75,-28,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39,-28,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.10,-28,0);
        glEnd();
        ///28.25
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.80,-28.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.90,-28.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36,-28.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.25,-28.25,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.5,-28.25,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75,-28.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37,-28.25,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-28.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-28.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-28.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38,-28.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25,-28.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.5,-28.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.75,-28.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39,-28.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.10,-28.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.20,-28.25,0);
        glEnd();
        ///28.25 rain 1
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.80, rain1 - 3.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.90, rain1 - 3.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36, rain1 - 3.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.25, rain1 - 3.250,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.5, rain1 - 3.250,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75, rain1 - 3.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37, rain1 - 3.250,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25, rain1 - 3.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5, rain1 - 3.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75, rain1 - 3.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38, rain1 - 3.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25, rain1 - 3.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.5, rain1 - 3.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.75, rain1 - 3.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39, rain1 - 3.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.10, rain1 - 3.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.20, rain1 - 3.250,0);
        glEnd();
        //28.5
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.80,-28.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.90,-28.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36,-28.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.25,-28.5,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.5,-28.5,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75,-28.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37,-28.5,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-28.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-28.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-28.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38,-28.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25,-28.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.5,-28.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.75,-28.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39,-28.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.10,-28.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.20,-28.5,0);
        glEnd();
        //28.75
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.80,-28.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.90,-28.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36,-28.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.25,-28.75,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.5,-28.75,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75,-28.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37,-28.75,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-28.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-28.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-28.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38,-28.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25,-28.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.5,-28.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.75,-28.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39,-28.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.10,-28.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.20,-28.75,0);
        glEnd();
        //29
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.80,-29,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.90,-29,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36,-29,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.25,-29,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.5,-29,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75,-29,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37,-29,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-29,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-29,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-29,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38,-29,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25,-29,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.5,-29,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.75,-29,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39,-29,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.10,-29,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.20,-29,0);
        glEnd();
        //29.25
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.70,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.80,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.90,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.25,-29.25,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.5,-29.25,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37,-29.25,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.5,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.75,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.10,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.20,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.30,-29.25,0);
        glEnd();
                //29.5
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.70,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.80,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.90,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.25,-29.5,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.5,-29.5,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37,-29.5,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.5,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.75,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.10,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.20,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.30,-29.5,0);
        glEnd();
                //29.75
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.70,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.80,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.90,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.25,-29.75,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.5,-29.75,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37,-29.75,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.5,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.75,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.10,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.20,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.30,-29.75,0);
        glEnd();
                //30.00
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.55,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.70,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.80,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.90,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.25,-30.00,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.5,-30.00,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37,-30.00,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.5,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.75,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.10,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.20,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.30,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.45,-30.00,0);
        glEnd();
                //30.250
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.70,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.80,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.90,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.25,-30.250,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.5,-30.250,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37,-30.250,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.5,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.75,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.10,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.20,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.30,-30.250,0);
        glEnd();
        //30.50
        ///water point

        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.70,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.80,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.90,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.25,-30.50,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.5,-30.50,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37,-30.50,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.5,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.75,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.10,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.20,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.30,-30.50,0);
        glEnd();
                //30.750
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.70,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.80,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.90,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.25,-30.750,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.5,-30.750,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37,-30.750,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.5,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.75,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.10,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.20,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.30,-30.750,0);
        glEnd();
                //31
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.70,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.80,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.90,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.25,-31,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.5,-31,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37,-31,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.5,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.75,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.10,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.20,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.30,-31,0);
        glEnd();
        //31 rain 1
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.70, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.80, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.90, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.25, rain1 - 6,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.5, rain1 - 6,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37, rain1 - 6,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.5, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.75, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.10, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.20, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.30, rain1 - 6,0);
        glEnd();
                //31.26
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.70,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.80,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.90,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.25,-31.26,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.5,-31.26,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37,-31.26,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.5,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.75,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.10,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.20,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.30,-31.26,0);
        glEnd();
                //31.56
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.70,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.80,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.90,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.25,-31.56,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.5,-31.56,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37,-31.56,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.5,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.75,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.10,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.20,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.30,-31.56,0);
        glEnd();
                //31.76
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.70,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.80,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.90,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.25,-31.76,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.5,-31.76,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37,-31.76,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.5,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.75,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.10,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.20,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.30,-31.76,0);
        glEnd();
                //32.00
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.70,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.80,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.90,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.25,-32.00,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.5,-32.00,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37,-32.00,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.5,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.75,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.10,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.20,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.30,-32.00,0);
        glEnd();
                //32.30
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.70,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.80,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.90,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.25,-32.30,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.5,-32.30,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-36.75,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37,-32.30,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.25,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.75,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.25,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.5,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-38.75,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.10,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.20,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-39.30,-32.30,0);
        glEnd();
}

void fountain2()
{
    ////foara
        //foara stand 1 1
        glBegin(GL_POLYGON);
        glColor3f(0.36,0.21,0.07);
        glVertex3f(+42.9,-37,0);
        glVertex3f(+43,-35,0);
        glVertex3f(+36,-37,0);
        glVertex3f(+36,-38.5,0);
        glEnd();
        //foara stand 1 2
        glBegin(GL_POLYGON);
        glColor3f(0.36,0.21,0.07);
        glVertex3f(+36,-38.5,0);
        glVertex3f(+36,-37,0);
        glVertex3f(+32,-32,0);
        glVertex3f(+32,-33.8,0);
        glEnd();
        //foara stand 2 1
        glBegin(GL_POLYGON);
        glColor3f(0.99,0.5,0.99);
        glVertex3f(+43,-35,0);
        glVertex3f(+42,-34,0);
        glVertex3f(+36.5,-35.5,0);
        glVertex3f(+36,-37,0);
        glEnd();
        //foara stand 2 2
        glBegin(GL_POLYGON);
        glColor3f(0.99,0.5,0.99);
        glVertex3f(+36,-37,0);
        glVertex3f(+36.5,-35.5,0);
        glVertex3f(+33,-32,0);
        glVertex3f(+32,-32,0);
        glEnd();
        //foara stand 2 3
        glBegin(GL_POLYGON);
        glColor3f(0.99,0.5,0.99);
        glVertex3f(+32,-32,0);
        glVertex3f(+33,-32,0);
        glVertex3f(+36,-30,0);
        glVertex3f(+36,-29,0);
        glEnd();
        //foara stand 2 4
        glBegin(GL_POLYGON);
        glColor3f(0.99,0.5,0.99);
        glVertex3f(+36,-29,0);
        glVertex3f(+36,-30,0);
        glVertex3f(+40,-30,0);
        glVertex3f(+40,-29,0);
        glEnd();
        //foara stand 2 5
        glBegin(GL_POLYGON);
        glColor3f(0.99,0.5,0.99);
        glVertex3f(+40,-29,0);
        glVertex3f(+40,-30,0);
        glVertex3f(+41.5,-31,0);
        glVertex3f(+43,-31,0);
        glEnd();
        //foara stand 2 6
        glBegin(GL_POLYGON);
        glColor3f(0.99,0.5,0.99);
        glVertex3f(+42.7,-31,0);
        glVertex3f(+41.7,-31,0);
        glVertex3f(+42,-34,0);
        glVertex3f(+43,-35,0);
        glEnd();



        //water
        glBegin(GL_TRIANGLES);
        glColor3f(0.24,0.18,0.38);
        glVertex3f(+36.5,-35.5,0);
        glColor3f(0.5,1,0);
        glVertex3f(+33,-32,0);
        glColor3f(0.24,0.18,0.38);
        glVertex3f(+36,-30,0);
        glEnd();

         //water 2
        glBegin(GL_TRIANGLES);
        glColor3f(0.24,0.18,0.38);
        glVertex3f(+36.5,-35.5,0);
        glColor3f(0.24,0.18,0.38);
        glVertex3f(+36,-30,0);
        glColor3f(0.5,1,0);
        glVertex3f(+42,-34,0);
        glEnd();
        //wwater 3
        glBegin(GL_POLYGON);
        glColor3f(0.5,1,0);
        glVertex3f(+42,-34,0);
        glColor3f(0.5,0.7,0);
        glVertex3f(+41.7,-31,0);
        glColor3f(0.5,0.7,0);
        glVertex3f(+40,-30,0);
        glColor3f(0.24,0.15,0.3);
        glVertex3f(+36,-30,0);
        glEnd();


        //foara 1
        glBegin(GL_POLYGON);
        glColor3f(0.9,0.9,0.9);
        glVertex3f(+38,-33,0);
        glColor3f(0.7,0.7,0.7);
        glVertex3f(+37.7,-26,0);
        glColor3f(0.9,0.9,0.9);
        glVertex3f(+37.62,-26,0);
        glColor3f(0.6,0.6,0.6);
        glVertex3f(+37.5,-33,0);
        glEnd();
        //water point
        //25.50


        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-25.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-25.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-25.50,0);
        glEnd();

        //water point
        //24
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.45,-24.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.55,-24.75,0);
        glEnd();
        //water point
        //24
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.40, rain1 - 0.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.60, rain1- 0.250,0);
        glEnd();
        //water point
        //25
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-25,0);
        glEnd();


        //water point
        //25.25


        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.35,-25.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-25.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.65,-25.25,0);
        glEnd();

        //water point
        //25.75
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-25.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-25.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-25.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38,-25.75,0);
        glEnd();

        //water point
        //26
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.9,-26,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37,-26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38,-26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.15,-26,0);
        glEnd();

         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75,-26.250,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-26.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37,-26.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-26.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-26.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38,-26.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25,-26.250,0);
        glEnd();

        //water point
        //26.50
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.5,-26.50,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75,-26.50,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-26.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37,-26.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-26.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-26.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38,-26.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25,-26.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.5,-26.50,0);
        glEnd();
        //water point
        //26.250//26.250
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75, rain1 - 1.250,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25, rain1 - 1.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37, rain1 - 1.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5, rain1 - 1.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75, rain1 - 1.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38, rain1 - 1.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25, rain1 - 1.250,0);
        glEnd();

        //water point
        //26.50
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.5,-26.50,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75,-26.50,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-26.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37,-26.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-26.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-26.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38,-26.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25,-26.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.5,-26.50,0);
        glEnd();


        //26.75
        ///water point

        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.25,-26.75,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.5,-26.75,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75,-26.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37,-26.75,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-26.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-26.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-26.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38,-26.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25,-26.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.5,-26.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.75,-26.75,0);
        glEnd();

        ///27
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36,-27,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.25,-27,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.5,-27,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75,-27,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37,-27,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-27,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(-37.5,-27,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-27,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38,-27,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25,-27,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.5,-27,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.75,-27,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39,-27,0);
        glEnd();


        ///27.25
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.90,-27.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36,-27.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.25,-27.25,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.5,-27.25,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75,-27.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37,-27.25,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-27.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-27.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-27.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38,-27.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25,-27.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.5,-27.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.75,-27.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39,-27.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.10,-27.25,0);
        glEnd();
        ///27.5
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.90,-27.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36,-27.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.25,-27.5,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.5,-27.5,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75,-27.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37,-27.5,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-27.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-27.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-27.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38,-27.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25,-27.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.5,-27.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.75,-27.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39,-27.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.10,-27.5,0);
        glEnd();
        ///27.75
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.90,-27.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36,-27.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.25,-27.75,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.5,-27.75,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75,-27.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37,-27.75,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-27.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-27.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-27.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38,-27.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25,-27.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.5,-27.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.75,-27.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39,-27.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.10,-27.75,0);
        glEnd();
        ///28
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.90,-28,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36,-28,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.25,-28,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.5,-28,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75,-28,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37,-28,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-28,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-28,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-28,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38,-28,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25,-28,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.5,-28,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.75,-28,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39,-28,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.10,-28,0);
        glEnd();
        ///28.25
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.80,-28.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.90,-28.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36,-28.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.25,-28.25,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.5,-28.25,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75,-28.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37,-28.25,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-28.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-28.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-28.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38,-28.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25,-28.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.5,-28.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.75,-28.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39,-28.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.10,-28.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.20,-28.25,0);
        glEnd();
        ///28.25 rain 1
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.80, rain1 - 3.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.90, rain1 - 3.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36, rain1 - 3.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.25, rain1 - 3.250,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.5, rain1 - 3.250,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75, rain1 - 3.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37, rain1 - 3.250,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25, rain1 - 3.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5, rain1 - 3.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75, rain1 - 3.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38, rain1 - 3.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25, rain1 - 3.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.5, rain1 - 3.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.75, rain1 - 3.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39, rain1 - 3.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.10, rain1 - 3.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.20, rain1 - 3.250,0);
        glEnd();
        //28.5
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.80,-28.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.90,-28.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36,-28.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.25,-28.5,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.5,-28.5,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75,-28.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37,-28.5,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-28.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-28.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-28.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38,-28.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25,-28.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.5,-28.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.75,-28.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39,-28.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.10,-28.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.20,-28.5,0);
        glEnd();
        //28.75
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.80,-28.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.90,-28.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36,-28.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.25,-28.75,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.5,-28.75,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75,-28.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37,-28.75,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-28.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-28.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-28.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38,-28.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25,-28.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.5,-28.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.75,-28.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39,-28.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.10,-28.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.20,-28.75,0);
        glEnd();
        //29
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.80,-29,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.90,-29,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36,-29,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.25,-29,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.5,-29,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75,-29,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37,-29,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-29,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-29,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-29,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38,-29,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25,-29,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.5,-29,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.75,-29,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39,-29,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.10,-29,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.20,-29,0);
        glEnd();
        //29.25
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.70,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.80,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.90,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.25,-29.25,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.5,-29.25,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37,-29.25,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.5,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.75,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.10,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.20,-29.25,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.30,-29.25,0);
        glEnd();
                //29.5
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.70,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.80,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.90,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.25,-29.5,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.5,-29.5,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37,-29.5,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.5,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.75,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.10,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.20,-29.5,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.30,-29.5,0);
        glEnd();
                //29.75
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.70,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.80,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.90,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.25,-29.75,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.5,-29.75,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37,-29.75,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.5,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.75,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.10,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.20,-29.75,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.30,-29.75,0);
        glEnd();
                //30.00
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.55,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.70,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.80,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.90,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.25,-30.00,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.5,-30.00,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37,-30.00,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.5,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.75,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.10,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.20,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.30,-30.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.45,-30.00,0);
        glEnd();
                //30.250
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.70,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.80,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.90,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.25,-30.250,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.5,-30.250,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37,-30.250,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.5,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.75,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.10,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.20,-30.250,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.30,-30.250,0);
        glEnd();
        //30.50
        ///water point

        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.70,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.80,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.90,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.25,-30.50,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.5,-30.50,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37,-30.50,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.5,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.75,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.10,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.20,-30.50,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.30,-30.50,0);
        glEnd();
                //30.750
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.70,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.80,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.90,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.25,-30.750,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.5,-30.750,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37,-30.750,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.5,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.75,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.10,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.20,-30.750,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.30,-30.750,0);
        glEnd();
                //31
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.70,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.80,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.90,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.25,-31,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.5,-31,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37,-31,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.5,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.75,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.10,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.20,-31,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.30,-31,0);
        glEnd();
        //31 rain 1
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.70, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.80, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.90, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.25, rain1 - 6,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.5, rain1 - 6,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37, rain1 - 6,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.5, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.75, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.10, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.20, rain1 - 6,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.30, rain1 - 6,0);
        glEnd();
                //31.26
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.70,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.80,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.90,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.25,-31.26,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.5,-31.26,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37,-31.26,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.5,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.75,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.10,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.20,-31.26,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.30,-31.26,0);
        glEnd();
                //31.56
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.70,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.80,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.90,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.25,-31.56,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.5,-31.56,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37,-31.56,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.5,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.75,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.10,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.20,-31.56,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.30,-31.56,0);
        glEnd();
                //31.76
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.70,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.80,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.90,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.25,-31.76,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.5,-31.76,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37,-31.76,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.5,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.75,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.10,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.20,-31.76,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.30,-31.76,0);
        glEnd();
                //32.00
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.70,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.80,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.90,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.25,-32.00,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.5,-32.00,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37,-32.00,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.5,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.75,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.10,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.20,-32.00,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.30,-32.00,0);
        glEnd();
                //32.30
        ///water point
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.70,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.80,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.90,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.25,-32.30,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.5,-32.30,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+36.75,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37,-32.30,0);
        glEnd();
         glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.25,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.5,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+37.75,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.25,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.5,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+38.75,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.10,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.20,-32.30,0);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex3f(+39.30,-32.30,0);
        glEnd();
}


void chorki()
{





	//chorki code
	// making star side 1
	//corki stand
        glBegin(GL_POLYGON);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(-32,-10,0);
        glVertex3d(-30,10,0);
        glVertex3d(-30,8,0);
        glVertex3d(-31.3,-10,0);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(-28.7,-10,0);
        glVertex3d(-30,8,0);
        glVertex3d(-30,10,0);
        glVertex3d(-28,-10,0);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(-32,-10,0);
        glVertex3d(-32,-10.7,0);
        glVertex3d(-28,-10.7,0);
        glVertex3d(-28,-10,0);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(-32,-9,0);
        glVertex3d(-32,-9.7,0);
        glVertex3d(-28,-9.7,0);
        glVertex3d(-28,-9,0);
        glEnd();




        glPushMatrix();
        glTranslatef(-30,10,0);

        glPushMatrix();
        glRotatef(spin,0,0,1);

        glBegin(GL_POLYGON);
        glColor3f(0.93,0.76,0.57);
        glVertex2f(-29.75+30,-3-10);
        glVertex2f(-29.75+30,23-10);
        glVertex2f(-30.25+30,23-10);
        glVertex2f(-30.25+30,-3-10);
        glEnd();




        // making star side 2
       glBegin(GL_POLYGON);
        glColor3f(0.93,0.76,0.57);
        glVertex3f(-43+30,9.5-10,0);
        glVertex3f(-43+30,10-10,0);
        glVertex3f(-17+30,10-10,0);
        glVertex3f(-17+30,9.5-10,0);
        glEnd();


        // making star side 3
       glBegin(GL_POLYGON);
        glColor3f(0.93,0.76,0.57);
        glVertex3f(-38.7+30,0.8-10,0);
        glVertex3f(-39+30,1.3-10,0);
        glVertex3f(-20.9+30,19-10,0);
        glVertex3f(-20.2+30,19-10,0);
        glEnd();
        // making star side 4
       glBegin(GL_POLYGON);
        glColor3f(0.93,0.76,0.57);
        glVertex3f(-40+30,19-10,0);
        glVertex3f(-39.4+30,19.2-10,0);
        glVertex3f(-21+30,1-10,0);
        glVertex3f(-21.5+30,0.7-10,0);
        glEnd();
        //head of stand
        glColor3f(0.42,0.02,0.06);
        circle(3,3,-30+30,10-10);
        glColor3f(0.62,0.01,0.03);
        circle(2.5,2.5,-30+30,10-10);
        glColor3f(0.82,0.0,0.0);
        circle(2.0,2.0,-30+30,10-10);
        glColor3f(0.86,0.18,0.01);
        circle(1.5,1.5,-30+30,10-10);
        glColor3f(0.91,0.36,0.02);
        circle(1,1,-30+30,10-10);
        glColor3f(1.0,0.84,0.04);
        circle(0.5,0.5,-30+30,10-10);


        // sit 1
        glColor3f(0.02,0.4,0.71);
        circle(3,3,-30+30,-3-10);





        // sit 2
        glColor3f(1.0,0.89,0.11);
        circle(3,3,-37.7+30,0.8-10);




        // sit 3
        glColor3f(0.94,0.14,0.24);
        circle(3,3,-41+30,8-10);




         // sit 4
        glColor3f(0.51,0.22,0.93);
        circle(3,3,-39+30,17-10);




        // sit 5
        glColor3f(0.0,0.3,0.0);
        circle(3,3,-30+30,21.5-10);



        // sit 6
        glColor3f(0.02,0.84,0.63);
        circle(3,3,-21+30,17-10);




        // sit 7
        glColor3f(0.97,0.15,0.52);
        circle(3,3,-18.3+30,8-10);




        // sit 8
        glColor3f(0.44,0.88,0.0);
        circle(3,3,-22+30,0.8-10);








glPopMatrix();
        glPopMatrix();

         spin = spin +.1;
        glutPostRedisplay();




}

void underground()
{
    //under ground
        glBegin(GL_POLYGON);
        glColor3f(0.0,0.2,0.0);
        glVertex3d(-50,0,0);
        glVertex3d(50, 0, 0);
        glColor3f(0.02,0.96,0.0);
        glVertex3d(50,-40,0);
        glVertex3d(-50,-40,0);
        glEnd();

        //small plant 1 1
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-19,-33-5,0.0);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14,-35-5,0);
        glEnd();
        //small plant 1 2
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-17.5,-31-5,0.14);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14,-35-5,0);
        glEnd();
        //small plant 1 3
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-15,-30-5,0.14);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14,-35-5,0);
        glEnd();

        //small plant 1 4
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-12,-31-5,0.14);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14,-35-5,0);
        glEnd();
         //small plant 1 5
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-11,-33-5,0.14);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14,-35-5,0);
        glEnd();


        //small///plant 2
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16-10, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-19-10,-33-5,0.0);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14-10,-35-5,0);
        glEnd();
        //small plant 1 2
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16-10, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-18-10,-31-5,0.14);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14-10,-35-5,0);
        glEnd();
        //small plant 1 3
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16-10, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-15-10,-30-5,0.14);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14-10,-35-5,0);
        glEnd();

        //small plant 1 4
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16-10, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-12-10,-31-5,0.14);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14-10,-35-5,0);
        glEnd();
         //small plant 1 5
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16-10, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-11-10,-33-5,0.14);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14-10,-35-5,0);
        glEnd();



        //small///plant 2
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16+20, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-19+20,-33-5,0.0);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14+20,-35-5,0);
        glEnd();
        //small plant 1 2
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16+20, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-18+20,-31-5,0.14);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14+20,-35-5,0);
        glEnd();
        //small plant 1 3
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16+20, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-15+20,-30-5,0.14);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14+20,-35-5,0);
        glEnd();

        //small plant 1 4
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16+20, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-12+20,-31-5,0.14);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14+20,-35-5,0);
        glEnd();
         //small plant 1 5
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16+20, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-11+20,-33-5,0.14);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14+20,-35-5,0);
        glEnd();
        //small///plant 2
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16+10, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-19+10,-33-5,0.0);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14+10,-35-5,0);
        glEnd();
        //small plant 1 2
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16+10, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-18+10,-31-5,0.14);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14+10,-35-5,0);
        glEnd();
        //small plant 1 3
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16+10, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-15+10,-30-5,0.14);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14+10,-35-5,0);
        glEnd();

        //small plant 1 4
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16+10, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-12+10,-31-5,0.14);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14+10,-35-5,0);
        glEnd();
         //small plant 1 5
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16+10, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-11+10,-33-5,0.14);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14+10,-35-5,0);
        glEnd();
        //small///plant 2
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16+30, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-19+30,-33-5,0.0);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14+30,-35-5,0);
        glEnd();
        //small plant 1 2
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16+30, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-18+30,-31-5,0.14);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14+30,-35-5,0);
        glEnd();
        //small plant 1 3
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16+30, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-15+30,-30-5,0.14);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14+30,-35-5,0);
        glEnd();

        //small plant 1 4
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16+30, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-12+30,-31-5,0.14);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14+30,-35-5,0);
        glEnd();
         //small plant 1 5
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16+30, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-11+30,-33-5,0.14);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14+30,-35-5,0);
        glEnd();
        //small///plant 2
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16+40, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-19+40,-33-5,0.0);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14+40,-35-5,0);
        glEnd();
        //small plant 1 2
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16+40, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-18+40,-31-5,0.14);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14+40,-35-5,0);
        glEnd();
        //small plant 1 3
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16+40, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-15+40,-30-5,0.14);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14+40,-35-5,0);
        glEnd();

        //small plant 1 4
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16+40, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-12+40,-31-5,0.14);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14+40,-35-5,0);
        glEnd();
         //small plant 1 5
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-16+40, -35-5, 0);
        glColor3f(0.75,0.95,0.14);
        glVertex3d(-11+40,-33-5,0.14);
        glColor3f(0.5,0.86,0.11);
        glVertex3d(-14+40,-35-5,0);
        glEnd();


}
void background()
{


        glBegin(GL_POLYGON);
        glColor3f(r, g, b);
        //glColor3f(swingx+8.74,0.6,swingx+9.4);
        glVertex3d(-50,0,0);
        glVertex3d(-50, 500, 0);
        glVertex3d(50,50,0);
        glColor3f(0.47,0.81,1.0);///
        glVertex3d(50,0,0);

        glEnd();

        //cloud
        //cloud
        cloud();



        glColor3f(0.6,0.85,0.5);
        circle(6,30,47,10);
        glColor3f(0.6,0.85,0.3);
        circle(6,30,37,0);
        circle(6,30,43,-4);
        glColor3f(0.6,0.85,0.3);
        circle(6,6,44,10);

        glColor3f(0.6,0.85,0.3);
        circle(4,12,40,-3);

        glColor3f(0.6,0.85,0.3);
        circle(4,12,35,8);
        glColor3f(0.6,0.85,0.3);
        circle(4,12,30,-3);

        glColor3f(0.6,0.85,0.3);
        circle(4,12,25,4);
        glColor3f(0.6,0.85,0.3);
        circle(4,12,18,-3);

        glColor3f(0.6,0.85,0.3);
        circle(4,12,12,-8);
        glColor3f(0.6,0.85,0.3);
        circle(4,12,7,-8.5);
        glColor3f(0.6,0.85,0.3);
        circle(4,12,3,-9);

        circle(4,12,-1,-10);
        glColor3f(0.6,0.85,0.3);
        circle(4,12,-5,-11);
        glColor3f(0.6,0.85,0.3);
        circle(4,12,-8,-10.4);
        glColor3f(0.6,0.85,0.3);
        circle(4,12,-11,-10.4);
        glColor3f(0.6,0.85,0.3);
        circle(4,12,-14,-10.4);
        glColor3f(0.6,0.85,0.3);
        circle(4,12,-17,-10.4);
        glColor3f(0.6,0.85,0.3);
        circle(4,12,-20,-10.4);
        glColor3f(0.6,0.85,0.3);
        circle(4,12,-24,-10.4);
        glColor3f(0.6,0.85,0.3);
        circle(4,12,-27,-10.4);
        glColor3f(0.6,0.85,0.3);
        circle(4,12,-30,-10.4);
        glColor3f(0.6,0.85,0.3);
        circle(4,12,-33,-10.6);
        glColor3f(0.6,0.85,0.3);
        circle(4,12,-36,-10.8);
        glColor3f(0.6,0.85,0.3);
        circle(4,12,-39,-10.6);
        glColor3f(0.6,0.85,0.3);
        circle(4,12,-41,-10.6);
        glColor3f(0.6,0.85,0.3);
        circle(4,12,-44,-10.6);
        glColor3f(0.6,0.85,0.3);
        circle(4,12,-47,-10.6);

        circle(4,12,-49,-10.9);




}

void horse_spinner()
{
       glColor3f(0.0,0.34,0.0);
       circle(13,5,37,-12);
     //Horse plate
        glColor3f(swingx+7.21,0.8,swingx+6.59);
        //9glColor3f(0.8,0.8,0);
        circle(12,4,35,-11);
        glColor3f(1,1,0);
        circle(12,4,35,-10);
        //Horse triangle
        glBegin(GL_TRIANGLES);
        glColor3f(0.8,0,0);
        glVertex3d(20,10,0);
        glVertex3d(35,20,0);
        glVertex3d(23,10,0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glColor3f(0,0.8,0);
        glVertex3d(23,10,0);
        glVertex3d(35,20,0);
        glVertex3d(26,10,0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glColor3f(0,0,0.8);
        glVertex3d(26,10,0);
        glVertex3d(35,20,0);
        glVertex3d(29,10,0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glColor3f(0.8,0,0);
        glVertex3d(29,10,0);
        glVertex3d(35,20,0);
        glVertex3d(32,10,0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glColor3f(0,0.8,0);
        glVertex3d(32,10,0);
        glVertex3d(35,20,0);
        glVertex3d(34.5,10,0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glColor3f(0,0,0.8);
        glVertex3d(34.5,10,0);
        glVertex3d(35,20,0);
        glVertex3d(37,10,0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glColor3f(0.8,0,0);
        glVertex3d(37,10,0);
        glVertex3d(35,20,0);
        glVertex3d(40,10,0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glColor3f(0,0.8,0);
        glVertex3d(40,10,0);
        glVertex3d(35,20,0);
        glVertex3d(43,10,0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glColor3f(0,0,0.8);
        glVertex3d(43,10,0);
        glVertex3d(35,20,0);
        glVertex3d(46,10,0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glColor3f(0.8,0,0);
        glVertex3d(46,10,0);
        glVertex3d(35,20,0);
        glVertex3d(49,10,0);
        glEnd();

        //horse piller 2^
        glBegin(GL_POLYGON);
        glColor3f(0.8,0.8,0);
        glVertex3d(29.5,-7.7,0);
        glVertex3d(29.5, 10, 0);
        glColor3f(0.99,0.99,1);
        glVertex3d(30.3,10,0);
        glVertex3d(30.3,-7.7,0);
        glEnd();
        //horse piller 4^
        glBegin(GL_POLYGON);
        glColor3f(0.8,0.8,0);
        glVertex3d(37,-7.7,0);
        glVertex3d(37, 10, 0);
        glColor3f(0.9,0.9,1);
        glVertex3d(37.8,10,0);
        glVertex3d(37.8,-7.7,0);
        glEnd();
        //horse piller 6
        glBegin(GL_POLYGON);
        glColor3f(0.8,0.8,0);
        glVertex3d(43.5,-10,0);
        glVertex3d(43.5, 10, 0);
        glColor3f(0.9,0.9,1);
        glVertex3d(44.3,10,0);
        glVertex3d(44.3,-10,0);
        glEnd();
        //horse roof
        glBegin(GL_POLYGON);
        glColor3f(0.8,0,0);
        glVertex3d(25,8,0);
        glVertex3d(25, 9, 0);
        glVertex3d(44,9,0);
        glVertex3d(44,8,0);
        glEnd();
        //horse roof middle
        glBegin(GL_POLYGON);
        glColor3f(0,0,0.8);
        glVertex3d(25,8.4,0);
        glVertex3d(25, 8.5, 0);
        glColor3f(0,0,0);
        glVertex3d(44,8.5,0);
        glVertex3d(44,8.4,0);
        glEnd();
        //horse piller 1
        glBegin(GL_POLYGON);
        glColor3f(0.8,0.8,0);
        glVertex3d(25,-10,0);
        glVertex3d(25, 10, 0);
        glColor3f(0.9,0.9,1);
        glVertex3d(25.8,10,0);
        glVertex3d(25.8,-10,0);
        glEnd();

        //horse piller 1 horse 1
        glColor3f(0.54,0.06,0.26);
        circle(3.5,1,25,horse1y-2.5);
        glColor3f(-0.75,0.75,0);
        circle(3.5,1,25,horse1y-2);
        //lips
        glBegin(GL_TRIANGLES);
        glColor3f(0,0,0.8);
        glVertex3d(20,horse1y+1.6,0);
        glVertex3d(22,horse1y+3,0);
        glVertex3d(23,horse1y+1,0);
        glEnd();
        //belly
        circle(3.5,2,25,horse1y);

        //head
        circle(1.7,2,23,horse1y+2);
        //eyes
        glColor3f(0,0,0);
        circle(0.3,0.3,22.5,horse1y+2);
        //tail
        glBegin(GL_TRIANGLES);
        glColor3f(0,0,0.8);
        glVertex3d(26,horse1y-1,0);
        glVertex3d(28,horse1y+4,0);
        glVertex3d(30,horse1y+3,0);
        glEnd();






        //horse piller 2
        glBegin(GL_POLYGON);
        glColor3f(0.8,0.8,0);
        glVertex3d(28.5,-12,0);
        glVertex3d(28.5, 10, 0);
        glColor3f(0.9,0.9,1);
        glVertex3d(29.3,10,0);
        glVertex3d(29.3,-12,0);
        glEnd();

        //horse piller 3
        glBegin(GL_POLYGON);
        glColor3f(0.8,0.8,0);
        glVertex3d(33,-12.5,0);
        glVertex3d(33, 10, 0);
        glColor3f(0.9,0.9,1);
        glVertex3d(33.8,10,0);
        glVertex3d(33.8,-12.5,0);
        glEnd();

        //horse piller 3 horse 2
        glColor3f(-0.75,1,0);
        circle(3.5,1,33,horse2y-2.5);
        glColor3f(-0.75,0.75,0);
        circle(3.5,1,33,horse2y-2);
        //lips
        glBegin(GL_TRIANGLES);
        glColor3f(0.58,0.02,0.24);
        glVertex3d(28,horse2y+1.6,0);
        glVertex3d(30,horse2y+3,0);
        glVertex3d(31,horse2y+1,0);
        glEnd();
        //belly
        circle(3.5,2,33,horse2y+0);

        //head
        circle(1.7,2,31,horse2y+2);
        //eyes
        glColor3f(0,0,0);
        circle(0.3,0.3,30.5,horse2y+2);
        //tail
        glBegin(GL_TRIANGLES);
        glColor3f(0.58,0.02,0.24);
        glVertex3d(34,horse2y-1,0);
        glVertex3d(36,horse2y+4,0);
        glVertex3d(38,horse2y+3,0);
        glEnd();



        //horse piller 4
        glBegin(GL_POLYGON);
        glColor3f(0.8,0.8,0);
        glVertex3d(36.5,-12.5,0);
        glVertex3d(36.5, 10, 0);
        glColor3f(0.9,0.9,1);
        glVertex3d(37.3,10,0);
        glVertex3d(37.3,-12.5,0);
        glEnd();

        //horse piller 5
        glBegin(GL_POLYGON);
        glColor3f(0.8,0.8,0);
        glVertex3d(40,-12.5,0);
        glVertex3d(40, 10, 0);
        glColor3f(0.9,0.9,1);
        glVertex3d(40.8,10,0);
        glVertex3d(40.8,-12.5,0);
        glEnd();
        //horse piller 5 horse 33
        glColor3f(0.95,0.33,0.15);
        circle(3.5,1,40,horse3y-2.5);
        glColor3f(-0.75,0.75,0);
        circle(3.5,1,40,horse3y-2);
        //lips
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,1,1);
        glVertex3d(35,horse3y+1.6,0);
        glVertex3d(37,horse3y+3,0);
        glVertex3d(38,horse3y+1,0);
        glEnd();
        //belly
        circle(3.5,2,40,horse3y+0);

        //head
        circle(1.7,2,38,horse3y+2);
        //eyes
        glColor3f(0,0,0);
        circle(0.3,0.3,37.5,horse3y+2);
        //tail
        glBegin(GL_TRIANGLES);
        glColor3f(0.5,1,1);
        glVertex3d(41,horse3y-1,0);
        glVertex3d(43,horse3y+4,0);
        glVertex3d(45,horse3y+3,0);
        glEnd();

}

void plane()

{
     glBegin(GL_POLYGON);
    glColor3f( 0.2,0.2,1);
    glVertex3d(pl-7,24,0);
    glVertex3d(pl-5,25,0);
    glVertex3d(pl-7,27,0);
    glVertex3d(pl-15,27,0);
    glVertex3d(pl-15,24,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f( 0.3,0.88,1);

    glVertex3d(pl-5,25,0);
    glVertex3d(pl-7,27,0);
    glVertex3d(pl-9,27,0);
    glVertex3d(pl-9,25,0);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f( 0.03,0,0.1);
     glVertex3d(pl-15,27,0);
     glVertex3d(pl-17,30,0);
    glVertex3d(pl-19,30,0);
    glVertex3d(pl-15,24,0);


    glEnd();

//finn
    glBegin(GL_POLYGON);
    glColor3f( 0.3,0,0);
     glVertex3d(pl-13,21,0);
     glVertex3d(pl-10,24,0);
    glVertex3d(pl-12,24,0);
    glVertex3d(pl-14,21.5,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f( 0.3,0,0);
    glVertex3d(pl-10,25,0);
     glVertex3d(pl-13,28,0);
     glVertex3d(pl-16,26,0);
    glVertex3d(pl-12,25,0);
    glEnd();
}

void train2()
{

        /// moving head down
        glPushMatrix();
        glTranslatef(15,-15,0);
        glColor3f(0.91,0.38,0.1);
        circle(1.2,1.2,trnx-34.12,trny+10.5);

		glPushMatrix();
        glTranslatef(0,3,0);
        glBegin(GL_POLYGON);
        glColor3f(0.91,0.38,0.1);
        glVertex2d(trnx-35.25,trny+7);
        glVertex2d(trnx-35.25,trny+11);
        glVertex2d(trnx-33,trny+11);
        glVertex2d(trnx-33,trny+7);
        glEnd();
        glPopMatrix();



        glPushMatrix();
        glTranslatef(0,3,0);
        glBegin(GL_POLYGON);
        glColor3f(0.91,0.38,0.1);
        glVertex2d(trnx-35.25,trny+7);
        glVertex2d(trnx-35.25,trny+11);
        glVertex2d(trnx-35.25,trny+11);
        glVertex2d(trnx-35.25,trny+7);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,3,0);
        glBegin(GL_POLYGON);
        glColor3f(0.95,0.15,0.26);
        glVertex2d(trnx-35,trny+8.5);
        glVertex2d(trnx-35,trny+10.4);
        glVertex2d(trnx-33.5,trny+10.4);
        glVertex2d(trnx-33.5,trny+8.5);
        glEnd();
        glPopMatrix();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(15,0,0);
        ///connectet
        glPushMatrix();
        glTranslatef(17,-19.5,0);
        glBegin(GL_POLYGON);
        glColor3f(1,0,0);
        glVertex2d(trnx-49.35,trny+25);
        glVertex2d(trnx-49.35, trny+27);
        glVertex2d(trnx-49, trny+27);
        glVertex2d(trnx-49,trny+25);
        glEnd();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(17,-24.5,0);
        glBegin(GL_POLYGON);
        glColor3f(1,0,0);
        glVertex2d(trnx-49.35,trny+25);
        glVertex2d(trnx-49.35, trny+27);
        glVertex2d(trnx-49, trny+27);
        glVertex2d(trnx-49,trny+25);
        glEnd();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-3.5,0,0);
        glPushMatrix();
        glTranslatef(17,-19.5,0);
        glBegin(GL_POLYGON);
        glColor3f(1,0,0);
        glVertex2d(trnx-49.35,trny+25);
        glVertex2d(trnx-49.35, trny+27);
        glVertex2d(trnx-49, trny+27);
        glVertex2d(trnx-49,trny+25);
        glEnd();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(17,-24.5,0);
        glBegin(GL_POLYGON);
        glColor3f(1,0,0);
        glVertex2d(trnx-49.35,trny+25);
        glVertex2d(trnx-49.35, trny+27);
        glVertex2d(trnx-49, trny+27);
        glVertex2d(trnx-49,trny+25);
        glEnd();
        glPopMatrix();
        glPopMatrix();






        glBegin(GL_POLYGON);
        glColor3f(0.19,0.59,0.9);
        glVertex2d(trnx-36,trny+7);
        glVertex2d(trnx-36,trny+11);
        glColor3f(0,0,0.4);
        glVertex2d(trnx-32,trny+11);
        glVertex2d(trnx-32,trny+7);
        glEnd();


        glPushMatrix();
        glTranslatef(0,-5,0);
        glBegin(GL_POLYGON);
         glColor3f(0.19,0.59,0.9);
        glVertex2d(trnx-36,trny+7);
        glVertex2d(trnx-36,trny+11);
        glColor3f(0,0,0.4);
        glVertex2d(trnx-32,trny+11);
        glVertex2d(trnx-32,trny+7);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,-10,0);
        glBegin(GL_POLYGON);
         glColor3f(0.19,0.59,0.9);
        glVertex2d(trnx-36,trny+7);
        glVertex2d(trnx-36,trny+11);
        glColor3f(0,0,.4);
        glVertex2d(trnx-32,trny+11);
        glVertex2d(trnx-32,trny+7);
        glEnd();
        glPopMatrix();
        glPopMatrix();


}
void train1()
{

        glPushMatrix();
        glTranslatef(15,0,0);
        ///connectet
        glPushMatrix();
        glTranslatef(17,-19.5,0);
        glBegin(GL_POLYGON);
        glColor3f(1,0,0);
        glVertex2d(trnx-49.35,trny+25);
        glVertex2d(trnx-49.35, trny+27);
        glVertex2d(trnx-49, trny+27);
        glVertex2d(trnx-49,trny+25);
        glEnd();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(17,-24.5,0);
        glBegin(GL_POLYGON);
        glColor3f(1,0,0);
        glVertex2d(trnx-49.35,trny+25);
        glVertex2d(trnx-49.35, trny+27);
        glVertex2d(trnx-49, trny+27);
        glVertex2d(trnx-49,trny+25);
        glEnd();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-3.5,0,0);
        glPushMatrix();
        glTranslatef(17,-19.5,0);
        glBegin(GL_POLYGON);
        glColor3f(1,0,0);
        glVertex2d(trnx-49.35,trny+25);
        glVertex2d(trnx-49.35, trny+27);
        glVertex2d(trnx-49, trny+27);
        glVertex2d(trnx-49,trny+25);
        glEnd();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(17,-24.5,0);
        glBegin(GL_POLYGON);
        glColor3f(1,0,0);
        glVertex2d(trnx-49.35,trny+25);
        glVertex2d(trnx-49.35, trny+27);
        glVertex2d(trnx-49, trny+27);
        glVertex2d(trnx-49,trny+25);
        glEnd();
        glPopMatrix();
        glPopMatrix();

        glColor3f(0.91,0.38,0.1);
        circle(1.2,1.2,trnx-34.12,trny+13.5);

		glPushMatrix();
        glTranslatef(0,3,0);
        glBegin(GL_POLYGON);
        glColor3f(0.91,0.38,0.1);
        glVertex2d(trnx-35.25,trny+7);
        glVertex2d(trnx-35.25,trny+11);
        glVertex2d(trnx-33,trny+11);
        glVertex2d(trnx-33,trny+7);
        glEnd();
        glPopMatrix();



        glPushMatrix();
        glTranslatef(0,3,0);
        glBegin(GL_POLYGON);
        glColor3f(0.91,0.38,0.1);
        glVertex2d(trnx-35.25,trny+7);
        glVertex2d(trnx-35.25,trny+11);
        glVertex2d(trnx-35.25,trny+11);
        glVertex2d(trnx-35.25,trny+7);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,3,0);
        glBegin(GL_POLYGON);
        glColor3f(0.95,0.15,0.26);
        glVertex2d(trnx-35,trny+8.5);
        glVertex2d(trnx-35,trny+10.4);
        glVertex2d(trnx-33.5,trny+10.4);
        glVertex2d(trnx-33.5,trny+8.5);
        glEnd();
        glPopMatrix();




        glBegin(GL_POLYGON);
        glColor3f(0.19,0.59,0.9);
        glVertex2d(trnx-36,trny+7);
        glVertex2d(trnx-36,trny+11);
        glColor3f(0,0,0.4);
        glVertex2d(trnx-32,trny+11);
        glVertex2d(trnx-32,trny+7);
        glEnd();


        glPushMatrix();
        glTranslatef(0,-5,0);
        glBegin(GL_POLYGON);
         glColor3f(0.19,0.59,0.9);
        glVertex2d(trnx-36,trny+7);
        glVertex2d(trnx-36,trny+11);
        glColor3f(0,0,0.4);
        glVertex2d(trnx-32,trny+11);
        glVertex2d(trnx-32,trny+7);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,-10,0);
        glBegin(GL_POLYGON);
         glColor3f(0.19,0.59,0.9);
        glVertex2d(trnx-36,trny+7);
        glVertex2d(trnx-36,trny+11);
        glColor3f(0,0,.4);
        glVertex2d(trnx-32,trny+11);
        glVertex2d(trnx-32,trny+7);
        glEnd();
        glPopMatrix();
        glPopMatrix();

}
void train()
{
     glColor3f(0.53,0.49,0.42);
     circle(1.7,1.5,trnx-17,trny+10);
     circle(2.7,2.5,trnx-13.5,trny+15);
    	  //connector
      glPushMatrix();
      glTranslatef(6.5,1,0);
      glBegin(GL_POLYGON);
      glColor3f(1,0,0);
      glVertex2d(trnx-19.1,trny+.8);
      glVertex2d(trnx-19.1,trny+1.2);
      glVertex2d(trnx-17,trny+1.2);
      glVertex2d(trnx-17,trny+.8);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(11.5,1,0);
      glBegin(GL_POLYGON);
      glColor3f(1,0,0);
      glVertex2d(trnx-19.1,trny+.8);
      glVertex2d(trnx-19.1,trny+1.2);
      glVertex2d(trnx-17,trny+1.2);
      glVertex2d(trnx-17,trny+.8);
      glEnd();
      glPopMatrix();

      //child train going left
      glBegin(GL_POLYGON);
      glColor3f(0.91,0.38,0.1);
      glVertex2d(trnx-19,trny+1);
      glVertex2d(trnx-19,trny+5);
      glVertex2d(trnx-15,trny+5);
      glVertex2d(trnx-15,trny+1);
      glEnd();
      //child
      circle(2,2,trnx-18,trny+3);


      ///  while
      glPushMatrix();
      glTranslatef(2,0,0);
      circle(2,2,trnx-18,trny+3);
      glColor3f(0.28,0.11,0.12);
      circle(.7,.7,trnx-19,trny+1);
      glColor3f(1,1,1);
      circle(.40,.40,trnx-19,trny+1);
      glPopMatrix();
      glColor3f(0.28,0.11,0.12);
      circle(.7,.7,trnx-19,trny+1);
      glColor3f(1,1,1);
      circle(.40,.40,trnx-19,trny+1);
      glBegin(GL_POLYGON);
      glColor3f(0,0,0);
      glVertex2d(trnx-19.1,trny+.8);
      glVertex2d(trnx-19.1,trny+1.2);
      glVertex2d(trnx-17,trny+1.2);
      glVertex2d(trnx-17,trny+.8);
      glEnd();



      //2nd box
      glBegin(GL_POLYGON);
      glColor3f(0.19,0.59,0.9);
      glVertex2d(trnx-16,trny+1);
      glVertex2d(trnx-16,trny+8);
      glColor3f(0,0,0.9);
      glVertex2d(trnx-12,trny+8);
      glVertex2d(trnx-12,trny+1);
      glEnd();
      glBegin(GL_POLYGON);
      glColor3f(1,1,01);
      glVertex2d(trnx-15,trny+4);
      glVertex2d(trnx-15,trny+7);
      glColor3f(0,0,0.9);
      glVertex2d(trnx-13,trny+7);
      glVertex2d(trnx-13,trny+4);
      glEnd();
      glBegin(GL_POLYGON);
      glColor3f(1,1,01);
      glVertex2d(trnx-15,trny+5);
      glVertex2d(trnx-15,trny+7);
      glColor3f(0,0,0);
      glVertex2d(trnx-13,trny+7);
      glVertex2d(trnx-13,trny+5);
      glEnd();
      ///1nd cabin
      glPushMatrix();
      glTranslatef(5,0,0);
      glBegin(GL_POLYGON);
      glColor3f(0.19,0.59,0.9);
      glVertex2d(trnx-16,trny+1);
      glVertex2d(trnx-16,trny+5);
      glColor3f(0,0,0.9);
      glVertex2d(trnx-12,trny+5);
      glVertex2d(trnx-12,trny+1);
      glEnd();
      glPopMatrix();
      glPushMatrix();
      glTranslatef(5,0,0);
      glBegin(GL_POLYGON);
      glColor3f(1,1,0);
      glVertex2d(trnx-16,trny+3);
      glVertex2d(trnx-16,trny+3.8);
      glColor3f(0,0,0.9);
      glVertex2d(trnx-12,trny+3.8);
      glVertex2d(trnx-12,trny+3);
      glEnd();
      glPopMatrix();
      glPushMatrix();
      glTranslatef(0,0,0);
      glBegin(GL_POLYGON);
      glColor3f(1,1,0);
      glVertex2d(trnx-16,trny+3);
      glVertex2d(trnx-16,trny+3.8);
      glColor3f(0,0,0.9);
      glVertex2d(trnx-12,trny+3.8);
      glVertex2d(trnx-12,trny+3);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-4,0,0);
      glBegin(GL_POLYGON);
      glColor3f(1,0,0);
      glVertex2d(trnx-16,trny+3);
      glVertex2d(trnx-16,trny+3.8);
      glColor3f(0,0,00);
      glVertex2d(trnx-12,trny+3.8);
      glVertex2d(trnx-12,trny+3);
      glEnd();
      glPopMatrix();
      /// ///  chaka2
      glPushMatrix();
      glTranslatef(9,0,0);
      glPushMatrix();
      glTranslatef(2,0,0);
      glColor3f(0.28,0.11,0.12);
      circle(.7,.7,trnx-19,trny+1);
      glColor3f(1,1,1);
      circle(.40,.40,trnx-19,trny+1);
      glPopMatrix();
      glColor3f(0.28,0.11,0.12);
      circle(.7,.7,trnx-19,trny+1);
      glColor3f(1,1,1);
      circle(.40,.40,trnx-19,trny+1);
      glBegin(GL_POLYGON);
      glColor3f(0,0,0);
      glVertex2d(trnx-19.1,trny+.8);
      glVertex2d(trnx-19.1,trny+1.2);
      glVertex2d(trnx-17,trny+1.2);
      glVertex2d(trnx-17,trny+.8);
      glEnd();
      ///
      glPopMatrix();
      ///2nd cabin
      glPushMatrix();
      glTranslatef(10,0,0);
      glBegin(GL_POLYGON);
      glColor3f(0.19,0.59,0.9);
      glVertex2d(trnx-16,trny+1);
      glVertex2d(trnx-16,trny+5);
      glColor3f(0,0,0.9);
      glVertex2d(trnx-12,trny+5);
      glVertex2d(trnx-12,trny+1);
      glEnd();
      glPopMatrix();
      glPushMatrix();
      glTranslatef(10,0,0);
      glBegin(GL_POLYGON);
      glColor3f(1,1,0);
      glVertex2d(trnx-16,trny+3);
      glVertex2d(trnx-16,trny+3.8);
      glColor3f(0,0,0.9);
      glVertex2d(trnx-12,trny+3.8);
      glVertex2d(trnx-12,trny+3);
      glEnd();
      glPopMatrix();
      /// ///  chaka3
      glPushMatrix();
      glTranslatef(14,0,0);
      glPushMatrix();
      glTranslatef(2,0,0);
      glColor3f(0.28,0.11,0.12);
      circle(.7,.7,trnx-19,trny+1);
      glColor3f(1,1,1);
      circle(.40,.40,trnx-19,trny+1);
      glPopMatrix();
      glColor3f(0.28,0.11,0.12);
      circle(.7,.7,trnx-19,trny+1);
      glColor3f(1,1,1);
      circle(.40,.40,trnx-19,trny+1);
      glBegin(GL_POLYGON);
      glColor3f(0,0,0);
      glVertex2d(trnx-19.1,trny+.8);
      glVertex2d(trnx-19.1,trny+1.2);
      glVertex2d(trnx-17,trny+1.2);
      glVertex2d(trnx-17,trny+.8);
      glEnd();
      ///
      glPopMatrix();

      ///stream out
      glBegin(GL_POLYGON);
      glColor3f(0.95,0.15,0.26);
      glVertex2d(trnx-18.7,trny+5);
      glVertex2d(trnx-19,trny+7 );
      glVertex2d(trnx-17,trny+7);
      glVertex2d(trnx-17.6, trny+5);
      glEnd();

      ///chaka big
      glPushMatrix();
      glTranslatef(5,0,0);
      glColor3f(0.28,0.11,0.12);
      circle(1.2,1.2,trnx-19,trny+1);
      glColor3f(1,1,1);
      circle(.40,.40,trnx-19,trny+1);
      glPopMatrix();
}

void train3()
{
     glColor3f(0.53,0.49,0.42);
     circle(1.7,1.5,trnxx-17,trnyy+10);
     circle(2.7,2.5,trnxx-13,trnyy+15);
    	  //connector
      glPushMatrix();
      glTranslatef(6.5,1,0);
      glBegin(GL_POLYGON);
      glColor3f(1,0,0);
      glVertex2d(trnxx-19.1,trnyy+.8);
      glVertex2d(trnxx-19.1,trnyy+1.2);
      glVertex2d(trnxx-17,trnyy+1.2);
      glVertex2d(trnxx-17,trnyy+.8);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(11.5,1,0);
      glBegin(GL_POLYGON);
      glColor3f(1,0,0);
      glVertex2d(trnxx-19.1,trnyy+.8);
      glVertex2d(trnxx-19.1,trnyy+1.2);
      glVertex2d(trnxx-17,trnyy+1.2);
      glVertex2d(trnxx-17,trnyy+.8);
      glEnd();
      glPopMatrix();

      //child train going left
      glBegin(GL_POLYGON);
      glColor3f(0.91,0.38,0.1);
      glVertex2d(trnxx-19,trnyy+1);
      glVertex2d(trnxx-19,trnyy+5);
      glVertex2d(trnxx-15,trnyy+5);
      glVertex2d(trnxx-15,trnyy+1);
      glEnd();
      //child
      circle(2,2,trnxx-18,trnyy+3);


      ///  while
      glPushMatrix();
      glTranslatef(2,0,0);
      circle(2,2,trnxx-18,trnyy+3);
      glColor3f(0.28,0.11,0.12);
      circle(.7,.7,trnxx-19,trnyy+1);
      glColor3f(1,1,1);
      circle(.40,.40,trnxx-19,trnyy+1);
      glPopMatrix();
      glColor3f(0.28,0.11,0.12);
      circle(.7,.7,trnxx-19,trnyy+1);
      glColor3f(1,1,1);
      circle(.40,.40,trnxx-19,trnyy+1);
      glBegin(GL_POLYGON);
      glColor3f(0,0,0);
      glVertex2d(trnxx-19.1,trnyy+.8);
      glVertex2d(trnxx-19.1,trnyy+1.2);
      glVertex2d(trnxx-17,trnyy+1.2);
      glVertex2d(trnxx-17,trnyy+.8);
      glEnd();



      //2nd box
      glBegin(GL_POLYGON);
      glColor3f(0.19,0.59,0.9);
      glVertex2d(trnxx-16,trnyy+1);
      glVertex2d(trnxx-16,trnyy+8);
      glColor3f(0,0,0.9);
      glVertex2d(trnxx-12,trnyy+8);
      glVertex2d(trnxx-12,trnyy+1);
      glEnd();
      glBegin(GL_POLYGON);
      glColor3f(1,1,01);
      glVertex2d(trnxx-15,trnyy+4);
      glVertex2d(trnxx-15,trnyy+7);
      glColor3f(0,0,0.9);
      glVertex2d(trnxx-13,trnyy+7);
      glVertex2d(trnxx-13,trnyy+4);
      glEnd();
      glBegin(GL_POLYGON);
      glColor3f(1,1,01);
      glVertex2d(trnxx-15,trnyy+5);
      glVertex2d(trnxx-15,trnyy+7);
      glColor3f(0,0,0);
      glVertex2d(trnxx-13,trnyy+7);
      glVertex2d(trnxx-13,trnyy+5);
      glEnd();
      ///1nd cabin
      glPushMatrix();
      glTranslatef(5,0,0);
      glBegin(GL_POLYGON);
      glColor3f(0.19,0.59,0.9);
      glVertex2d(trnxx-16,trnyy+1);
      glVertex2d(trnxx-16,trnyy+5);
      glColor3f(0,0,0.9);
      glVertex2d(trnxx-12,trnyy+5);
      glVertex2d(trnxx-12,trnyy+1);
      glEnd();
      glPopMatrix();
      glPushMatrix();
      glTranslatef(5,0,0);
      glBegin(GL_POLYGON);
      glColor3f(1,1,0);
      glVertex2d(trnxx-16,trnyy+3);
      glVertex2d(trnxx-16,trnyy+3.8);
      glColor3f(0,0,0.9);
      glVertex2d(trnxx-12,trnyy+3.8);
      glVertex2d(trnxx-12,trnyy+3);
      glEnd();
      glPopMatrix();
      glPushMatrix();
      glTranslatef(0,0,0);
      glBegin(GL_POLYGON);
      glColor3f(1,1,0);
      glVertex2d(trnxx-16,trnyy+3);
      glVertex2d(trnxx-16,trnyy+3.8);
      glColor3f(0,0,0.9);
      glVertex2d(trnxx-12,trnyy+3.8);
      glVertex2d(trnxx-12,trnyy+3);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-4,0,0);
      glBegin(GL_POLYGON);
      glColor3f(1,0,0);
      glVertex2d(trnxx-16,trnyy+3);
      glVertex2d(trnxx-16,trnyy+3.8);
      glColor3f(0,0,00);
      glVertex2d(trnxx-12,trnyy+3.8);
      glVertex2d(trnxx-12,trnyy+3);
      glEnd();
      glPopMatrix();
      /// ///  chaka2
      glPushMatrix();
      glTranslatef(9,0,0);
      glPushMatrix();
      glTranslatef(2,0,0);
      glColor3f(0.28,0.11,0.12);
      circle(.7,.7,trnxx-19,trnyy+1);
      glColor3f(1,1,1);
      circle(.40,.40,trnxx-19,trnyy+1);
      glPopMatrix();
      glColor3f(0.28,0.11,0.12);
      circle(.7,.7,trnxx-19,trnyy+1);
      glColor3f(1,1,1);
      circle(.40,.40,trnxx-19,trnyy+1);
      glBegin(GL_POLYGON);
      glColor3f(0,0,0);
      glVertex2d(trnxx-19.1,trnyy+.8);
      glVertex2d(trnxx-19.1,trnyy+1.2);
      glVertex2d(trnxx-17,trnyy+1.2);
      glVertex2d(trnxx-17,trnyy+.8);
      glEnd();
      ///
      glPopMatrix();
      ///2nd cabin
      glPushMatrix();
      glTranslatef(10,0,0);
      glBegin(GL_POLYGON);
      glColor3f(0.19,0.59,0.9);
      glVertex2d(trnxx-16,trnyy+1);
      glVertex2d(trnxx-16,trnyy+5);
      glColor3f(0,0,0.9);
      glVertex2d(trnxx-12,trnyy+5);
      glVertex2d(trnxx-12,trnyy+1);
      glEnd();
      glPopMatrix();
      glPushMatrix();
      glTranslatef(10,0,0);
      glBegin(GL_POLYGON);
      glColor3f(1,1,0);
      glVertex2d(trnxx-16,trnyy+3);
      glVertex2d(trnxx-16,trnyy+3.8);
      glColor3f(0,0,0.9);
      glVertex2d(trnxx-12,trnyy+3.8);
      glVertex2d(trnxx-12,trnyy+3);
      glEnd();
      glPopMatrix();
      /// ///  chaka3
      glPushMatrix();
      glTranslatef(14,0,0);
      glPushMatrix();
      glTranslatef(2,0,0);
      glColor3f(0.28,0.11,0.12);
      circle(.7,.7,trnxx-19,trnyy+1);
      glColor3f(1,1,1);
      circle(.40,.40,trnxx-19,trnyy+1);
      glPopMatrix();
      glColor3f(0.28,0.11,0.12);
      circle(.7,.7,trnxx-19,trnyy+1);
      glColor3f(1,1,1);
      circle(.40,.40,trnxx-19,trnyy+1);
      glBegin(GL_POLYGON);
      glColor3f(0,0,0);
      glVertex2d(trnxx-19.1,trnyy+.8);
      glVertex2d(trnxx-19.1,trnyy+1.2);
      glVertex2d(trnxx-17,trnyy+1.2);
      glVertex2d(trnxx-17,trnyy+.8);
      glEnd();
      ///
      glPopMatrix();

      ///stream out
      glBegin(GL_POLYGON);
      glColor3f(0.95,0.15,0.26);
      glVertex2d(trnxx-18.7,trnyy+5);
      glVertex2d(trnxx-19,trnyy+7 );
      glVertex2d(trnxx-17,trnyy+7);
      glVertex2d(trnxx-17.6, trnyy+5);
      glEnd();

      ///chaka big
      glPushMatrix();
      glTranslatef(5,0,0);
      glColor3f(0.28,0.11,0.12);
      circle(1.2,1.2,trnxx-19,trnyy+1);
      glColor3f(1,1,1);
      circle(.40,.40,trnxx-19,trnyy+1);
      glPopMatrix();
}
void swings()
{




     //stand  1
        glBegin(GL_POLYGON);
        glColor3f(swingx+6.79,0.2,swingx);
        glVertex3d(-11,-11,0);
        glVertex3d(-11,-10,0);
        glVertex3d(11, -10,0);
        glVertex3d(11,-11,0);
        glEnd();

        ///stand left 1
        glBegin(GL_POLYGON);
        glColor3f(swingx+6.79,0.2,swingx);
        glVertex3d(-11,-26,0);
        glVertex3d(-11,-11,0);
        glVertex3d(-10.65, -11,0);
        glVertex3d(-10.65,-26,0);
        glEnd();
        ///stand right 1
        glBegin(GL_POLYGON);
        glColor3f(swingx+6.79,0.2,swingx);
        glVertex3d(11,-26,0);
        glVertex3d(11,-11,0);
        glVertex3d(10.65, -11,0);
        glVertex3d(10.65,-26,0);
        glEnd();


        //stand  left 2 1
        glBegin(GL_POLYGON);
        glColor3f(swingx+6.79,0.2,swingx);
        glVertex3d(-11,-13,0);
        glVertex3d(-11,-10,0);
        glVertex3d(-14,-30,0);
        glVertex3d(-13.3,-30,0);
        glEnd();

        //stand  left 2 2
        glBegin(GL_POLYGON);
        glColor3f(swingx+6.79,0.2,swingx);
        glVertex3d(11,-13,0);
        glVertex3d(11,-10,0);
        glVertex3d(14,-30,0);
        glVertex3d(13.3,-30,0);
        glEnd();


        //siting root 1 1
        glBegin(GL_POLYGON);
        glColor3f(0.6,0.38,0.27);
        glVertex3d(swingx-1.41,swingy,0);
        glVertex3d(-6.59-1.41,-10,0);
        glVertex3d(-6.59-1.61,-10,0);
        glVertex3d(swingx-1.61,swingy,0);
        glEnd();
        //siting root 1 2
        glBegin(GL_POLYGON);
        glColor3f(0.6,0.38,0.27);
        glVertex3d(swingx+1.59,swingy,0);
        glVertex3d(-6.59+1.59,-10,0);
        glVertex3d(-6.59+1.79,-10,0);
        glVertex3d(swingx+1.79,swingy,0);
        glEnd();

        //siting root 2 1
        glBegin(GL_POLYGON);
        glColor3f(0.6,0.38,0.27);
        glVertex3d(swingx+5.59,-22,0);
        glVertex3d(-1,-10,0);
        glVertex3d(-1.2,-10,0);
        glVertex3d(swingx+5.39,-22,0);
        glEnd();
        //siting root 2 2
        glBegin(GL_POLYGON);
        glColor3f(0.6,0.38,0.27);
        glVertex3d(swingx+8.59,-22,0);
        glVertex3d(2,-10,0);
        glVertex3d(2.2,-10,0);
        glVertex3d(swingx+8.79,-22,0);
        glEnd();

        //siting root 3 1
        glBegin(GL_POLYGON);
        glColor3f(0.6,0.38,0.27);
        glVertex3d(swingx+12.59,-22,0);
        glVertex3d(6,-10,0);
        glVertex3d(6.2,-10,0);
        glVertex3d(swingx+12.76,-22,0);
        glEnd();
        //siting root 3 2
        glBegin(GL_POLYGON);
        glColor3f(0.6,0.38,0.27);
        glVertex3d(swingx+15.59,-22,0);
        glVertex3d(9,-10,0);
        glVertex3d(9.2,-10,0);
        glVertex3d(swingx+15.79,-22,0);
        glEnd();
        ///sit 3
        glColor3f(0,0,1);
        halfcircle_moon(1.55,1.5,swingx+14.23,-22);
        ///sit 2
        glColor3f(0.9,0.9,0.3);
        halfcircle_moon(1.55,1.5,swingx+7.14,-22);
        ///sit 1
        glColor3f(1,0,0);
        halfcircle_moon(1.55,1.5,swingx+0.1,-22);

        ///baccha log 1
        //head


        glColor3f(0.95,0.36,0.31);
        circle(0.67,0.67,swingx+0.29,-20);
        //head over cap
        glBegin(GL_TRIANGLES);
        glColor3f(0.95,0.95,0.36);
        glVertex3d(swingx-0.31,-19.5,0);
        glVertex3d(swingx+0.29,-18.1,0);
        glVertex3d(swingx+0.89,-19.5,0);
        glEnd();
        //eyes
        glColor3f(0,0,0);
        circle(0.15,0.15,swingx-0.01,-19.9);
        circle(0.15,0.15,swingx+0.59,-19.9);
        //mouth
        glBegin(GL_LINES);
        glVertex3d(swingx+0.09,-20.32,0);
        glVertex3d(swingx+0.49,-20.32,0);
        glEnd();
        //body
        glBegin(GL_POLYGON);
        glColor3f(1,01,1);
        glVertex3d(swingx-0.61,-22,0);
        glVertex3d(swingx-0.61,-20.4,0);
        glVertex3d(swingx+1.19, -20.4,0);
        glVertex3d(swingx+1.19,-22,0);
        glEnd();
        //hand 1
        glBegin(GL_POLYGON);
        glColor3f(1,01,1);
        glVertex3d(swingx-0.61,-20.4,0);
        glVertex3d(swingx-0.61,-21,0);
        glVertex3d(swingx-1.41, -19,0);
        glVertex3d(swingx-1.01,-19,0);
        glEnd();
        //hand 2
        glBegin(GL_POLYGON);
        glColor3f(1,01,1);
        glVertex3d(swingx+1.19,-21,0);
        glVertex3d(swingx+1.19, -20.4,0);
        glVertex3d(swingx+1.69, -19,0);
        glVertex3d(swingx+1.99,-19,0);
        glEnd();
        // leg pice L 1
        glBegin(GL_TRIANGLES);
        glColor3f(0.95,0.95,0.36);
        glVertex3d(swingx-0.21,-23.7,0);
        glVertex3d(swingx-0.61,-21.7,0);
        glVertex3d(swingx-0.81,-23.7,0);
        glEnd();
        // leg pice R8 1
        glBegin(GL_TRIANGLES);
        glColor3f(0.95,0.95,0.36);
        glVertex3d(swingx+1.59,-23.7,0);
        glVertex3d(swingx+1.19,-21.7,0);
        glVertex3d(swingx+0.79,-23.7,0);
        glEnd();
        //baccha log 2
        //head


        glColor3f(0.95,0.36,0.31);
        circle(0.67,0.67,swingx+7.29,-20);
        //head over cap
        glBegin(GL_TRIANGLES);
        glColor3f(0.95,0.95,0.36);
        glVertex3d(swingx+6.69,-19.5,0);
        glVertex3d(swingx+7.29,-18.1,0);
        glVertex3d(swingx+7.89,-19.5,0);
        glEnd();
        //eyes
        glColor3f(0,0,0);
        circle(0.15,0.15,swingx+6.99,-19.9);
        circle(0.15,0.15,swingx+7.59,-19.9);
        //mouth
        glBegin(GL_LINES);
        glVertex3d(swingx+7.09,-20.32,0);
        glVertex3d(swingx+7.49,-20.32,0);
        glEnd();
        //body
        glBegin(GL_POLYGON);
        glColor3f(1,01,1);
        glVertex3d(swingx+6.39,-22,0);
        glVertex3d(swingx+6.39,-20.4,0);
        glVertex3d(swingx+8.19, -20.4,0);
        glVertex3d(swingx+8.19,-22,0);
        glEnd();
        //hand 1
        glBegin(GL_POLYGON);
        glColor3f(1,01,1);
        glVertex3d(swingx+6.39,-20.4,0);
        glVertex3d(swingx+6.39,-21,0);
        glVertex3d(swingx+5.59, -19,0);
        glVertex3d(swingx+5.99,-19,0);
        glEnd();
        //hand 2
        glBegin(GL_POLYGON);
        glColor3f(1,01,1);
        glVertex3d(swingx+8.19,-21,0);
        glVertex3d(swingx+8.19, -20.4,0);
        glVertex3d(swingx+8.69, -19,0);
        glVertex3d(swingx+8.99,-19,0);
        glEnd();
        // leg pice L 1
        glBegin(GL_TRIANGLES);
        glColor3f(0,0,0);
        glVertex3d(swingx+6.79,-23.7,0);
        glVertex3d(swingx+6.39,-21.7,0);
        glVertex3d(swingx+6.19,-23.7,0);
        glEnd();
        // leg pice R8 1
        glBegin(GL_TRIANGLES);
        glColor3f(0,0,0);
        glVertex3d(swingx+8.59,-23.7,0);
        glVertex3d(swingx+8.19,-21.7,0);
        glVertex3d(swingx+7.79,-23.7,0);
        glEnd();

                glColor3f(0.95,0.36,0.31);
        circle(0.67,0.67,swingx+14.29,-20);
        //head over cap
        glBegin(GL_TRIANGLES);
        glColor3f(swingx+7.54,0.95,0.36);
        glVertex3d(swingx+13.69,-19.5,0);
        glVertex3d(swingx+14.29,-18.1,0);
        glVertex3d(swingx+14.89,-19.5,0);
        glEnd();
        //eyes
        glColor3f(0,0,0);
        circle(0.15,0.15,swingx+13.99,-19.9);
        circle(0.15,0.15,swingx+ 14.59,-19.9);
        //mouth
        glBegin(GL_LINES);
        glVertex3d(swingx+ 14.50,-20.32,0);
        glVertex3d(swingx+ 14.49,-20.32,0);
        glEnd();
        //body
        glBegin(GL_POLYGON);
        glColor3f(1,01,1);
        glVertex3d(swingx+ 13.39,-22,0);
        glVertex3d(swingx+ 13.39,-20.4,0);
        glVertex3d(swingx+ 15.19, -20.4,0);
        glVertex3d(swingx+ 15.19,-22,0);
        glEnd();
        //hand 1
        glBegin(GL_POLYGON);
        glColor3f(1,01,1);
        glVertex3d(swingx+ 13.39,-20.4,0);
        glVertex3d(swingx+ 13.39,-21,0);
        glVertex3d(swingx+ 12.59, -19,0);
        glVertex3d(swingx+ 12.99,-19,0);
        glEnd();
        //hand 2
        glBegin(GL_POLYGON);
        glColor3f(1,01,1);
        glVertex3d(swingx+ 15.19,-21,0);
        glVertex3d(swingx+ 15.19, -20.4,0);
        glVertex3d(swingx+ 15.69, -19,0);
        glVertex3d(swingx+ 15.99,-19,0);
        glEnd();
        // leg pice L 1
        glBegin(GL_TRIANGLES);
        glColor3f(swingx+7.0,0.95,0.36);
        glVertex3d(swingx+ 13.79,-23.7,0);
        glVertex3d(swingx+ 13.39,-21.7,0);
        glVertex3d(swingx+ 13,-23.7,0);
        glEnd();
        // leg pice R8 1
        glBegin(GL_TRIANGLES);
        glColor3f(swingx+7.54,0.95,0.36);
        glVertex3d(swingx+15.59,-23.7,0);
        glVertex3d(swingx+ 15.19,-21.7,0);
        glVertex3d(swingx+14.79,-23.7,0);
        glEnd();




}
void tower()
{

        glColor3f(0.0,0.25,0.0);
        circle(6, 1, 0, -1.5);

        glColor3f(0.99,0.52,0.03);
         halfcircle(0.2, 3, 0,35);
        glColor3f(0.98,0.66,0.16);
        halfcircle(1, 4, 0,33);




        glColor3f(0.99,0.49,0.03);
        halfcircle(4, 6, 0,30);

        glColor3f(0.96,0.74,0.38);

        halfcircle(1, 1, -10.9, 30);
        halfcircle(1, 1, 10.9, 30);

        halfcircle(1.6, 1.6, -8.7, 30);
        halfcircle(1.6, 1.6, 8.7, 30);

        halfcircle(2.9, 3.5, 4.9, 29.5);
        halfcircle(2.9, 3.5, 0, 30);
        halfcircle(2.9, 3.5, -4.9, 29.5);



       // tower stand  1
        glBegin(GL_POLYGON);
        glColor3f(0.98,0.93,0.05);
        glVertex3d(-1.5,-1,0);
        glColor3f(1.0,0.02,0.0);
        glVertex3d(-1.5,23,0);
        glColor3f(0.98,0.93,0.05);
        glVertex3d(1.5, 23,0);
        glColor3f(1.0,0.02,0.0);
        glVertex3d(1.5,-1,0);
        glEnd();

        // tower bottom
        glBegin(GL_POLYGON);
        glColor3f(1.0,0.08,0.0);
        glVertex3d(-1.75,0,0);
        glVertex3d(-1.75,0.5,0);
        glVertex3d(1.75, 0.5,0);
        glVertex3d(1.75,0,0);
        glEnd();
        // tower bottom
        glBegin(GL_POLYGON);
        glColor3f(1.0,0.08,0.0);
        glVertex3d(-1.75,-1,0);
        glVertex3d(-1.75,-0.5,0);
        glVertex3d(1.75, -0.5,0);
        glVertex3d(1.75,-1,0);
        glEnd();

        // tower over  triangle 1
        glBegin(GL_TRIANGLES);
        glColor3f(swingx+9.52,0.68,swingx+8.69);
        glVertex3d(-5,23,0);
        glVertex3d(-10,25,0);
        glVertex3d(-5,25,0);
        glEnd();

        // tower over   2
        glBegin(GL_POLYGON);
        glColor3f(0.84,0.1,0.0);
        glVertex3d(-5,23,0);
        glVertex3d(-5,25,0);
        glVertex3d(-4,25,0);
        glVertex3d(-1,23,0);
        glEnd();
        // tower over  triangle 3
        glBegin(GL_TRIANGLES);
        glColor3f(swingx+9.52,0.68,swingx+8.69);
        glVertex3d(-1,23,0);
        glVertex3d(-4,25,0);
        glVertex3d(-1,25,0);
        glEnd();

        // tower over  4
        glBegin(GL_POLYGON);
        glColor3f(0.84,0.1,0.0);
        glVertex3d(-1,23,0);
        glVertex3d(-1,25,0);
        glVertex3d(1,25,0);
        glVertex3d(1,23,0);
        glEnd();
        // tower over  triangle 5
        glBegin(GL_TRIANGLES);
        glColor3f(swingx+9.52,0.68,swingx+8.69);
        glVertex3d(1,23,0);
        glVertex3d(4,25,0);
        glVertex3d(1,25,0);
        glEnd();
        // tower over   6
        glBegin(GL_POLYGON);
        glColor3f(0.84,0.1,0.0);
        glVertex3d(5,23,0);
        glVertex3d(5,25,0);
        glVertex3d(4,25,0);
        glVertex3d(1,23,0);
        glEnd();
        // tower over  triangle 1
        glBegin(GL_TRIANGLES);
        glColor3f(swingx+9.52,0.68,swingx+8.69);
        glVertex3d(5,23,0);
        glVertex3d(10,25,0);
        glVertex3d(5,25,0);
        glEnd();


        // tower over part2  left 1
        glBegin(GL_POLYGON);
        glColor3f(0.98,0.93,0.05);
        glVertex3d(-10,25,0);
        glColor3f(1.0,0.02,0.0);
        glVertex3d(-12,30,0);
        glColor3f(0.98,0.93,0.05);
        glVertex3d(-7,30,0);
        glColor3f(1.0,0.02,0.0);
        glVertex3d(-5,25,0);
        glEnd();
        // tower over part2 r8 1
        glBegin(GL_POLYGON);
        glColor3f(0.98,0.93,0.05);
        glVertex3d(10,25,0);
        glColor3f(1.0,0.02,0.0);
        glVertex3d(12,30,0);
        glColor3f(0.98,0.93,0.05);
        glVertex3d(7,30,0);
        glColor3f(1.0,0.02,0.0);
        glVertex3d(5,25,0);
        glEnd();

        // tower over part2 l2
        glBegin(GL_POLYGON);
        glColor3f(0.98,0.93,0.05);
        glVertex3d(-5,25,0);
        glColor3f(1.0,0.02,0.0);
        glVertex3d(-7,30,0);
        glColor3f(0.98,0.93,0.05);
        glVertex3d(-2,30,0);
        glColor3f(1.0,0.02,0.0);
        glVertex3d(-1.5,25,0);
        glEnd();

        // tower over part2 R2
        glBegin(GL_POLYGON);
        glColor3f(0.98,0.93,0.05);
        glVertex3d(5,25,0);
        glColor3f(1.0,0.02,0.0);
        glVertex3d(7,30,0);
        glColor3f(0.98,0.93,0.05);
        glVertex3d(2,30,0);
        glColor3f(1.0,0.02,0.0);
        glVertex3d(1.5,25,0);
        glEnd();

        // tower over part2 middle
        glBegin(GL_POLYGON);
        glColor3f(0.98,0.93,0.05);
        glVertex3d(-1.5,25,0);
        glColor3f(1.0,0.02,0.0);
        glVertex3d(-2,30,0);
        glColor3f(0.98,0.93,0.05);
        glVertex3d(2,30,0);
        //glColor3f(1.0,0.02,0.0);
        glVertex3d(1.5,25,0);
        glEnd();


        glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(-2,23,0);
        glVertex3d(-5,10,0);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(-2,23,0);
        glVertex3d(-6,10,0);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(-5,10,0);
        glVertex3d(-6,10,0);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(-5,10.1,0);
        glVertex3d(-6,10.1,0);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(-5,10.2,0);
        glVertex3d(-6,10.2,0);
        glEnd();
         glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(-4.9,10.3,0);
        glVertex3d(-5.9,10.3,0);
        glEnd();
         glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(-4.8,10.6,0);
        glVertex3d(-5.9,10.6,0);
        glEnd();


         glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(2,23,0);
        glVertex3d(5,10,0);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(2,23,0);
        glVertex3d(6,10,0);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(5,10,0);
        glVertex3d(6,10,0);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(5,10.1,0);
        glVertex3d(6,10.1,0);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(5,10.2,0);
        glVertex3d(6,10.2,0);
        glEnd();
         glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(4.9,10.3,0);
        glVertex3d(5.9,10.3,0);
        glEnd();
         glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(4.8,10.6,0);
        glVertex3d(5.9,10.6,0);
        glEnd();


        glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(5,23,0);
        glVertex3d(9,10,0);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(5,23,0);
        glVertex3d(10,10,0);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(-5,23,0);
        glVertex3d(-9,10,0);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(-5,23,0);
        glVertex3d(-10,10,0);
        glEnd();
        //sit r8
        glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(9,10,0);
        glVertex3d(10,10,0);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(9,10.1,0);
        glVertex3d(10,10.1,0);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(9,10.2,0);
        glVertex3d(10,10.2,0);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(9,10.1,0);
        glVertex3d(10,10.1,0);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(9,10.2,0);
        glVertex3d(10,10.2,0);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(8.9,10.3,0);
        glVertex3d(9.9,10.3,0);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(8.8,10.8,0);
        glVertex3d(9.8,10.8,0);
        glEnd();

        //sit left
        glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(-9,10,0);
        glVertex3d(-10,10,0);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(-9,10.1,0);
        glVertex3d(-10,10.1,0);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(-9,10.2,0);
        glVertex3d(-10,10.2,0);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(-9,10.1,0);
        glVertex3d(-10,10.1,0);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(-9,10.2,0);
        glVertex3d(-10,10.2,0);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(-8.9,10.3,0);
        glVertex3d(-9.9,10.3,0);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0.15,0.0,0.46);
        glVertex3d(-8.8,10.8,0);
        glVertex3d(-9.8,10.8,0);
        glEnd();





}


void myDisplay()
{
    //circle
    glClear(GL_COLOR_BUFFER_BIT);

       //if(horse1y<=3)   //moving limit with the display measurement
       //{horse1y+=.005;} //changing the object position for redisplaying
       //else
       //{horse1y = -4;}
        if(c<60)
        {
            c+=0.009;
        }
        else
        {
            c = -100;
        }
        if(pl<100)
        {
            pl+=0.06;
        }
        else
        {
        pl= -100;
        }


        if(rain1<=-20)
            {rain1+=0.019;}
        else
            {rain1 = -27;}


        //horse 1
        if(horse1y<=hrs1)
       {horse1y+=.005;}
        else if (horse1y>=-6)
        {
            hrs1= -99;
            {horse1y-=.005;}

        }
        else
        {
            hrs1 = 3;
        }
        //horse 2

         if(horse2y<=hrs2)
       {horse2y+=.005;}
        else if (horse2y>=-5)
        {
            hrs2= -99;
            {horse2y-=.005;}

        }
        else
        {
            hrs2 = 3;
        }
        //horse 3
        if(horse3y<=hrs3)
       {horse3y+=.005;}
        else if (horse3y>=-5)
        {
            hrs3= -99;
            {horse3y-=.005;}
        }
        else
        {
            hrs3 = 3;
        }


        //swings
        if(swingx<=as)
            {swingx= swingx +0.005;}

        else if(swingx>=-8.59)
        {
            as = -111;
            {swingx= swingx -0.005;}

        }
        else
        {
            as =-5.4;
        }

        if ((c<-75 and c>-87) or (c<-28 and c>-45))
        {


            r = 0.37;
            g = 0.47;
            b = 0.62;
        }
        else
        {
             r = 0.15;
              g = 0.6;
               b = 0.81;
        }

        background();
        plane();
        underground();
        fountain2();
        //tower
        tower();

        if (trnxx >= -57)
        {
            glPushMatrix();
            glTranslatef(15,20,0);
            train3();
            glPopMatrix();
            trnxx -= 0.08;
        }
        else
        trnxx  = 50;

        //chorki
        chorki();
        horse_spinner();




        //swings
        swings();
        fountain();
        fountain2();







glutPostRedisplay();
    glFlush();
}


int main()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1080, 768);
    glutInitWindowPosition(60, 0);
    glutCreateWindow("Project Eclipse");
    init();
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(my_keyboard);
	glutSpecialFunc(spe_key);
	glutMouseFunc(my_mouse);
	sndPlaySound("sound.wav", SND_ASYNC);
	//PlaySound(TEXT("sound.wav"),NULL, SND_SYNC);
    glutMainLoop();
    return 0;
}
