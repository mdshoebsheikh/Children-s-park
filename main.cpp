#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>



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
        //cloud();



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

        underground();



        if (trnxx >= -57)
        {
            glPushMatrix();
            glTranslatef(15,20,0);

            glPopMatrix();
            trnxx -= 0.08;
        }
        else
        trnxx  = 50;

        //chorki













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
    glutMainLoop();
    return 0;
}
