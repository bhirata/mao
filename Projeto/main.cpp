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
static int elev_antebraco = 275;

static int mao = 0;
static int elev_mao = 0;

static int polegar = -30;
static int polegarF = -15;
static int elev_polegar = 0;

static int polegar1 = -30;
static int polegarF1 = 10;
static int elev_polegarF = 5;

static int indicador = 30;
static int elev_indicador = 0;

static int indicadorF1 = 30;
static int indicadorF11 = -28;
static int elev_indicadorF1 = 0;

static int indicadorF2 = 30;
static int indicadorF12 = -30;
static int elev_indicadorF2 = 0;

static int medio = 30;
static int medio1 = -30;
static int elev_medio = 0;

static int medioF = 30;
static int medio1F = 0;
static int elev_medioF = 0;

static int medioF1 = 30;
static int medio1F1 = 0;
static int elev_medioF1 = 0;

static int anelar = 30;
static int anelar1 = 0;
static int elev_anelar = 0;

static int anelarF = 0;
static int anelar1F = 0;
static int elev_anelarF = 0;

static int anelarF1 = 0;
static int anelar1F1 = 0;
static int elev_anelarF1 = 0;

static int mendinho = 30;
static int mendinho1 = 0;
static int elev_mendinho = 0;

static int mendinhoF = 0;
static int mendinho1F = 0;
static int elev_mendinhoF = 0;

static int mendinhoF1 = 0;
static int mendinho1F1 = 0;
static int elev_mendinhoF1 = 0;

int angle = 0;
int a = 0;

static int inverte_mao = 0;
static int inverte_mao1 = 0;

GLfloat angulo_mao = mao;
GLfloat angulo_elev_mao = angulo_elev_mao;



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

void display(void){
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
        glRotatef ((GLfloat) mao + angulo_mao, 0.0, 0.0, 1.0);
        glRotatef ((GLfloat) elev_mao + angulo_elev_mao, 0.0, 1.0, 0.0);
        glTranslatef (5.0, 0.0, 0.0);
    
        // Desenha a mao
        glPushMatrix();
            glScalef (2.0, 2.66, 0.5);
            glutSolidCube (5.0);

        glPopMatrix();
    
        // Posiciona a Primeira Falange do Polegar (Falange mais proxima da mao)
        glTranslatef (4.0, 2.0, 0.0);
        glRotatef ((GLfloat) polegar1, 0.0, 0.0, 5.0);
        glTranslatef (-0.0, -9.5, 0.0);
    
        glPushMatrix();
            glTranslatef (-5.0, 0.0, 0.0);
            glRotatef ((GLfloat) polegar, 0.0, 0.0, 5.0);
            glRotatef ((GLfloat) elev_polegar, 0.0, 5.0, 0.0);
            glTranslatef (5.0, 0.0, 0.0);
    
            // Desenha falange do polegar
            glPushMatrix();
                glScalef (1.5, 0.5, 0.5);
                glutSolidCube (5.0);
            glPopMatrix();
    
            //Posiciona a Segunda Falange do Polegar
            glTranslatef (4.5, 3.5, 0.0);
            glRotatef ((GLfloat) polegarF1, 0.0, 0.0, 5.0);
            glTranslatef (-0.0, -9.5, 0.0);
            
            glPushMatrix();
                glTranslatef (-4.5, 7.0, 0.0);
                glRotatef ((GLfloat) polegarF, 0.0, 0.0, 5.0);
                glRotatef ((GLfloat) elev_polegarF, 10.0, 5.0, 0.0);
                glTranslatef (5.0, 0.0, 0.0);
                
                // Desenha a falange do polegar
                glPushMatrix();
                    glScalef (1.5, 0.5, 0.5);
                    glutSolidCube (5.0);

                glPopMatrix();

            glPopMatrix();

        glPopMatrix();
    
        //Posiciona a primeira falange do indicador
        glPushMatrix();
            glTranslatef(7.0, 5.0, 0.0);
            glRotatef ((GLfloat) indicador, 0.0, 0.0, 5.0); //Rotacao inicial
    
            glPushMatrix();
                glTranslatef (-5.0, 0.0, 0.0);
                glRotatef ((GLfloat) elev_indicador, 0.0, 5.0, 0.0); //Rotacao
                glTranslatef (5.0, 0.0, 0.0);
    
                glPushMatrix();
                    glScalef (1.2, 0.4, 0.5); // Desenha o indicador
                    glutSolidCube (5.0);
                glPopMatrix();
    
                // Posiciona a segunda falange do indicador
                glTranslatef(-2.0, 0.0, 0.0);
                glRotatef((GLfloat) indicadorF11, 0.0, 0.0, 5.0);//Rotacao inicial
        
                glPushMatrix();
                    glTranslatef(4.5, 2.0, 0.0);
                    glRotatef((GLfloat) indicadorF1, 0.0, 0.0, 5.0);
                    glRotatef((GLfloat) elev_indicadorF1, 0.0, 5.0, 0.0);
                    glTranslatef(1.5, 0.5, 0.0);
        
                    glPushMatrix();
                        glScalef (0.8, 0.4, 0.5);
                        glutSolidCube (5.0); // Desenha indicador
                    glPopMatrix();
        
                    glTranslatef(2.0, 0.0, 0.0);
                    glRotatef((GLfloat) indicadorF12, 0.0, 0.0, 5.0);//Rotacao inicial
        
                    glPushMatrix();
                        glTranslatef(1.0, 0.4, 0.0);
                        glRotatef((GLfloat) indicadorF2, 0.0, 0.0, 5.0);
                        glRotatef((GLfloat) elev_indicadorF2, 0.0, 5.0, 0.0);
                        glTranslatef(-0.5, 0.0, 0.0);
        
                        glPushMatrix();
                            glScalef (0.6, 0.4, 0.5); // Desenha o indicador
                            glutSolidCube (5.0);
                        glPopMatrix();
        
                    glPopMatrix();
        
                glPopMatrix();
    
            glPopMatrix();
    
        glPopMatrix();

    
        //Posiciona a primeira falange do medio
        glPushMatrix();
            glTranslatef(5.1, 8.5, 0.0);
            glRotatef ((GLfloat) medio, 0.0, 0.0, 5.0); //Rotacao inicial
    
            glPushMatrix();
                glTranslatef (-5.0, 0.0, 0.0);
                glRotatef ((GLfloat) elev_medio, 0.0, 5.0, 0.0); //Rotacao
                glTranslatef (5.0, 0.0, 0.0);
    
                glPushMatrix();
                    glScalef (1.2, 0.4, 0.5); // Desenha o medio
                    glutSolidCube (5.0);
                glPopMatrix();
    
                // Posiciona a segunda falange do medio
                glTranslatef(-2.5, -2.4, 0.0);
                glRotatef((GLfloat) medio1F, 0.0, 0.0, 5.0);//Rotacao inicial
        
                glPushMatrix();
                    glTranslatef(4.5, 2.0, 0.0);
                    glRotatef((GLfloat) medio1F, 0.0, 0.0, 5.0);
                    glRotatef((GLfloat) elev_medioF, 0.0, 5.0, 0.0);
                    glTranslatef(1.5, 0.5, 0.0);
        
                    glPushMatrix();
                        glScalef (0.8, 0.4, 0.5);
                        glutSolidCube (5.0); // Desenha medio
                    glPopMatrix();
        
                    glTranslatef(2.0, 0.0, 0.0);
                    glRotatef((GLfloat) medio1F1, 0.0, 0.0, 5.0);//Rotacao inicial
        
                    glPushMatrix();
                        glTranslatef(0.8, -0.3, 0.0);
                        glRotatef((GLfloat) medio1F1, 0.0, 0.0, 5.0);
                        glRotatef((GLfloat) elev_medioF1, 0.0, 5.0, 0.0);
                        glTranslatef(0.7, 0.3, 0.0);
        
                        glPushMatrix();
                            glScalef (0.6, 0.4, 0.5); // Desenha o medio
                            glutSolidCube (5.0);
                        glPopMatrix();
        
                    glPopMatrix();
        
                glPopMatrix();
    
            glPopMatrix();
    
        glPopMatrix();


    
        //Posiciona a primeira falange do anelar
        glPushMatrix();
            glTranslatef(3.2, 12.0, 0.0);
            glRotatef ((GLfloat) anelar, 0.0, 0.0, 5.0); //Rotacao inicial
    
            glPushMatrix();
                glTranslatef (-5.0, 0.0, 0.0);
                glRotatef ((GLfloat) elev_anelar, 0.0, 5.0, 0.0); //Rotacao
                glTranslatef (5.0, 0.0, 0.0);
    
                glPushMatrix();
                    glScalef (1.2, 0.4, 0.5); // Desenha o anelar
                    glutSolidCube (5.0);
                glPopMatrix();
    
                // Posiciona a segunda falange do anelar
                glTranslatef(-2.5, -2.4, 0.0);
                glRotatef((GLfloat) anelar1F, 0.0, 0.0, 5.0);//Rotacao inicial
        
                glPushMatrix();
                    glTranslatef(4.5, 2.0, 0.0);
                    glRotatef((GLfloat) anelar1F, 0.0, 0.0, 5.0);
                    glRotatef((GLfloat) elev_anelarF, 0.0, 5.0, 0.0);
                    glTranslatef(1.5, 0.5, 0.0);
        
                    glPushMatrix();
                        glScalef (0.8, 0.4, 0.5);
                        glutSolidCube (5.0); // Desenha anelar
                    glPopMatrix();
        
                    glTranslatef(2.0, 0.0, 0.0);
                    glRotatef((GLfloat) anelar1F1, 0.0, 0.0, 5.0);//Rotacao inicial
        
                    glPushMatrix();
                        glTranslatef(0.8, -0.3, 0.0);
                        glRotatef((GLfloat) anelar1F1, 0.0, 0.0, 5.0);
                        glRotatef((GLfloat) elev_anelarF1, 0.0, 5.0, 0.0);
                        glTranslatef(0.7, 0.3, 0.0);
        
                        glPushMatrix();
                            glScalef (0.6, 0.4, 0.5); // Desenha o anelar
                            glutSolidCube (5.0);
                        glPopMatrix();
        
                    glPopMatrix();
        
                glPopMatrix();
    
            glPopMatrix();
    
        glPopMatrix();


    
        //Posiciona a primeira falange do mendinho
        glPushMatrix();
            glTranslatef(1.5, 15.0, 0.0);
            glRotatef ((GLfloat) mendinho, 0.0, 0.0, 5.0); //Rotacao inicial
    
            glPushMatrix();
                glTranslatef (-5.0, 0.0, 0.0);
                glRotatef ((GLfloat) elev_mendinho, 0.0, 5.0, 0.0); //Rotacao
                glTranslatef (5.0, 0.0, 0.0);
    
                glPushMatrix();
                    glScalef (1.2, 0.4, 0.5); // Desenha o mendinho
                    glutSolidCube (5.0);
                glPopMatrix();
    
                // Posiciona a segunda falange do mendinho
                glTranslatef(-2.5, -2.4, 0.0);
                glRotatef((GLfloat) mendinho1F, 0.0, 0.0, 5.0);//Rotacao inicial
        
                glPushMatrix();
                    glTranslatef(4.5, 2.0, 0.0);
                    glRotatef((GLfloat) mendinho1F, 0.0, 0.0, 5.0);
                    glRotatef((GLfloat) elev_mendinhoF, 0.0, 5.0, 0.0);
                    glTranslatef(1.5, 0.5, 0.0);
        
                    glPushMatrix();
                        glScalef (0.8, 0.4, 0.5);
                        glutSolidCube (5.0); // Desenha mendinho
                    glPopMatrix();
        
                    glTranslatef(2.0, 0.0, 0.0);
                    glRotatef((GLfloat) mendinho1F1, 0.0, 0.0, 5.0);//Rotacao inicial
        
                    glPushMatrix();
                        glTranslatef(0.8, -0.3, 0.0);
                        glRotatef((GLfloat) mendinho1F1, 0.0, 0.0, 5.0);
                        glRotatef((GLfloat) elev_mendinhoF1, 0.0, 5.0, 0.0);
                        glTranslatef(0.7, 0.3, 0.0);
        
                        glPushMatrix();
                            glScalef (0.6, 0.4, 0.5); // Desenha o mendinho
                            glutSolidCube (5.0);
                        glPopMatrix();
        
                    glPopMatrix();
        
                glPopMatrix();
    
            glPopMatrix();
    
        glPopMatrix();
    
    glPopMatrix();
    
    glutSwapBuffers();
}


void DefineIluminacao(void){
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
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat) w/ (GLfloat) h, 1.0, 500.0);
    gluLookAt(80, 0, 20, 0, 0, 0, 0, 0, 1);
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
            if (!inverte_mao){
                angulo_mao = angulo_mao + 5;
                if (angulo_mao >= 25){
                    inverte_mao = 1;
                }
            }
            else{
                angulo_mao = angulo_mao - 5;
                if (angulo_mao <= -25){
                    inverte_mao = 0;
                }
            }
            glutPostRedisplay();
            break;
        case 'E': // Rotaciona a mao no sentido horario
            if (!inverte_mao){
                angulo_mao = angulo_mao + 5;
                if (angulo_mao >= 25){
                    inverte_mao = 1;
                }
            }
            else{
                angulo_mao = angulo_mao - 5;
                if (angulo_mao <= -25){
                    inverte_mao = 0;
                }
            }
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
            if (!inverte_mao1){
                elev_mao = elev_mao - 5;
                if (elev_mao >= -80){
                    inverte_mao1 = 1;
                }
            }
            printf("\nd %d\n", elev_mao);
            glutPostRedisplay();
            break;
        case 'D': //Deseleva a mao
            if (inverte_mao1){
                elev_mao = elev_mao + 5;
                if (elev_mao  >= 80){
                    inverte_mao1 = 0;
                }
            }
            printf("\nD %d\n", elev_mao);
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
        case 'y': // Aproxima o polegar da mao
            polegarF = (polegarF + 5) % 360;
            if (polegarF == 359) polegarF = 0;
            printf("\ny %d", polegarF);
            glutPostRedisplay();
            break;
        case 'Y': // Afasta o polegar da mao
            polegarF = (polegarF - 5) % 360;
            if (polegarF == 0) polegarF = 359;
            printf("\nT %d", polegarF);
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
        case 'j': // Aproxima o indicador da face exterior da mao
            elev_indicador = (elev_indicador + 5) % 360;
            if (elev_indicador == 359) elev_indicador = 0;
            printf("\nj %d", elev_indicador);
            glutPostRedisplay();
            break;
        case 'J': // Aproxima o indicador da face interior da mao
            elev_indicador = (elev_indicador - 5) % 360;
            if (elev_indicador == 0) elev_indicador = 359;
            printf("\nJ %d", elev_indicador);
            glutPostRedisplay();
            break;
        case 'u': // Aproxima o indicador da face exterior da mao
            elev_indicadorF1 = (elev_indicadorF1 + 5) % 360;
            if (elev_indicadorF1 == 359) elev_indicadorF1 = 0;
            printf("\n7 %d", elev_indicadorF1);
            glutPostRedisplay();
            break;
        case 'U': // Aproxima o indicador da face interior da mao
            elev_indicadorF1 = (elev_indicadorF1 - 5) % 360;
            if (elev_indicadorF1 == 0) elev_indicadorF1 = 359;
            printf("\n& %d", elev_indicadorF1);
            glutPostRedisplay();
            break;
        case '7': // Aproxima o indicador da face exterior da mao
            elev_indicadorF2 = (elev_indicadorF2 + 5) % 360;
            if (elev_indicadorF2 == 359) elev_indicadorF2 = 0;
            printf("\n7 %d", elev_indicadorF2);
            glutPostRedisplay();
            break;
        case '&': // Aproxima o indicador da face interior da mao
            elev_indicadorF2 = (elev_indicadorF2 - 5) % 360;
            if (elev_indicadorF2 == 0) elev_indicadorF2 = 359;
            printf("\n& %d", elev_indicadorF2);
            glutPostRedisplay();
            break;
        case 'k': // Aproxima o medio da face exterior da mao
            elev_medio = (elev_medio + 5) % 360;
            if (elev_medio == 359) elev_medio = 0;
            printf("\nk %d", elev_medio);
            glutPostRedisplay();
            break;
        case 'K': // Aproxima o medio da face interior da mao
            elev_medio = (elev_medio - 5) % 360;
            if (elev_medio == 0) elev_medio = 359;
            printf("\nK %d", elev_medio);
            glutPostRedisplay();
            break;
        case 'i': // Aproxima o medio da face exterior da mao
            elev_medioF = (elev_medioF + 5) % 360;
            if (elev_medioF == 359) elev_medioF = 0;
            printf("\ni %d", elev_medioF);
            glutPostRedisplay();
            break;
        case 'I': // Aproxima o medio da face interior da mao
            elev_medioF = (elev_medioF - 5) % 360;
            if (elev_medioF == 0) elev_medioF = 359;
            printf("\nI %d", elev_medioF);
            glutPostRedisplay();
            break;
        case '8': // Aproxima o medio da face exterior da mao
            elev_medioF1 = (elev_medioF1 + 5) % 360;
            if (elev_medioF1 == 359) elev_medioF1 = 0;
            printf("\n8 %d", elev_medioF1);
            glutPostRedisplay();
            break;
        case '*': // Aproxima o medio da face interior da mao
            elev_medioF1 = (elev_medioF1 - 5) % 360;
            if (elev_medioF1 == 0) elev_medioF1 = 359;
            printf("\n* %d", elev_medioF1);
            glutPostRedisplay();
            break;
        case 'l': // Aproxima o anelar da face exterior da mao
            elev_anelar = (elev_anelar + 5) % 360;
            if (elev_anelar == 359) elev_anelar = 0;
            printf("\no %d", elev_anelar);
            glutPostRedisplay();
            break;
        case 'L': // Aproxima o anelar da face interior da mao
            elev_anelar = (elev_anelar - 5) % 360;
            if (elev_anelar == 0) elev_anelar = 359;
            printf("\nO %d", elev_anelar);
            glutPostRedisplay();
            break;
        case 'o': // Aproxima o anelar da face exterior da mao
            elev_anelarF = (elev_anelarF + 5) % 360;
            if (elev_anelarF == 359) elev_anelarF = 0;
            printf("\no %d", elev_anelarF);
            glutPostRedisplay();
            break;
        case 'O': // Aproxima o anelar da face interior da mao
            elev_anelarF = (elev_anelarF - 5) % 360;
            if (elev_anelarF == 0) elev_anelarF = 359;
            printf("\nO %d", elev_anelarF);
            glutPostRedisplay();
            break;
        case '9': // Aproxima o anelar da face exterior da mao
            elev_anelarF1 = (elev_anelarF1 + 5) % 360;
            if (elev_anelarF1 == 359) elev_anelarF1 = 0;
            printf("\n9 %d", elev_anelarF1);
            glutPostRedisplay();
            break;
        case '(': // Aproxima o anelar da face interior da mao
            elev_anelarF1 = (elev_anelarF1 - 5) % 360;
            if (elev_anelarF1 == 0) elev_anelarF1 = 359;
            printf("\n( %d", elev_anelarF1);
            glutPostRedisplay();
            break;
        case ';': // Aproxima o mendinho da face exterior da mao
            elev_mendinho = (elev_mendinho + 5) % 360;
            if (elev_mendinho == 359) elev_mendinho = 0;
            printf("\np %d", elev_mendinho); 
            glutPostRedisplay();
            break;
        case ':': // Aproxima o mendinho da face interior da mao
            elev_mendinho = (elev_mendinho - 5) % 360;
            if (elev_mendinho == 0) elev_mendinho = 359;
            printf("\nP %d", elev_mendinho);  
            glutPostRedisplay();
            break;
        case 'p': // Aproxima o mendinho da face exterior da mao
            elev_mendinhoF = (elev_mendinhoF + 5) % 360;
            if (elev_mendinhoF == 359) elev_mendinhoF = 0;
            printf("\np %d", elev_mendinhoF); 
            glutPostRedisplay();
            break;
        case 'P': // Aproxima o mendinho da face interior da mao
            elev_mendinhoF = (elev_mendinhoF - 5) % 360;
            if (elev_mendinhoF == 0) elev_mendinhoF = 359;
            printf("\nP %d", elev_mendinhoF);  
            glutPostRedisplay();
            break;
        case '0': // Aproxima o mendinho da face exterior da mao
            elev_mendinhoF1 = (elev_mendinhoF1 + 5) % 360;
            if (elev_mendinhoF1 == 359) elev_mendinhoF1 = 0;
            printf("\n0 %d", elev_mendinhoF1); 
            glutPostRedisplay();
            break;
        case ')': // Aproxima o mendinho da face interior da mao
            elev_mendinhoF1 = (elev_mendinhoF1 - 5) % 360;
            if (elev_mendinhoF1 == 0) elev_mendinhoF1 = 359;
            printf("\n) %d", elev_mendinhoF1);  
            glutPostRedisplay();
            break;
        case 27:
            exit(0);
            break;
        default:
            break;
    }
}


int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    start();
    glutDisplayFunc(display);

    // glutTimerFunc(100,anima_tchau,1);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}