// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" {
struct lua_State;
typedef int (*lua_CFunction)(lua_State*);
void lua_pushlightuserdata(lua_State* L, void* p);
void lua_pushinteger(lua_State* L, int n);
void lua_settable(lua_State* L, int idx);
void lua_pushstring(lua_State* L, const char* s);
void lua_pushcclosure(lua_State* L, lua_CFunction fn, int n);
}
void openState(lua_State* L);
int settingsFunc(lua_State* L);

void setupState(lua_State* L, int identity)
{
	openState(L);
	lua_pushlightuserdata(L, (void*)0x54);
	lua_pushinteger(L, identity);
	lua_settable(L, -10002);
	lua_pushstring(L, "settings");
	lua_pushcclosure(L, settingsFunc, 0);
	lua_settable(L, -10002);
}
