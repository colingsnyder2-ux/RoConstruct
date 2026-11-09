// from server: 96% by atomic.potato
extern "C" void __cdecl lua_pushnumber(void *, double);

struct S
{
    int f(double);
};

int S::f(double value)
{
    lua_pushnumber(*(void **)this, value);
    return 1;
}
