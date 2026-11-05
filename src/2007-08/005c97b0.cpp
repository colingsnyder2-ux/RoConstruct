// from server: 100% by colin
// roc 2007-08 005c97b0  unit: lua_exception  size: 38 bytes

extern "C" double __cdecl luaL_checknumber(void* L, int arg);
extern "C" void __cdecl lua_pushnumber(void* L, double n);

extern double g_deg2rad;

int lua_math_deg(void* L)
{
    double d = luaL_checknumber(L, 1);
    lua_pushnumber(L, d * g_deg2rad);
    return 1;
}
