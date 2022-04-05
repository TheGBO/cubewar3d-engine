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

int luaSetDrawColor(lua_State* L){
    float r = lua_tonumber(L, 1);
    float g = lua_tonumber(L, 2);
    float b = lua_tonumber(L, 3);

    glColor3f(r,g,b);
    return 0;
}

int luaTranslate(lua_State* L){
    float x = lua_tonumber(L, 1);
    float y = lua_tonumber(L, 2);
    float z = lua_tonumber(L, 3);

    glTranslatef(x,y,z);
    return 0;
}

int luaRotate(lua_State* L){
    float a = lua_tonumber(L, 1);
    float x = lua_tonumber(L, 2);
    float y = lua_tonumber(L, 3);
    float z = lua_tonumber(L, 3);

    glRotatef(a,x,y,z);
    return 0;
}


int luaSolidCube(lua_State* L){
    float x = lua_tonumber(L, 1);
    float y = lua_tonumber(L, 2);
    float z = lua_tonumber(L, 3);
    float s = lua_tonumber(L, 4);
    glTranslatef(x,y,z);
    glutSolidCube(s);
    return 0;
}


