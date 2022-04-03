#ifndef GAME_ENTITY_H_INC
#define GAME_ENTITY_H_INC
#include <gl/GL.h>
#include <GL/freeglut.h>
#include <iostream>
#include <GL/glu.h>
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
    GameEntity(float x, float y, float z, float s){
        this->x = x;
        this->y = y;
        this->z = z;
        this->s = s;
    }

    virtual void tick();

    void render(){
        glPushMatrix();
        glColor3f(1,1,1);
        glTranslatef(this->x,this->y,this->z);
        glutSolidCube(this->s);
        glPopMatrix();
    }

    void offSet(float x, float y, float z){
        this->x += x;
        this->y += y;
        this->z += z;
    }
};

#endif