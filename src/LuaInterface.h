#ifndef LUA_API_H_INC
#define LUA_API_H_INC

#include <iostream>
#include "Models.h"

using namespace std;

extern "C"{
    #include <lua/lua.h>
    #include <lua/lauxlib.h>
    #include <lua/lualib.h>
}

bool CheckLua(lua_State*, int);

int luaDrawQuad(lua_State* L);
int luaSetDrawColor(lua_State* L);

#endif