#ifndef MODELS_H_INC
#define MODELS_H_INC
#include <gl/GL.h>
#include <GL/freeglut.h>
#include <iostream>
#include <GL/glu.h>
#include <vector>
//simple quad
inline void drawQuad(float posX, float posY, float posZ, float scale){
    glBegin(GL_QUADS);
    glVertex3f(posX+scale, posY+scale, posZ);
    glVertex3f(posX-scale, posY+scale, posZ);
    glVertex3f(posX-scale, posY-scale, posZ);
    glVertex3f(posX+scale, posY-scale, posZ);
    glEnd();
}
#endif