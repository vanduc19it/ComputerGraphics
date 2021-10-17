#include <GL/glut.h>
#include <stdio.h>
#include<conio.h>
#include <math.h>
void Init(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	
}
void ReShape(int width, int height){
	glViewport(0,0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	glOrtho(-10.0, 10.0, -10.0, 10.0, 10.0, -10.0);
//	glClearColor(0.0f,0.0f,0.0f,1.0f); 
	glOrtho(-320,320,-240,240,-1,1); 
	

	
}
void parabol(int xc, int yc, float a)
{
    if (a==0)
       {
          	glBegin(GL_LINES);
          glVertex2d(0, yc); 
            glEnd();  
            return;
       }

    float x=0, y=0, d=0, sign=1;
    if (a < 0) {a = -a;sign = -1;}
    glBegin(GL_POINTS);
    while (x*a < 0.5)
    {
        glVertex2i(xc+x,yc-y*sign);
        glVertex2i(xc-x,yc-y*sign);
        d += a*(2*x +1);
        if (y + 0.5 < d) y++;
        x++;
    }
    while (y < yc)
    {
        glVertex2i(xc+x,yc-y*sign);
        glVertex2i(xc-x,yc-y*sign);
        y++;
        if (d + a*(x+0.5) < y)
           {
                d += a*(2*x+1);
                x++;
           }
    }
    glEnd();
}
 void RenderScene(){
 	parabol(100, 200, 0.01); 
 	glFlush();
 }
int main()
{
  	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB	);
 	glutInitWindowSize(500, 500);
 	glutInitWindowPosition(500, 150);
 	glutCreateWindow("Ve duong parabol");

 	Init(); 
 	glutReshapeFunc(ReShape);
 	glutDisplayFunc(RenderScene);
 	glutMainLoop();
 	
    return 0; 
} 
