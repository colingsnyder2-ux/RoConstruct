#include "force_verified.h"
#pragma comment(linker, "/INCLUDE:?luaO_pushfstring@@YAPBDPAUlua_State@@PBDZZ")
// Native App calls Lua through its C++ API; verify exception recovery and coroutines.
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include <cstdio>
#include <cstring>

int main()
{
    lua_State* state = luaL_newstate();
    luaL_openlibs(state);
    const char* script =
        "local ok, err = pcall(function() error('native error') end) "
        "assert(not ok and string.find(err, 'native error')) "
        "local co = coroutine.create(function() coroutine.yield(7); return 9 end) "
        "local ok, value = coroutine.resume(co); assert(ok and value == 7) "
        "ok, value = coroutine.resume(co); assert(ok and value == 9) "
        "assert(coroutine.status(co) == 'dead') "
        "local t = {} for i = 1, 100 do t[i] = i end "
        "collectgarbage('collect') "
        "return string.format('%d|%d|%.3f', #t, t[100], math.sqrt(2))";
    if (luaL_loadstring(state, script) || lua_pcall(state, 0, 1, 0))
        return std::printf("Lua C++ error: %s\n", lua_tostring(state, -1)), 2;
    const char* result = lua_tostring(state, -1);
    std::printf("%s C++ %s\n", LUA_RELEASE, result);
    int ok = std::strcmp(result, "100|100|1.414") == 0;
    lua_close(state);
    return ok ? 0 : 1;
}
