#include "LuaInterface.h"


bool CheckLua(lua_State *L, int r)
{
    if(r != LUA_OK){
        cout << "LUA ERROR: " << lua_tostring(L,-1) << endl;
        return false;
    }
    return true;
}

int luaDrawQuad(lua_State* L){
    float x = lua_tonumber(L, 1);
    float y = lua_tonumber(L, 2);
    float z = lua_tonumber(L, 3);
    float s = lua_tonumber(L, 4);

    drawQuad(x,y,z,s);
    return 0;
}