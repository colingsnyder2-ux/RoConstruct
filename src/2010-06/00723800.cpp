// from server: 100% by atomic.potato
extern "C" int __cdecl lua_gettop(void *);

struct LuaArguments
{
    void *state;
    int getTop();
};

int LuaArguments::getTop()
{
    return lua_gettop(*(void **)((char *)this + 0x10)) - 1;
}
