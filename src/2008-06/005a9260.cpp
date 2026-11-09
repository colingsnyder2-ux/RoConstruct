// from server: 100% by king_originala
struct lua_State;

struct Scheduler {
    void wait(lua_State*, double);
};

struct Context {
    char padding[0x1A8];
    Scheduler* scheduler;
};

extern "C" double __cdecl lua_tonumber(lua_State*, int);
extern "C" void __cdecl lua_pushlightuserdata(lua_State*, void*);
extern "C" void __cdecl lua_rawget(lua_State*, int);
extern "C" void* __cdecl lua_touserdata(lua_State*, int);
extern "C" void __cdecl lua_settop(lua_State*, int);
extern "C" int __cdecl lua_yield(lua_State*, int);

int __cdecl wait_callback(lua_State* state)
{
    double duration = lua_tonumber(state, 1);
    lua_pushlightuserdata(state, reinterpret_cast<void*>(0x43));
    lua_rawget(state, -10002);
    Context* context = static_cast<Context*>(lua_touserdata(state, -1));
    lua_settop(state, -2);
    context->scheduler->wait(state, duration);
    return lua_yield(state, 0);
}
