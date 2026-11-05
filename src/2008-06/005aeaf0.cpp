// from server: 100% by king_originala
struct lua_State;
typedef int (__cdecl *lua_CFunction)(lua_State *);

extern "C" {
void __cdecl lua_pushboolean(lua_State *, int);
void __cdecl lua_pushinteger(lua_State *, int);
void __cdecl lua_pushstring(lua_State *, const char *);
void __cdecl lua_pushcclosure(lua_State *, lua_CFunction, int);
void __cdecl lua_settable(lua_State *, int);
void __cdecl lua_call(lua_State *, int, int);
char * __cdecl getSettings();
int __cdecl callback_624f80(lua_State *);
int __cdecl callback_5adc60(lua_State *);
}

extern const char string_834860[];
extern const char string_834854[];

void __cdecl initialize(lua_State *state, int value)
{
    lua_pushboolean(state, 84);
    lua_pushinteger(state, value);
    lua_settable(state, -10002);

    if (getSettings()[0x131] != 0) {
        lua_pushcclosure(state, callback_624f80, 0);
        lua_pushstring(state, string_834860);
        lua_call(state, 1, 0);
    }

    lua_pushstring(state, string_834854);
    lua_pushcclosure(state, callback_5adc60, 0);
    lua_settable(state, -10002);
}
