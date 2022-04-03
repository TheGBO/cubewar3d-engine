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
    float r = 0;
    float g = 0;
    float b = 0;
public:
    GameEntity(float x, float y, float z, float s){
        this->x = x;
        this->y = y;
        this->z = z;
        this->s = s;
    }

    virtual void tick(){

    }

    void setColor(float r, float g, float b){
        this->r = r;
        this->g = g;
        this->b = b;
        cout << "DEBUG::COLOR HAS BEEN SET " << r << ", " << g << ", " << b << endl;
    }

    void render(){
        glPushMatrix();
        glColor3f(this->r,this->g,this->b);
        glTranslatef(this->x,this->y,this->z);
        glutSolidCube(this->s);
        glutSolidTeapot(5);
        glPopMatrix();
    }

    void offSet(float x, float y, float z){
        this->x += x;
        this->y += y;
        this->z += z;
    }
};

#endif