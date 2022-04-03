#include "GameEntity.h"
#include <windows.h>

using namespace std;

vector<GameEntity*> entities;
int oldTimeSinceStart = 0;

//This section instatiate the Game Entities
GameEntity *e = new GameEntity(1,1,1,0.4);
//adding the entities to the Vector, so they can be renderer and updated
void run(){
    entities.push_back(e);
}

//this function updates the entities
void logic(){
    int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
    int deltaTime = timeSinceStart - oldTimeSinceStart;
    oldTimeSinceStart = timeSinceStart;
    for(GameEntity *e : entities){
        e->tick();
    }
    glutPostRedisplay();
}

//rendering entities
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0,0,-50);
    for (GameEntity *e : entities)
    {
        e->render();
    }
    
    glutSwapBuffers();
}

//TODO: add keyboard input handler
void keyboard(unsigned char key, int x, int y){
    
}

//initializing the engine
void init(){
    run();
    //3d mode
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(35,1,0.1f,1000);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    //skybox color
    glClearColor(0.4f,0.4f,0.7f,1);
}

int main(int argc, char **argv){
    //initialize graphics library
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(800,600);
    glutCreateWindow("Game");
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutIdleFunc(logic);
    init();
    glutMainLoop();
    return 0;
}