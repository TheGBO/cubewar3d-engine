#include <windows.h>
#include "LuaInterface.h"

using namespace std;

int oldTimeSinceStart = 0;
int cameraX;
int cameraY = -20;
int cameraZ = -50;

bool pressedKeys[255];

int luaIsKeyDown(lua_State* L){
    char key = lua_tostring(L, 1)[0];
    bool result = false;
    if(pressedKeys[key] == true){
        result = true;
    } 
    else {
        result == false;
    }
    lua_pushboolean(L, result);
    return 1;
}

int luaSetCameraPosition(lua_State* L){
    float x = lua_tonumber(L, 1);
    float y = lua_tonumber(L, 2);
    float z = lua_tonumber(L, 3);

    cameraX = x;
    cameraY = y;
    cameraZ = z;
    

    return 0;
}
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
    lua_register(L, "rotate", luaRotate);
    lua_register(L, "solidCube", luaSolidCube);
    lua_register(L, "setCameraPosition", luaSetCameraPosition);
    lua_register(L, "isKeyDown", luaIsKeyDown);

    //add entities with "entities.push_back(entity)"
    if(CheckLua(L, luaL_dofile(L, "gameAssets/script.lua"))){
        cout << "Loaded Game Scripting succesfull at the first try!" << endl;
    }else{
        cout << "Loading Game Scripting failed!" << endl;
    }
    lua_getglobal(L, "Entities");
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
                glPushMatrix();
                CheckLua(L, lua_pcall(L, 0, 0, 0));
                glPopMatrix();
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
    glTranslatef(cameraX,cameraY,cameraZ);
    
    
    luaEntityCallback("Render");
    

    glutSwapBuffers();
}

//TODO: add keyboard input handler
void keyboardDown(unsigned char key, int x, int y){
    pressedKeys[key] = true;
}

void keyboardUp(unsigned char key, int x, int y){
    pressedKeys[key] = false;
}


//initializing the engine
void init(){
    run();
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70,1.3,0.1f,1000);
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