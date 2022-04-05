//DEPRECATED CLASS, USE LUA SCRIPTING INSTEAD!
#ifndef GAME_ENTITY_H_INC
#define GAME_ENTITY_H_INC
#include <gl/GL.h>
#include <GL/freeglut.h>
#include <iostream>
#include <GL/glu.h>
#include <math.h>
#include <vector>
using namespace std;
class GameEntity
{
public:
//position vars
    float x = 0;
    float y = 0;
    float z = 0;
public:
//size vars
    float sX = 1;
    float sY = 1;
    float sZ = 1;
public:
//rotation vars
    float rotX = 0;
    float rotY = 0;
    float rotZ = 0;
    float rotAngle = 0;

public:
    GameEntity(float x, float y, float z){    
        this->x = x;
        this->y = y;
        this->z = z;
    }

    virtual void tick(){

    }

    virtual void model(){

    }

    virtual void keyboardDown(unsigned char key){

    }
    virtual void keyboardUp(unsigned char key){

    }

    void render(){
        glPushMatrix();
        glTranslatef(this->x,this->y,this->z);
        glRotatef(this->rotAngle, this->rotX, this->rotY, this->rotZ);
        model();
        glPopMatrix();
    }

    void offSet(float x, float y, float z){
        this->x += x;
        this->y += y;
        this->z += z;
    }

    void rotate(float a, float x, float y, float z){
        this->rotAngle = fmod(a, 360);
        this->rotX = x;
        this->rotY = y;
        this->rotZ = z;
    }

    virtual void getEntityList(vector<GameEntity*> list){
        
    }
};

#endif