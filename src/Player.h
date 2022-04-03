#include "GameEntity.h"
 
class Player : public GameEntity{
public:
    Player(float x, float y, float z, float s):GameEntity(x,y,z,s){}
    void tick(){
        offSet(0.0001,0.0001,0.005);
    }
};