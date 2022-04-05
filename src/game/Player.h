#include "../GameEntity.h"
#include "../Models.h"
 
class Player : public GameEntity{
public:
    bool left;
    bool right;
    bool forward;
    bool backward;
    bool isJumping;
    bool isFalling;

    float speed = 0.01;
    bool isColliding;

    float lastPosX;
    float lastPosY;
    float lastPosZ;

    Player(float x, float y, float z, float s):GameEntity(x,y,z,s){

    }

    void model(){
        glRotatef(30,1,1,1);
        glColor3f(1,.5,0);
        glutSolidCube(this->s-1);
        glColor3f(0,0,0);
        drawQuad(-1,0,-2.5,0.5);
        drawQuad(1,0,-2.5,0.5);
        glColor3f(0,0,1);
        glTranslatef(0,4,0);
        glutSolidCube(5);
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
        if(isJumping){
            y+=speed;
            if(isColliding){
                isJumping = false;
                y-=speed*4;
            }
        }
        if(isFalling){
            y-=speed;
            if(isColliding){
                isFalling = false;
                y+=speed*4;
            }
        }
    }

    void getEntityList(vector<GameEntity*> list){
        for (GameEntity* e : list)
        {
            if(e != this){
                if(x < e->x + e->s && 
                   x > e->x - e->s &&
                   z < e->z + e->s &&
                   z > e->z - e->s &&
                   y < e->y + e->s &&
                   y > e->y - e->s){
                    isColliding = true;
                }else{
                    isColliding = false;
                }
            }
        }
        
    }

    void keyboardDown(unsigned char key){
        cout << key << endl;
        if(key == 'w') forward = true;
        if(key == 's') backward = true;
        if(key == 'a') left = true;
        if(key == 'd') right = true;
        if(key == 32) isJumping = true;
        if(key == 'z') isFalling = true;
    }

    void keyboardUp(unsigned char key){
        if(key == 'd') right = false;
        if(key == 'a') left = false;
        if(key == 'w') forward = false;
        if(key == 's') backward = false;
        if(key == 32) isJumping = false;
        if(key == 'z') isFalling = false;
    }
};