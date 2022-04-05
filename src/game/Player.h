#include "../GameEntity.h"
#include "../Models.h"
 
class Player : public GameEntity{
public:
    bool left;
    bool right;
    bool forward;
    bool backward;

    float speed = 0.01;
    bool isColliding;

    float lastPosX;
    float lastPosY;
    float lastPosZ;

    Player(float x, float y, float z, float s):GameEntity(x,y,z,s){

    }
    void model(){
        glColor3f(1,.5,0);
        glutSolidCube(this->s-1);
        glColor3f(0,0,0);
        drawQuad(-1,0,-2.5,0.5);
        drawQuad(1,0,-2.5,0.5);
    }
    void tick(){
        //movement
        float lastPosX = x;
        float lastPosY = y;
        float lastPosZ = z;
        
        if(forward){
            if(isColliding){
                forward = false;
                z+=speed*4;
            }
            z-=speed;
            
        }
        else if(backward){
            if(isColliding){
                backward = false;
                z-=speed*4;
            }
            z+=speed;
        }
        if(left){
            if(isColliding){
                left = false;
                x+=speed*4;
            }
            x-=speed;
        }
        else if(right){
            if(isColliding){
                right = false;
                x-=speed*4;
            }
            x+=speed;
        }
        //gravity
        if(y > -0) this->y -= 0.005;
    }

    void getEntityList(vector<GameEntity*> list){
        for (GameEntity* e : list)
        {
            if(e != this){
                if(x < e->x + e->s && 
                   x > e->x - e->s &&
                   z < e->z + e->s &&
                   z > e->z - e->s ){
                    isColliding = true;
                }else{
                    isColliding = false;
                }
            }
        }
        
    }

    void keyboardDown(unsigned char key){
        cout << key << endl;
        if(key == 'w'){
            forward = true;
        }
        if(key == 's'){
            backward = true;
        }
        if(key == 'a'){
            left = true;
        }
        if(key == 'd'){
            right = true;
        }
    }

    void keyboardUp(unsigned char key){
        forward = false;
        backward = false;
        left = false;
        right = false;
    }
};