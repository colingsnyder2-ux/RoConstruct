// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/script-file-load
// >>> native-status (generated) -- do not edit >>>
// ScriptFileLoad | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 7e3a2736 | roc native-status --write
#include "util/NativeContentProvider.h"
#include "script/ScriptContext.h"
#include "lauxlib.h"

namespace RBX {
namespace Lua {
const char* safe_lua_tostring(lua_State* thread, int index)
{
    const char* value = lua_tolstring(thread, index, 0);
    if (!value) {
        std::string message("String expected");
        throw std::runtime_error(message);
    }
    return value;
}
}

inline ScriptContext& ScriptContext::getContext(lua_State* thread)
{
    lua_pushlightuserdata(thread, RBX_LUA_GLOBAL_SCRIPTCONTEXT);
    lua_gettable(thread, LUA_GLOBALSINDEX);
    ScriptContext* context = static_cast<ScriptContext*>(lua_touserdata(thread, -1));
    lua_pop(thread, 1);
    return *context;
}

int ScriptContext::loadfile(lua_State* thread)
{
    Security::Context::current().requirePermission(Security::Administrator, "loadfile");
    ContentId id(Lua::safe_lua_tostring(thread, -1));
    const std::string& file = ServiceProvider::create<ContentProvider>(&getContext(thread))->getFile(id);
    int results;
    if (luaL_loadfile(thread, file.c_str()) == 0) results = 1;
    else {
        lua_pushnil(thread);
        lua_insert(thread, -2);
        results = 2;
    }
    return results;
}

int ScriptContext::dofile(lua_State* thread)
{
    Security::Context::current().requirePermission(Security::Administrator, "dofile");
    const char* path = luaL_optstring(thread, 1, 0);
    int top = lua_gettop(thread);
    ContentId id(path);
    const std::string& file = ServiceProvider::create<ContentProvider>(&getContext(thread))->getFile(id);
    if (luaL_loadfile(thread, file.c_str()) != 0) lua_error(thread);
    lua_call(thread, 0, LUA_MULTRET);
    return lua_gettop(thread) - top;
}
}
