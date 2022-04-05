#include "../GameEntity.h"
#include "../Models.h"

class Ground : public GameEntity{
public:
    Ground(float x, float y, float z, float s):GameEntity(x,y,z,s){

    }
    void model(){
        rotate(90,1,0,0);
        glColor3f(0,0.5,0);
        //drawQuad(this->x,this->y,this->z,this->s);
        glutSolidCube(this->s*1.4);
    }
};