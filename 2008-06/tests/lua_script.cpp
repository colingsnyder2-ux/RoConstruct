// Lua: run a script that uses the base, string, table and math libraries.
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}
#include <stdio.h>
#include <string.h>

int main()
{
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    const char* script =
        "local t = {} for i = 1, 10 do t[#t + 1] = i * i end "
        "table.sort(t, function(a, b) return a > b end) "
        "return string.format('%d|%d|%s|%.3f', #t, t[1], table.concat(t, ',', 9, 10), math.sqrt(2))";
    if (luaL_loadstring(L, script) || lua_pcall(L, 0, 1, 0))
        return printf("lua error: %s\n", lua_tostring(L, -1)), 2;
    const char* result = lua_tostring(L, -1);
    printf("%s %s\n", LUA_RELEASE, result);
    int ok = strcmp(result, "10|100|4,1|1.414") == 0;
    lua_close(L);
    return ok ? 0 : 1;
}
