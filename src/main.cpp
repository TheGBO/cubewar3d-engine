#include <windows.h>
#include "LuaInterface.h"

using namespace std;

int oldTimeSinceStart = 0;

//initialize lua VM
lua_State *L = luaL_newstate();
//This section instatiate the Game Entities
//adding the entities to the Vector, so they can be renderer and updated
void run(){
    luaL_openlibs(L);
    //use this section to define runtime enviroment functions
    lua_register(L, "drawQuad", luaDrawQuad);
    lua_register(L, "setDrawColor", luaSetDrawColor);
    lua_register(L, "translate", luaTranslate);
    lua_register(L, "solidCube", luaSolidCube);

    //add entities with "entities.push_back(entity)"
    if(CheckLua(L, luaL_dofile(L, "game/script.lua"))){
        lua_getglobal(L, "Entities");
    }
    //lua_close(L);
}

void luaEntityCallback(string name){
    lua_getglobal(L, "Entities");
    int entLen = lua_rawlen(L, -1);
    for (int i = 0; i < entLen+1; i++)
    {
        if(!lua_isnil(L, -1)){
            lua_pushnumber(L, i);
            lua_gettable(L, -2);
            lua_getfield(L, -1, name.c_str());
            if(lua_isfunction(L, -1)){
                CheckLua(L, lua_pcall(L, 0, 0, 0));
            }
        }
        lua_pop(L, 1);
    }
}

//this function updates the entities
void logic(){
    int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
    int deltaTime = timeSinceStart - oldTimeSinceStart;
    oldTimeSinceStart = timeSinceStart;

    luaEntityCallback("Tick");

    glutPostRedisplay();
}

int frame=0,time,timebase=0;
//rendering entities
void display(){
    frame++;
	time=glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {
		//cout << "FPS:" << frame*1000.0/(time-timebase) << endl;
		timebase = time;
		frame = 0;
	}
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0,-13,-50);
    //renderCallback

    glPushMatrix();
    luaEntityCallback("Render");
    glPopMatrix();

    glutSwapBuffers();
}

//TODO: add keyboard input handler
void keyboardDown(unsigned char key, int x, int y){
    
}

void keyboardUp(unsigned char key, int x, int y){
    
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