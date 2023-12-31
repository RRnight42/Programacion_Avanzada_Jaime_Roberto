#include <iostream>
#include <GL/glut.h>
#include <string>
#include "Game.h"

using namespace std;

// constantes susceptibles de cambio

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int WINDOW_POSITION_X = 300;
const int WINDOW_POSITION_Y = 400;
const char TITLE[] = "Parte 1";
const GLclampf RED = 0.5;
const GLclampf GREEN = 0.5;
const GLclampf BLUE = 0.5;
const GLclampf ALPHA = 1.0;
bool fullscreenMode = false;

Game game;

void writeLine(string text) {

    cout << text << endl;
}

void InitGraphics() {

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glClearColor(RED, GREEN, BLUE, ALPHA);
    game.Init();
}


void Display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    game.Render();
    glutSwapBuffers(); // ponerlo antes del swapbuffers


}

void reshape(GLsizei width, GLsizei height) {

    if (height == 0) height = 1;
    GLfloat aspectRatio = (GLfloat)width / (GLfloat)height;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.f, aspectRatio, 1.0f, 200.0f);
    glMatrixMode(GL_MODELVIEW);
}

void idle() {

    game.Update();
    glutPostRedisplay();


}

void keyPressed(unsigned char key, int px, int py) {

    game.ProcessKeyPressed(key, px, py);
    glutPostRedisplay();


}

void mouseMoved(int x, int y)
{

    game.ProcessMouseMovement(x, y);
    glutPostRedisplay();


}

void SpecialKey(int key, int x, int y) {

    switch (key) {

    case GLUT_KEY_F11:
        fullscreenMode = !fullscreenMode;

        if (fullscreenMode) {


            glutFullScreen();

        }
        else {


            glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
            glutPositionWindow(WINDOW_POSITION_X, WINDOW_POSITION_Y);

        }
        break;




    }


}

void mouseClicked(int button, int state, int x, int y) {

    game.ProcessMouseClick(button, state, x, y);
    glutPostRedisplay();

}
int main(int argc, char** argv)
{
/*
    Vector3D v;

    try {
        v[5] = 9;
    }
    catch (out_of_range& e) {
        cout << e.what() << endl;
    }
  */


    writeLine("Open gl hello world");
    writeLine("Creating window ...");



    glutInit(&argc, argv);
    // inicializar glut
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    // tamaño inicial de la ventana
    glutInitWindowSize(800, 600);
    // posicion inicial de la ventana
    glutInitWindowPosition(100, 100);
    //titulo de la ventana
    glutCreateWindow(TITLE);


    glutReshapeFunc(reshape);
    glutMotionFunc(mouseMoved);
    glutKeyboardFunc(keyPressed);
    glutMouseFunc(mouseClicked);
    glutDisplayFunc(Display);
    glutSpecialFunc(SpecialKey);
    glutIdleFunc(idle);
    InitGraphics();


    writeLine("loop ...");
    glutMainLoop();

}