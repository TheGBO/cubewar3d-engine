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
    float x = 0;
    float y = 0;
    float z = 0;
    float s = 0;
public:
    float rotX = 0;
    float rotY = 0;
    float rotZ = 0;
    float rotAngle = 0;

public:
    GameEntity(float x, float y, float z, float s){    
        this->x = x;
        this->y = y;
        this->z = z;
        this->s = s;
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