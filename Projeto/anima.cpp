#include <iostream>

//OpenGL Includes
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <cmath>

GLfloat angulo = 0;


void start (){
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition (100, 100);
    glutCreateWindow("Anima");
    glClearColor (0.0, 0.0, 0.0, 0.0);


    glClearColor(0.0, 0.0, 0.0, 0.0);
 	glOrtho (0, 600, 0, 400, -0.5 ,0.5);
    
}

void anima (int i){
	
	if(angulo < 20){
		angulo = angulo + 5;
	}
	else{
		angulo = angulo - 5;
	}
	// reshape();
	glutPostRedisplay();

	glutTimerFunc(100,anima,1);
}


void display (){
	glClear(GL_COLOR_BUFFER_BIT);

	glTranslatef (angulo+5.0, 0.0, 0.0);
	glutSolidTeapot (5.0);

  glutSwapBuffers();
}


int  main(int argc, char  *argv[]){
    glutInit(&argc, argv);
    start();
    glutDisplayFunc(display);
	glutTimerFunc(100,anima,1);

	glutMainLoop();
	return 0;
}