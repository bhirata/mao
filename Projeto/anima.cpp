#include <iostream>

//OpenGL Includes
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

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


// void reshape (int w, int h){
//     glViewport (0, 0, (GLsizei) w, (GLsizei) h);
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     gluPerspective(60.0, (GLfloat) w/ (GLfloat) h, 1.0, 500.0);
//     gluLookAt(80, 0, 20, 0, 0, 0, 0, 0, 1);
// }



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
	// glClear(GL_COLOR_BUFFER_BIT);
	// glColor3f(1.0, 1.0, 1.0);
	// glRotatef ((GLfloat) angulo, 0.0, 0.0, 5.0);
	// glPushMatrix();
	// glScalef (4.0, 2.0, 0.5);
 //    glutSolidCube (5.0);
 //    glPopMatrix();
 //    glutSwapBuffers();
	glClear(GL_COLOR_BUFFER_BIT);

	glTranslatef (angulo+5.0, 0.0, 0.0);
	glutSolidTeapot (5.0);

 // glPolygonMode(GL_BACK, GL_LINE);
  // glColor3f(1.0, 1.0, 1.0);
  // glLineWidth(15.0);
  // glBegin(GL_LINE_LOOP);
  // glVertex2i(2,2);  glVertex2i(599,2);
  // glVertex2i(599,399); glVertex2i(2,399);
  // glEnd();

  // glBegin(GL_LINES);
  // glVertex2i(100,190);  glVertex2i(100,240);
  // glVertex2i(500,190);  glVertex2i(500,240);
  // glEnd();

  // glPointSize(15.0);
  // glBegin(GL_POINTS);
  // glVertex2i(angulo+200,210);
  // glEnd();

//  glFlush();
  glutSwapBuffers();
}


int  main(int argc, char  *argv[]){
    glutInit(&argc, argv);
    start();
    glutDisplayFunc(display);
	glutTimerFunc(100,anima,1);
    // glutReshapeFunc(reshape);
    // glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}