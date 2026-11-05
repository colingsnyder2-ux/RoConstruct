// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct lua_State;
struct lua_Debug;
extern "C" {
void lua_pushlightuserdata(lua_State* L, void* p);
void lua_gettable(lua_State* L, int idx);
void* lua_touserdata(lua_State* L, int idx);
void lua_settop(lua_State* L, int idx);
int luaL_error(lua_State* L, const char* fmt, ...);
}
struct RunState { int* get(); };
extern volatile int hookCount;
struct ScriptContext {
    char pad[0x120];
    RunState* active;
    static void hook(lua_State* L, lua_Debug* ar);
};
void ScriptContext::hook(lua_State* L, lua_Debug* ar)
{
    if (hookCount > 0) {
        lua_pushlightuserdata(L, (void*)0x43);
        lua_gettable(L, -10002);
        ScriptContext* sc = (ScriptContext*)lua_touserdata(L, -1);
        lua_settop(L, -2);
        if (sc->active && *sc->active->get() == 2)
            luaL_error(L, "Game script timout");
    }
}
