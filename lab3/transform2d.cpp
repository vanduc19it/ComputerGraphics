#include <math.h>
#include<GL/Glut.h> 

void initGL()
{
	glClearColor(1.1f, 1.0f, 1.0f, 1.0f); 
	glOrtho(-2,2,-2,2,-1,1);	
}
float vertices[] = {1, 1,0, 1,0, 0,1, 0};
void draw(void)
{
	glBegin(GL_POLYGON);
	
		glVertex2f(vertices[2], vertices[3]);
		glVertex2f(vertices[4], vertices[5]);
		glVertex2f(vertices[6], vertices[7]);
		
	glEnd();
	glFlush();		
}
void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.1, 0.5, 1.0);
	draw();
}
//pheptinhtien 
void changeX(float heso_tinh_tien) 
{
	vertices[3] += heso_tinh_tien;
	vertices[5] += heso_tinh_tien;
	vertices[7] += heso_tinh_tien;
	draw();
}
void changeY(float heso_tinh_tien) 
{
	vertices[2] += heso_tinh_tien;
	vertices[4] += heso_tinh_tien;
	vertices[6] += heso_tinh_tien;
	draw();
}
//phepquay 
void rotate(float heso)
{

	vertices[2]= vertices[2] * cos(heso*(M_1_PI/180)) - vertices[3] * sin(heso*(M_1_PI/180));
	vertices[4]= vertices[4] * cos(heso*(M_1_PI/180)) - vertices[5] * sin(heso*(M_1_PI/180));
	vertices[6]= vertices[6] * cos(heso*(M_1_PI/180)) - vertices[7] * sin(heso*(M_1_PI/180));

	vertices[3]= vertices[2] * sin(heso*(M_1_PI/180))+ vertices[3] * cos(heso*(M_1_PI/180));
	vertices[5]= vertices[4] * sin(heso*(M_1_PI/180))+ vertices[5] * cos(heso*(M_1_PI/180));
	vertices[7]= vertices[6] * sin(heso*(M_1_PI/180))+ vertices[7] * cos(heso*(M_1_PI/180));

	draw();
}
//pheptile 
void scale(float heso_ti_le) 
{
	for(int i = 0 ; i < 8 ; i++)
	vertices[i] *= heso_ti_le;	
}
//dieukhienmuitendetinhtien 
void keyPressed(unsigned char key, int x, int y) {
	
	switch (key)
	{
	case 'T':       
	case 't':
		scale(1.2);
		break;

	case 'N':       
	case 'n':
		scale(0.8);
		break;

	case 'L':       
	case 'l':
		rotate(-5);
		break;

	case 'R':     
	case 'r':
		rotate(5);
		break;
	}
}
void keypressSpecial(int key, int x, int y)
{
	if (key == GLUT_KEY_UP) {changeX(0.1);}    
	if (key == GLUT_KEY_DOWN) {changeX(-0.1);} 
	if (key == GLUT_KEY_RIGHT) {changeY(0.1);} 
	if (key == GLUT_KEY_LEFT) {changeY(-0.1);}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);    
	glutInitWindowPosition(100, 50); 
	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glutCreateWindow("Lab3-Transform 2D"); 
    initGL();
	glutDisplayFunc(Display);
	glutIdleFunc(Display);
	glutSpecialFunc(keypressSpecial);
	glutKeyboardFunc(keyPressed);  
	glutMainLoop(); 
}


