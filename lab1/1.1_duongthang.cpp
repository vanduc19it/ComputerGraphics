#include <GL/glut.h>
void init(){ 
	glClearColor(0.0f,0.0f,0.0f,1.0f); 
	glOrtho(-320,320,-240,240,-1,1); 
}
void LineBres(int x1,int y1,int x2,int y2)	
{
	
   	int Dx = x2-x1; 
	int Dy = y2-y1;
   	int p = 2*Dy-Dx;
  	int x = x1;	
	int y = y1;
  	glBegin(GL_POINTS);
	glVertex2i(x,y);
	while (x < x2)  
	{
		if (p <0)	 
            p+= 2*Dy;
		else
            {
            	p+=2*(Dy-Dx);
			    y--;
			}
		x++;
        glVertex2i(x,y);
	}
	glEnd();
  	
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0); 
	
	
	glBegin(GL_LINES);
 	glVertex2f(-320, 0);
 	glVertex2f(320, 0);
 	glEnd();
 	
 	glBegin(GL_LINES);
 	glVertex2f(0, -240);
 	glVertex2f(0,240);
 	glEnd();

	glBegin(GL_LINES);
	LineBres(0, 0, 320, 150);
	glViewport(0,0,640,480);
	glEnd();
	glFlush(); 
}

int main(int argc, char** argv){
	int mode=GLUT_SINGLE | GLUT_RGB;
	glutInitDisplayMode(mode);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (0, 0); 
	glutCreateWindow("Ve toa do voi duong thang");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}

