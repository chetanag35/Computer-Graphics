
#include <GL/glut.h>
#include<stdio.h>
#include <unistd.h>
//#include<iostream.h>
#define maxWD 640 
#define maxHT 480 

int X1 =100, Y1=50;
void draw_circle();
void display();
float s=5;
int k=0;
char spin = 0;
void keyboard( unsigned char key, int x, int y )
{
    if( key =='A' )
    {
	k++;
        int x=X1+50, y=Y1+50, flag=1, mode=1,r=50;

  if (k%4==0) {
    X1+=50;
    Y1+=50;
  }
  else if(k%4==1) {
    X1-=50;
Y1+=50;
  }
  else if(k%4==2)
      {X1-=50;
	Y1-=50;}
  else if(k%4==3)
  {  Y1-=50;
X1+=50;}
  glClear(GL_COLOR_BUFFER_BIT);
  draw_circle();

  glEnd();
  glFlush();

}
if( key =='B' )
    {
        s*=2;
    }
if( key =='C' )
    {
        s*=2;
    }
if( key =='D' )
    {
        s*=2;
    }
if( key =='E' )
    {
        s*=2;
    }
if( key =='F' )
    {
	int g = 0;
        while(g<1000){
		glTranslatef(100.0f,10.0f,0.0f);
		display();
usleep(4000);
	g++;
	}
    }
if(key=='R')
{

draw_circle();

}
if( key =='X' )
    {
        exit(0);
    }

}
void draw(int x,int y)
{
//glClearColor (0.0, 0.0, 0.0, 0.0);
 //glClear (GL_COLOR_BUFFER_BIT);
    glColor3f( 1, 1, 1 );
glBegin(GL_TRIANGLES);
glVertex3f(x+s*(0),y+s*(0.57),0);
glVertex3f(x+s*(-0.5),y+s*(-0.285),0);
glVertex3f(x+s*(0.5),y+s*(-0.285),0);
glEnd();
glBegin(GL_TRIANGLES);
glVertex3f(x+s*(0),y+s*(-0.57),0);
glVertex3f(x+s*(-0.5),y+s*(0.285),0);
glVertex3f(x+s*(0.5),y+s*(0.285),0);
glEnd();
glFlush();
 
}
float angle = 0;
void timer( int value )
{
    if( spin==1 )
    {
        angle += 3;
    }



    glutTimerFunc( 16, timer, 0 );
    glutPostRedisplay();
}
void mouse(int button,int state,int x,int y)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:

			exit(0);
		break;
	
	case GLUT_RIGHT_BUTTON:
			draw(x,y);
printf("%d %d\n",x,y);
		break;
	default:
		break;
	}
}

void draw_circle()
{

glClear (GL_COLOR_BUFFER_BIT);
  glBegin(GL_POINTS);
  int X =100, Y=100;
  int x=0, y=100;
  int p = 3-2*y;
  while(x<y) {
    x++;
    if(p<0)
      p = p + 4*x + 6;
    else {
      p = p + 4*(x-y) + 10;
      y--;
    }
    
    glVertex2d(x + X, y + Y);
    glVertex2d(y + X, x + Y);
    glVertex2d(x + X, -y + Y);
    glVertex2d(y + X, -x + Y);
    glVertex2d(-x + X, -y + Y);
    glVertex2d(-y + X, -x + Y);
    glVertex2d(-x + X, y + Y);
    glVertex2d(-y + X, x + Y);
  }
glEnd();
  
glBegin(GL_POINTS);
  
   x=0, y=50;
   p = 3-2*y;
  while(x<y) {
    x++;
    if(p<0)
      p = p + 4*x + 6;
    else {
      p = p + 4*(x-y) + 10;
      y--;
    }
    
    glVertex2d(x + X1, y + Y1);
    glVertex2d(y + X1, x + Y1);
    glVertex2d(x + X1, -y + Y1);
    glVertex2d(y + X1, -x + Y1);
    glVertex2d(-x + X1, -y + Y1);
    glVertex2d(-y + X1, -x + Y1);
    glVertex2d(-x + X1, y + Y1);
    glVertex2d(-y + X1, x + Y1);
  }

glClear (GL_COLOR_BUFFER_BIT);
  glBegin(GL_POINTS);
  X =-100, Y=100;
  x=0, y=100;
  p = 3-2*y;
  while(x<y) {
    x++;
    if(p<0)
      p = p + 4*x + 6;
    else {
      p = p + 4*(x-y) + 10;
      y--;
    }
    
    glVertex2d(x + X, y + Y);
    glVertex2d(y + X, x + Y);
    glVertex2d(x + X, -y + Y);
    glVertex2d(y + X, -x + Y);
    glVertex2d(-x + X, -y + Y);
    glVertex2d(-y + X, -x + Y);
    glVertex2d(-x + X, y + Y);
    glVertex2d(-y + X, x + Y);
  }
  
glBegin(GL_POINTS);
  X =-100, Y=50;
   x=0, y=50;
   p = 3-2*y;
  while(x<y) {
    x++;
    if(p<0)
      p = p + 4*x + 6;
    else {
      p = p + 4*(x-y) + 10;
      y--;
    }
    
    glVertex2d(x + X, y + Y);
    glVertex2d(y + X, x + Y);
    glVertex2d(x + X, -y + Y);
    glVertex2d(y + X, -x + Y);
    glVertex2d(-x + X, -y + Y);
    glVertex2d(-y + X, -x + Y);
    glVertex2d(-x + X, y + Y);
    glVertex2d(-y + X, x + Y);
  }

glBegin(GL_POINTS);
  X =0, Y=-120;
   x=0, y=350;
   p = 3-2*y;
  while(x<y) {
    x++;
    if(p<0)
      p = p + 4*x + 6;
    else {
      p = p + 4*(x-y) + 10;
      y--;
    }
    
    glVertex2d(x + X, y + Y);
    glVertex2d(y + X, x + Y);
    glVertex2d(x + X, -y + Y);
    glVertex2d(y + X, -x + Y);
    glVertex2d(-x + X, -y + Y);
    glVertex2d(-y + X, -x + Y);
    glVertex2d(-x + X, y + Y);
    glVertex2d(-y + X, x + Y);
  }

glBegin(GL_POINTS);
  X =0, Y=-100;
   x=0, y=50;
   p = 3-2*y;
  while(x<y) {
    x++;
    if(p<0)
      p = p + 4*x + 6;
    else {
      p = p + 4*(x-y) + 10;
      y--;
    }
    
    glVertex2d(x + X, y + Y);
    glVertex2d(y + X, x + Y);
    glVertex2d(x + X, -y + Y);
    glVertex2d(y + X, -x + Y);
    glVertex2d(-x + X, -y + Y);
    glVertex2d(-y + X, -x + Y);
    glVertex2d(-x + X, y + Y);
    glVertex2d(-y + X, x + Y);
  }

glBegin(GL_POINTS);
  X =0, Y=-150;
   x=0, y=150;
   p = 3-2*y;
  while(x<y) {
    x++;
    if(p<0)
      p = p + 4*x + 6;
    else {
      p = p + 4*(x-y) + 10;
      y--;
    }
    
    glVertex2d(x + X, -y + Y);
    glVertex2d(y + X, -x + Y);
    glVertex2d(-x + X, -y + Y);
    glVertex2d(-y + X, -x + Y);
   // glVertex2d(-x + X, y + Y);
   // glVertex2d(-y + X, x + Y);
  }

}


void display()

{
//draw(100,100);
 //glClear (GL_COLOR_BUFFER_BIT);
//glClearColor (0.0, 0.0, 0.0, 0.0);

draw_circle();


 glutSwapBuffers();
}
 void init(void)
 {
 glClearColor (0.0, 0.0, 0.0, 0.0);
 glOrtho(-1000.0, 1000.0, -1000.0, 1000.0, -1.0, 1.0);
 }
int main( int argc, char **argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE );
    glutInitWindowSize( 640, 480 );
glutInitWindowPosition (1000, 1000);
    glutCreateWindow( "GLUT" );
init();
    glutDisplayFunc( display );
    glutKeyboardFunc( keyboard );	
    glutMouseFunc(mouse);
glutIdleFunc(display);
   // glutTimerFunc( 0, timer, 0 );
    glutMainLoop();
    return 0;
}

