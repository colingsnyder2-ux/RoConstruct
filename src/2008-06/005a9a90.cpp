// from server: 100% by king_originala
struct lua_State;

extern "C" {
int __cdecl lua_gettop(lua_State*);
void __cdecl lua_settop(lua_State*, int);
void __cdecl lua_remove(lua_State*, int);
void __cdecl lua_pushvalue(lua_State*, int);
int __cdecl lua_type(lua_State*, int);
void __cdecl lua_pushlightuserdata(lua_State*, void*);
void __cdecl lua_getfield(lua_State*, int, const char*);
void __cdecl lua_rawget(lua_State*, int);
void __cdecl lua_rawset(lua_State*, int);
int __cdecl lua_setmetatable(lua_State*, int);
void* __cdecl lua_newuserdata(lua_State*, unsigned int);
}

extern const char* metatableName;

void __cdecl push_object(lua_State* state, void* object)
{
    lua_gettop(state);
    lua_pushlightuserdata(state, reinterpret_cast<void*>(&push_object));
    lua_rawget(state, -10000);
    lua_pushlightuserdata(state, object);
    lua_rawget(state, -2);

    if (lua_type(state, -1) == 0) {
        lua_settop(state, -2);
        void** storage = static_cast<void**>(lua_newuserdata(state, 4));
        if (storage)
            *storage = object;

        lua_getfield(state, -10000, metatableName);
        lua_setmetatable(state, -2);
        lua_pushlightuserdata(state, object);
        lua_pushvalue(state, -2);
        lua_rawset(state, -4);
    }

    lua_remove(state, -2);
}
