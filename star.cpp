
#include <GL/glut.h>
#include<iostream>  

void draw_star(int x, int y){

glClear(GL_COLOR_BUFFER_BIT);

	glTranslatef(x, y, 0.0f);
	glBegin(GL_TRIANGLES);              
      glColor3f(1.0f, 0.0f, 0.0f); 
      glVertex2f(-0.15f, 0.0f);
      glVertex2f(0.0f,0.2f);
      glVertex2f(0.15f,0.0f);    
   glEnd();
	
glTranslatef(x, y, 0.0f);
	glBegin(GL_TRIANGLES);              
      //glColor3f(1.0f, 0.0f, 0.0f); 
      glVertex2f(-1.15f, 1.15f);
      glVertex2f(1.0f,-1.1f);
      glVertex2f(1.15f,1.15f);    
   glEnd();
	
	glutSwapBuffers();
	glFlush();
 
}


void mouse(int button,int state,int x,int y)
{

	
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
std::cout<<"Hello";

		if(state==GLUT_DOWN)
			draw_star(x,y);
		glutPostRedisplay();
		break;
	case GLUT_MIDDLE_BUTTON:
			if(state==GLUT_DOWN)
			draw_star(x,y);
		break;
	case GLUT_RIGHT_BUTTON:
		if(state==GLUT_DOWN)
		draw_star(x,y);
		break;
	default:
		break;
	}
}
void keyboard(unsigned char key, int x, int y)
{
	/*//-------- spin --------
	if(key=='x')
	{
		setSpin(1.0,0.0,0.0);
		glutPostRedisplay();
	}
	else if(key=='y')
	{
		setSpin(0.0,1.0,0.0);
		glutPostRedisplay();
	}
	else if(key=='z')
	{
		setSpin(0.0,0.0,1.0);
		glutPostRedisplay();
	}
	else if(key=='a')
	{
		setSpin(1.0,1.0,1.0);
		glutPostRedisplay();
	}
	//-------- spin --------
	//-------- zoom --------
	else if(key=='i')
	{
		translate_z++;
		glutPostRedisplay();
	}
	else if(key=='o')
	{
		translate_z--;
		glutPostRedisplay();
	}
	//-------- zoom --------
	//-------- reset -------
	else if(key=='r')
	{glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 400, 0, 400);
		reset();
		glutPostRedisplay();
	}
	//-------- reset -------*/
}
 
void myDisplay() {
   
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	//******************************************//


	//------- custom code ends -------
	//******************************************// 
	glutSwapBuffers();

}

void reshape(int w,int h)
{
	glViewport(0,0, (GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(100.0f, (GLfloat)w/(GLfloat)h, 1.0f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void init()
{
	glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-320, 319,-240, 239);
glClear(GL_COLOR_BUFFER_BIT);
glFlush();
}
 

int main(int argc, char** argv) {
   glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1024, 768);
	glutCreateWindow("Keyboard and Mouse Interaction");
        
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	init();
	glutMainLoop();        
   return 0;
}
