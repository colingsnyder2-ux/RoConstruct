// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/script-file-load
#include "util/NativeContentProvider.h"
#include "script/ScriptContext.h"
#include "lauxlib.h"
#include "script/ScriptEvent.h"
#include "util/RunStateOwner.h"
#include "util/StandardOut.h"

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

// 005a92d0: global 'time' (openState 005aefa0). getContext inlined (lightuserdata 0x43, LUA_GLOBALSINDEX gettable,
// touserdata -1, settop -2), then lua_pushnumber of runService (+0x1a0) gameTime (+0x1b8).
int ScriptContext::time(lua_State* L)
{
    lua_pushnumber(L, getContext(L).runService->gameTime());
    return 1;
}

// 005add30: global 'printidentity' (openState 005aefa0). lua_isstring(L, -1) (00611eb0) selects
// "%s %d" (008346e0) with lua_tostring(L, -1), else "Current identity is %d" (008346c8); both MESSAGE_OUTPUT with
// Security::Context::current() 00493760 identity (+0).
int ScriptContext::printidentity(lua_State* L)
{
    if (lua_isstring(L, -1))
        StandardOut::singleton()->print(MESSAGE_OUTPUT, "%s %d", lua_tostring(L, -1), Security::Context::current().identity);
    else
        StandardOut::singleton()->print(MESSAGE_OUTPUT, "Current identity is %d", Security::Context::current().identity);
    return 0;
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

// 005ae0d0: donor ScriptContext::resume(thread, narg) with the 2008 timeout check inside the impersonator scope:
// exeState (+0x1c8) set and Security::Context::current() identity GameScript (2) -> std::runtime_error("Game script
// timout") 008346a8; lua_resume 00622400; Yield queues the thread on yieldEvent (+0x1a8, queueWaiter 006217d0) unless
// RobloxExtraSpace yieldCaptured (L-0xc, +8); errors go to reportError 005ac610.
ScriptContext::Result ScriptContext::resume(lua_State* thread, int narg)
{
    int n;
    {
        ScriptImpersonator impersonate(thread);
        if (exeState && Security::Context::current().identity == Security::GameScript)
            throw std::runtime_error("Game script timout");
        n = lua_resume(thread, narg);
    }

    switch (n)
    {
        case 0:
            return Success;

        case 1:
            if (!RobloxExtraSpace::get(thread)->yieldCaptured)
                yieldEvent->queueWaiter(thread);

            return Yield;

        default:
            reportError(thread);
            return Error;
    }
}
}
