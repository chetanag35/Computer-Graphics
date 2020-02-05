#include <stdio.h> 
#include <math.h> 
#include <time.h> 
#include <GL/glut.h>
#define maxWD 640 
#define maxHT 480 
  
// rotation speed 
#define thetaSpeed 0.05 
  
// this creates delay between two actions 
void delay(unsigned int mseconds) 
{ 
    clock_t goal = mseconds + clock(); 
    while (goal > clock()) 
        ; 
} 
  
// this is a basic init for the glut window 
void myInit(void) 
{ 
    glClearColor(0.0, 0.0, 0.0, 1.0); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluOrtho2D(0.0, maxWD, 0.0, maxHT); 
    glClear(GL_COLOR_BUFFER_BIT); 
    glFlush(); 
} 
  
// this function just draws a point 
void drawPoint(int x, int y) 
{ 
    glPointSize(7.0); 
    glColor3f(0.0f, 0.0f, 1.0f); 
    glBegin(GL_POINTS); 
    glVertex2i(x, y); 
    glEnd(); 
} 
  
void rotateAroundPt(int px, int py, int cx, int cy) 
{ 
    float theta = 0.0; 
    while (1) { 
        glClear(GL_COLOR_BUFFER_BIT); 
        int xf, yf; 
  
        // update theta anticlockwise rotation 
        theta = theta + thetaSpeed; 
  
        // check overflow 
        if (theta >= (2.0 * 3.14159)) 
            theta = theta - (2.0 * 3.14159); 
  
        // actual calculations.. 
        xf = cx + (int)((float)(px - cx) * cos(theta)) 
             - ((float)(py - cy) * sin(theta)); 
        yf = cy + (int)((float)(px - cx) * sin(theta)) 
             + ((float)(py - cy) * cos(theta)); 
  
        // drawing the centre point 
        drawPoint(cx, cy); 
  
        // drawing the rotating point 
        drawPoint(xf, yf); 
        glFlush(); 
        // creating a delay 
        // so that the point can be noticed 
        delay(10); 
    } 
} 
  

void draw_circle(float x1,float y1,float r)
{

  glBegin(GL_POINTS);
  float x=0, y=r;
  float p = 3-2*r;
  while(x<y) {
    x++;
    if(p<0)
      p = p + 4*x + 6;
    else {
      p = p + 4*(x-y) + 10;
      y--;
    }
	float X = x1,Y=y1;
   // glTranslate2f(x1,y1);
    glVertex2f(x + X, y + Y);
    glVertex2f(y + X, x + Y);
    glVertex2f(x + X, -y + Y);
    glVertex2f(y + X, -x + Y);
    glVertex2f(-x + X, -y + Y);
    glVertex2f(-y + X, -x + Y);
    glVertex2f(-x + X, y + Y);
    glVertex2d(-y + X, x + Y);
  }
  

}

// this function will translate the point 
void translatePoint(float x1, float y1,float tx,float ty,float r) 
{ 
   // int fx = x1, fy = y1; 
        glClear(GL_COLOR_BUFFER_BIT); 
  
        // update 


      glColor3f( 1, 1, 1 );
draw_circle(x1,y1,r);

	glEnd();  
draw_circle(x1+tx,y1+ty,r);

	glEnd(); 
//        drawPoint(px, py); // drawing the point 
  
        glFlush(); 
        // creating a delay 
        // so that the point can be noticed 
      
} 
  
// this function draws 
void scalePoint(int px, int py, int sx, int sy) 
{ 
    int fx, fy; 
    while (1) { 
        glClear(GL_COLOR_BUFFER_BIT); 
  
        // update 
        fx = px * sx; 
        fy = py * sy; 
  
        drawPoint(fx, fy); // drawing the point 
  
        glFlush(); 
        // creating a delay 
        // so that the point can be noticed 
        delay(500); 
  
        glClear(GL_COLOR_BUFFER_BIT); 
  
        // update 
        fx = px; 
        fy = py; 
  
        // drawing the point 
        drawPoint(fx, fy); 
        glFlush(); 
        // creating a delay 
        // so that the point can be noticed 
    //    delay(500); 
    } 
} 
  
// Actual display function 
void myDisplay(void) 
{ 
    int opt; 
    printf("\nEnter\n\t<1> for Line"); 
    scanf("%d", &opt); 
    printf("\nGo to the window..."); 
float x1,y1,x2,y2,r;
    switch (opt) { 
    case 1: 
	
	printf("Enter Center and radius\n");
	scanf("%f %f %f",&x1,&y1,&r);
	float tx,ty;
	printf("Enter translation x,y\n");
	scanf("%f %f",&tx,&ty);
	//printf("%f %f %f %f %f %f\n",x1,y1,x2,y2,tx,ty);
        translatePoint(x1, y1,tx,ty,r); 
        break; 
    case 2: 
        
        break; 
    case 3: 
       // scalePoint(10, 20, 2, 3); 
        break; 
    } 
} 
  
void main(int argc, char** argv) 
{ 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(maxWD, maxHT); 
    glutInitWindowPosition(100, 150); 
    glutCreateWindow("Transforming point"); 
    glutDisplayFunc(myDisplay); 
    myInit(); 
    glutMainLoop(); 
} 
