#include <stdio.h> 
#include <math.h> 
#include <time.h> 
#include <GL/glut.h>
#define maxWD 640 
#define maxHT 480 
#define PI 3.141592654
  
// rotation speed 
#define thetaSpeed 0.05 
float a[100];
float b[100];
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
  }
  

void draw_circle(float x1,float y1,float r)
{

 
}

// this function will translate the point 
void translatePoint(float tx,float n) 
{ 
 glClear(GL_COLOR_BUFFER_BIT); 
  
        // update 
      

int i;
      glColor3f( 1, 1, 1 );
glBegin(GL_LINE_LOOP);
for(i=0;i<n;i++)
    {glVertex2f(a[i], b[i]);}
glEnd();
glColor3f( 0.5, 1, 0.5 );
glBegin(GL_LINE_LOOP);
for(i=0;i<n;i++)
    {	float xx = a[i]*cos(0.7)-b[i]*sin(0.7);
	float yy = b[i]*cos(0.7)+a[i]*sin(0.7);
	glVertex2f(xx, yy);}
glEnd();
  
//        drawPoint(px, py); // drawing the point 
  
        glFlush(); 
      
} 
  
// this function draws 
void scalePoint(int px, int py, int sx, int sy) 
{ 
   
} 
  
// Actual display function 
void myDisplay(void) 
{ 
    int opt; 
    printf("\nEnter\n\t<1> for Line"); 
    scanf("%d", &opt); 
    printf("\nGo to the window..."); 
float x1,y1,x2,y2,r;
int n;
    switch (opt) { 
    case 1: 
	
	printf("Enter sides count\n");
	scanf("%d",&n);
	printf("Enter %d sides\n",n);
	int i;
	for(i=0;i<n;i++){
		scanf("%f %f",&a[i],&b[i]);
	}
	float tx,ty;
	printf("Enter degree for rotation\n");
	scanf("%f",&tx);
	//printf("%f %f %f %f %f %f\n",x1,y1,x2,y2,tx,ty);
        translatePoint(tx,n); 
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
