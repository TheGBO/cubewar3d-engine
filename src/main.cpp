#include "GameEntity.h"
#include <windows.h>

#include "game/Player.h"
#include "game/Ground.h"

using namespace std;

vector<GameEntity*> entities;
int oldTimeSinceStart = 0;
float cameraAngle = 0;
//This section instatiate the Game Entities
Player *player = new Player(-10,0,0,5);
Ground *ground = new Ground(0,-2.5,0,10);
//adding the entities to the Vector, so they can be renderer and updated
void run(){
    entities.push_back(ground);
    entities.push_back(player);
}

//this function updates the entities
void logic(){
    int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
    int deltaTime = timeSinceStart - oldTimeSinceStart;
    oldTimeSinceStart = timeSinceStart;
    for(GameEntity *e : entities){
       e->tick();
       e->getEntityList(entities);
    }
    cameraAngle += 0.005f;
    glutPostRedisplay();
}

//rendering entities
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(180,0,1,0);
    glTranslatef(cameraAngle/2,-13,50);
    for (GameEntity *e : entities)
    {
        e->render();
    }
    
    glutSwapBuffers();
}

//TODO: add keyboard input handler
void keyboardDown(unsigned char key, int x, int y){
    for (GameEntity *e : entities)
    {
        e->keyboardDown(key);
    }
}

void keyboardUp(unsigned char key, int x, int y){
    for (GameEntity *e : entities)
    {
        e->keyboardUp(key);
    }
}

//initializing the engine
void init(){
    run();
    //3d mode
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70,(double)(800/600),0.1f,1000);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    // Lighting set up
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Set lighting intensity and color
	GLfloat qaAmbientLight[]	= {0.2, 0.2, 0.2, 1.0};
    glEnable(GL_COLOR_MATERIAL);
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);


	// Set the light position
	GLfloat qaLightPosition[]	= {.5, .5, 0.0, 1.0};
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
    //skybox color
    glClearColor(0.4f,0.4f,0.7f,1);
}

int main(int argc, char **argv){
    //initialize graphics library
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(800,600);
    glutCreateWindow("Game");
    glutKeyboardFunc(keyboardDown);
    glutKeyboardUpFunc(keyboardUp);
    glutDisplayFunc(display);
    glutIdleFunc(logic);
    init();
    glutMainLoop();
    return 0;
}