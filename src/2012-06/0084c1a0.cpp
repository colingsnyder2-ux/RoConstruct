// from server: 96% by atomic.potato
extern "C" void __cdecl lua_pushnumber(int, double);

struct LuaArguments
{
    int pushNumber(float);
};

int LuaArguments::pushNumber(float value)
{
    lua_pushnumber(*reinterpret_cast<int *>(this), value);
    return 1;
}
