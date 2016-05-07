//
//  main.cpp
//  Projeto
//
//  Created by Bruno Hirata on 4/22/16.
//  Copyright © 2016 Bruno Hirata. All rights reserved.
//

#include <iostream>

//OpenGL Includes
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>



// static int ombro = 0;
static int antebraco = 0;
static int elev_antebraco = 0;
static int mao = 0;
static int elev_mao = 0;
static int polegar = -30;
static int polegar1 = -30;
static int polegarF = -30;
static int polegarF1 = -30;
static int elev_polegar = 0;
static int elev_polegarF = 0;
static int indicador = 30;
static int elev_indicador = 0;
static int indicadorF1 = 30;
static int elev_indicadorF1 = 0;
static int indicadorF2 = 30;
static int elev_indicadorF2 = 0;
static int medio = 0;
static int elev_medio = 0;
static int anelar = 0;
static int elev_anelar = 0;
static int mendinho = 0;
static int elev_mendinho = 0;

int angle = 0;
int a = 0;

void start (){
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow("La Mano");
    glClearColor (0.0, 0.0, 0.0, 0.0);
    // glShapeModel (GL_FLAT);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    
}


void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    
    glPushMatrix();
        // Posiciona o antebraco
        glTranslatef (-5.0, 0.0, 0.0);
        glRotatef ((GLfloat) antebraco, 0.0, 0.0, 1.0);
        glRotatef ((GLfloat) elev_antebraco, 0.0, 1.0, 0.0);
        glTranslatef (5.0, 0.0, 0.0);
        glColor4f(1.0f,0.9f,0.1f,0.5f);
    
        // Desenha o antebraco
        glPushMatrix();
            glScalef (4.0, 2.0, 0.5);
            glutSolidCube (5.0);
        glPopMatrix();
    
        // Posiciona a mao
        glTranslatef (7.5, 0.0, 0.0);
        glRotatef ((GLfloat) mao, 0.0, 0.0, 1.0);
        glRotatef ((GLfloat) elev_mao, 0.0, 1.0, 0.0);
        glTranslatef (5.0, 0.0, 0.0);
    
        // Desenha a mao
        glPushMatrix();
            glScalef (2.0, 2.66, 0.5);
            glutSolidCube (5.0);
        glPopMatrix();
        
        // Posiciona a Primeira Falange do Polegar
        glTranslatef (4.0, 2.0, 0.0);
        glRotatef ((GLfloat) polegar, 0.0, 0.0, 5.0);
        glTranslatef (-0.0, -9.5, 0.0);
        
        /*
        glPushMatrix();
            glTranslatef (-5.0, 0.0, 0.0);
            glRotatef ((GLfloat) polegar, 0.0, 0.0, 5.0);
            // glTranslatef (5.0, 0.0, 0.0);
            glRotatef ((GLfloat) elev_polegar, 0.0, 5.0, 0.0);
            glTranslatef (5.0, 0.0, 0.0);
            // glRotatef ((GLfloat) elev_polegar, 0.0, 5.0, 0.0);
            // glRotatef (-30.0, 0.0, 0.0, 5.0);
            // glTranslatef (0.0, (GLfloat) elev_polegar, 0.0);
            // glPopMatrix();
        
            glPushMatrix();
                glScalef (1.0, 0.5, 0.5); // Desenha o polegar
                glutSolidCube (5.0);
            glPopMatrix();
        
        glPopMatrix();
        
        glTranslatef (11.0, 4.5, 0.0); //Posiciona o polegar
        glRotatef ((GLfloat) polegar, 0.0, 0.0, 5.0);
    
        glPushMatrix();
            //Posiciona para o proximo desenho
            glTranslatef (-7.0, -13.0, 0.0);
            glRotatef ((GLfloat) polegarF, 0.0, 0.0, -8.0);
            glRotatef ((GLfloat) elev_polegarF, 0.0, 5.0, 0.0);
            glTranslatef (5.0, 0.0, 0.0);
                glPushMatrix();
                    glScalef (1.0, 0.5, 0.5); // Desenha o polegar Falange de cima
                    glutSolidCube (5.0);
                glPopMatrix();
        glPopMatrix();
        
        glTranslatef (4.0, -1.0, 0.0);
        glRotatef ((GLfloat) indicador, 0.0, 0.0, 5.0);
        // glRotatef (30.0, 0.0, 0.0, 5.0);
        glTranslatef (7.0, 5.5, 0.0);
        
        glPushMatrix();
            glTranslatef (-5.0, 0.0, 0.0);
            glRotatef ((GLfloat) elev_indicador, 0.0, 5.0, 0.0);
            glTranslatef (5.0, 0.0, 0.0);
            glPushMatrix();
                glScalef (2.0, 0.4, 0.5); // Desnha o indicador
                glutSolidCube (5.0);
            glPopMatrix();
        glPopMatrix();
        
        glTranslatef (5.0, 0.0, 0.0);
        glRotatef ((GLfloat) medio, 0.0, 0.0, 5.0);
        // glRotatef (0.0, 0.0, 0.0, 5.0);
        glTranslatef (-5.0, 3.6, 0.0);
        
        glPushMatrix();
            glTranslatef (-5.0, 0.0, 0.0);
            glRotatef ((GLfloat) elev_medio, 0.0, 5.0, 0.0);
            glTranslatef (5.0, 0.0, 0.0);
            glPushMatrix();
                glScalef (2.0, 0.4, 0.5); // Desenha o medio
                glutSolidCube (5.0);
            glPopMatrix();
        glPopMatrix();
        
        glTranslatef (5.0, 0.0, 0.0);
        glRotatef ((GLfloat) anelar, 0.0, 0.0, 5.0);
        // glRotatef (0.0, 0.0, 0.0, 5.0);
        glTranslatef (-5.0, 3.7, 0.0);
        
        glPushMatrix();
            glTranslatef (-5.0, 0.0, 0.0);
            glRotatef ((GLfloat) elev_anelar, 0.0, 5.0, 0.0);
            glTranslatef (5.0, 0.0, 0.0);
            glPushMatrix();
                glScalef (2.0, 0.4, 0.5); // Desenha o anelar
                glutSolidCube (5.0);
            glPopMatrix();
        glPopMatrix();
        
        glTranslatef (5.0, 0.0, 0.0);
        glRotatef ((GLfloat) mendinho, 0.0, 0.0, 5.0);
        // glRotatef (0.0, 0.0, 0.0, 5.0);
        glTranslatef (-5.0, 4.0, 0.0);
        
        glPushMatrix();
            glTranslatef (-5.0, 0.0, 0.0);
            glRotatef ((GLfloat) elev_mendinho, 0.0, 5.0, 0.0);
            glTranslatef (5.0, 0.0, 0.0);
            glPushMatrix();
                glScalef (2.0, 0.4, 0.5); // Desenha o mendinho
                glutSolidCube (5.0);
            glPopMatrix();
        glPopMatrix();
    
         */
    glPopMatrix();
    
    glutSwapBuffers();
}

void DefineIluminacao(void)
{
    // estrutura de dados
    GLfloat luzAmbiente[4] = {0.5,0.5,0.5,1.0};
    GLfloat luzDifusa[4] = {0.7,0.7,0.7,1.0};
    GLfloat luzEspecular[4] = {1.0,1.0,1.0,1.0};
    GLfloat posicaoLuz[4] = {0.0,100.0,100.0,1.0};
    GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
    GLfloat especMaterial[] = {0,0,1,1};;
    // material
    glMaterialfv(GL_FRONT,GL_SPECULAR,especularidade);
    glMaterialfv(GL_FRONT,GL_SHININESS, especMaterial);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,luzAmbiente);
    // caracteristicas da luz
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);
}

void reshape (int w, int h){
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    // glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat) w/ (GLfloat) h, 1.0, 500.0);
    gluLookAt(80, 0, 20, 0, 0, 0, 0, 0, 1);
    // glMatrixMode(GL_MODELVIEW);
    // glLoadIdentity();
    // glTranslatef(0.0, 0.0, -5.0);
}

void keyboard (unsigned char key, int x, int y){
    switch (key){
        case 's': // Rotaciona antebraco no sentido anti-horario
            antebraco = (antebraco + 5) % 360;
            glutPostRedisplay();
            break;
        case 'S': // Rotaciona antebraco no sentido horario
            antebraco = (antebraco - 5) % 360;
            glutPostRedisplay();
            break;
        case 'e': // Rotaciona a mao no sentido anti-horario
            if ( mao <= 25 && mao >= -25) {
                // if ( mao <= -25) {
                mao = (mao + 5) % 360;
                printf("\nmao %d", mao);
                glutPostRedisplay();
            }
            break;
        case 'E': // Rotaciona a mao no sentido horario
            mao = (mao - 5) % 360;
            printf("\nmao %d", mao);
            glutPostRedisplay();
            break;
        case 'x': // Eleva antebraco
            elev_antebraco = (elev_antebraco + 5) % 360;
            if (elev_antebraco == 359) elev_antebraco = 0;
            printf("\nx %d", elev_antebraco);
            glutPostRedisplay();
            break;
        case 'X': // Declina antebraco
            elev_antebraco = (elev_antebraco - 5) % 360;
            if (elev_antebraco == 0) elev_antebraco = 359;
            printf("\nX %d", elev_antebraco);
            glutPostRedisplay();
            break;
        case 'd': // Eleva a mao
            elev_mao = (elev_mao + 5) % 360;
            if (elev_mao == 359) elev_mao = 0;
            printf("\nd %d", elev_mao);
            glutPostRedisplay();
            break;
        case 'D': //Deseleva a mao
            elev_mao = (elev_mao - 5) % 360;
            if (elev_mao == 0) elev_mao = 359;
            printf("\nD %d", elev_mao);
            glutPostRedisplay();
            break;
        case 'h': // Aproxima o polegar da mao
            polegar = (polegar + 5) % 360;
            if (polegar == 359) polegar = 0;
            printf("\nh %d", polegar);
            glutPostRedisplay();
            break;
        case 'H': // Afasta o polegar da mao
            polegar = (polegar - 5) % 360;
            if (polegar == 0) polegar = 359;
            printf("\nH %d", polegar);
            glutPostRedisplay();
            break;
        case 'n': // Aproxima o polegar do antebraco
            elev_polegar = (elev_polegar + 5) % 360;
            if (elev_polegar == 359) elev_polegar = 0;
            printf("\nn %d", elev_polegar);
            glutPostRedisplay();
            break;
        case 'N': // Afasta o polegar do antebraco ou o aproxima dos dedos
            elev_polegar = (elev_polegar - 5) % 360;
            if (elev_polegar == 0) elev_polegar = 359;
            printf("\nN %d", elev_polegar);
            glutPostRedisplay();
            break;
        case 'u': // Aproxima o indicador da face exterior da mao
            elev_indicador = (elev_indicador + 5) % 360;
            if (elev_indicador == 359) elev_indicador = 0;
            printf("\nu %d", elev_indicador);
            glutPostRedisplay();
            break;
        case 'U': // Aproxima o indicador da face interior da mao
            elev_indicador = (elev_indicador - 5) % 360;
            if (elev_indicador == 0) elev_indicador = 359;
            printf("\nU %d", elev_indicador);
            glutPostRedisplay();
            break;
        case 'i': // Aproxima o medio da face exterior da mao
            elev_medio = (elev_medio + 5) % 360;
            if (elev_medio == 359) elev_medio = 0;
            printf("\ni %d", elev_medio);
            glutPostRedisplay();
            break;
        case 'I': // Aproxima o medio da face interior da mao
            elev_medio = (elev_medio - 5) % 360;
            if (elev_medio == 0) elev_medio = 359;
            printf("\nI %d", elev_medio);
            glutPostRedisplay();
            break;
        case 'o': // Aproxima o anelar da face exterior da mao
            elev_anelar = (elev_anelar + 5) % 360;
            if (elev_anelar == 359) elev_anelar = 0;
            printf("\no %d", elev_anelar);
            glutPostRedisplay();
            break;
        case 'O': // Aproxima o anelar da face interior da mao
            elev_anelar = (elev_anelar - 5) % 360;
            if (elev_anelar == 0) elev_anelar = 359;
            printf("\nO %d", elev_anelar);
            glutPostRedisplay();
            break;
        case 'p': // Aproxima o mendinho da face exterior da mao
            elev_mendinho = (elev_mendinho + 5) % 360;
            if (elev_mendinho == 359) elev_mendinho = 0;
            printf("\np %d", elev_mendinho); 
            glutPostRedisplay();
            break;
        case 'P': // Aproxima o mendinho da face interior da mao
            elev_mendinho = (elev_mendinho - 5) % 360;
            if (elev_mendinho == 0) elev_mendinho = 359;
            printf("\nP %d", elev_mendinho);  
            glutPostRedisplay();
            break;
        case 27:
            exit(0);
            break;
        default:
            break;
    }
}


int main(int argc, char	*argv[])
{
    glutInit(&argc, argv);
    start();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}