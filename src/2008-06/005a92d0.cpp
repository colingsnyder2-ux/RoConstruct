// from server: 100% by king_originala
struct lua_State;

extern "C" void __cdecl lua_pushlightuserdata(lua_State *, void *);
extern "C" void __cdecl lua_rawget(lua_State *, int);
extern "C" void * __cdecl lua_touserdata(lua_State *, int);
extern "C" void __cdecl lua_settop(lua_State *, int);
extern "C" void __cdecl lua_pushnumber(lua_State *, double);

int __cdecl f(lua_State *L)
{
    lua_pushlightuserdata(L, (void *)0x43);
    lua_rawget(L, -10002);
    void *context = lua_touserdata(L, -1);
    lua_settop(L, -2);
    void *object = *(void **)((char *)context + 0x1a0);
    lua_pushnumber(L, *(double *)((char *)object + 0x1b8));
    return 1;
}
