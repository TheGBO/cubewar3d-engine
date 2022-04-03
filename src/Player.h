#include "GameEntity.h"
 
class Player : public GameEntity{
public:
    Player(float x, float y, float z, float s):GameEntity(x,y,z,s){
        setColor(1,0.1,0.5);
    }
    void tick(){
        offSet(.0001,.0001,.001);
    }
};