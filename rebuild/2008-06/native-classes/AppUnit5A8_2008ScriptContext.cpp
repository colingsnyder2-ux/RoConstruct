// 2008-06 native rows of the ScriptContext translation unit (script/ScriptContext.cpp) in the application range
// 005a8000..005b0000 (inactive). Verified by tests/record_native_app_unit5a8_2008.py; the unit map is in its receipt.
//
// Headers are read-only here: the native script/ScriptContext.h (layout: globalState +0x138, yieldEvent +0x1a8,
// sizeof 0x1f8 from malloc(0x1f8) in Creatable<Instance>::create<ScriptContext> 0042d3f0), the donor lua/LuaBridge.h
// and script/LuaAtomicClasses.h templates, and the LuaBridge2008 owner's bridge headers. The constructor and destructor
// are the committed ScriptContextLifetime.cpp (compiled unchanged by the recorder).
#include "script/ScriptContext.h"
#include "lua/LuaBridge.h"
#include "script/LuaAtomicClasses.h"
#include "LuaBridge2008/LuaBridge2008.h"
#include "LuaBridge2008/LuaSignalBridge2008.h"
#include "LuaBridge2008/LuaEnumBridge2008.h"
#include "util/StandardOut.h"
#include "v8datamodel/DebugSettings.h"
#include "v8datamodel/GlobalSettings.h"
#include "security/SecurityContext.h"
#include "G3D/System.h"
#include "lua.h"
#include "lualib.h"

using namespace RBX;

// 005a8660: the sandbox metatable: a new globals table whose __index is the old one.
void ScriptContext::sandboxThread(lua_State* thread)
{
    lua_newtable(thread);
    lua_newtable(thread);
    lua_pushliteral(thread, "__index");
    lua_pushvalue(thread, LUA_GLOBALSINDEX);
    lua_settable(thread, -3);
    lua_setmetatable(thread, -2);
    lua_replace(thread, LUA_GLOBALSINDEX);
}

// 005a9120: RobloxExtraSpace (12 bytes before the lua_State, luaconf.h LUAI_EXTRASPACE) holds the thread counter.
size_t ScriptContext::getThreadCount() const
{
    if (globalState)
        return RobloxExtraSpace::get(globalState)->getThreadCount();
    else
        return 0;
}

// 005a86e0
ScriptContext& ScriptContext::getContext(lua_State* thread)
{
    lua_pushlightuserdata(thread, RBX_LUA_GLOBAL_SCRIPTCONTEXT);
    lua_gettable(thread, LUA_GLOBALSINDEX);
    ScriptContext* sc = static_cast<ScriptContext*>(lua_touserdata(thread, -1));
    lua_pop(thread, 1);
    return *sc;
}

// 005a8750
int ScriptContext::tick(lua_State* L)
{
    lua_pushnumber(L, G3D::System::getTick());
    return 1;
}

// 005a9320
int ScriptContext::print(lua_State* L)
{
    std::string msg;
    int top = lua_gettop(L);

    lua_getglobal(L, "tostring");

    for (int i = 1; i <= top; i++)
    {
        if (i > 1)
            msg += ' ';

        lua_pushvalue(L, -1);
        lua_pushvalue(L, i);
        lua_call(L, 1, 1);

        const char* str = lua_tostring(L, -1);

        if (!str)
            throw std::runtime_error("'tostring' must return a string to 'print'");

        msg += str;

        if (i > 1)
            fputs("\t", stdout);

        lua_pop(L, 1);
    }

    StandardOut::singleton()->print(MESSAGE_OUTPUT, msg.c_str());

    return 0;
}

// 005a8770 (Listener<RunService, RunTransition> slot: this is the listener subobject, globalState at +8)
void ScriptContext::onEvent(const RunService* source, RunTransition event)
{
    if (globalState)
        lua_gc(globalState, LUA_GCCOLLECT, 0);
}

// 005aeaf0: "io" opens only when DebugSettings::ioEnabled (+0x131); settings() 005adc60 is the "settings" global.
void ScriptContext::setThreadIdentity(lua_State* thread, Security::Identities identity)
{
    lua_pushlightuserdata(thread, RBX_LUA_GLOBAL_IDENTITY);
    lua_pushinteger(thread, identity);
    lua_settable(thread, LUA_GLOBALSINDEX);

    if (DebugSettings::singleton().ioEnabled)
    {
        lua_pushcfunction(thread, luaopen_io);
        lua_pushstring(thread, LUA_IOLIBNAME);
        lua_call(thread, 1, 0);
    }

    lua_pushstring(thread, "settings");
    lua_pushcfunction(thread, ScriptContext::settings);
    lua_settable(thread, LUA_GLOBALSINDEX);
}

// 005adc60
int ScriptContext::settings(lua_State* thread)
{
    Security::Context::current().requirePermission(Security::Administrator, "settings()");
    Lua::ObjectBridge::push(thread, GlobalSettings::singleton());
    return 1;
}

// 005ad8c0
ScriptContext::ScriptImpersonator::ScriptImpersonator(lua_State* thread)
    : Security::Impersonator(getThreadIdentity(thread))
{
}

namespace RBX
{
    namespace Lua
    {
        template class Bridge<G3D::CoordinateFrame, true>;
        template class Bridge<G3D::Vector3, true>;
        template class Bridge<G3D::Color3, true>;
        template class Bridge<BrickColor, true>;
        template class Bridge<boost::shared_ptr<Reflection::DescribedBase>, false>;
        template class Bridge<boost::shared_ptr<Reflection::SignalInstance>, false>;
        template class Bridge<boost::signals::connection, true>;
        template class Bridge<ThreadRef::NodePtr, true>;
        template class Bridge<AllEnumDescriptorsPtr, false>;
        template class Bridge<EnumDescriptorPtr, false>;
        template class Bridge<EnumDescriptorItemPtr, false>;
        template class SingletonBridge<AllEnumDescriptorsPtr>;
        template class SingletonBridge<EnumDescriptorPtr>;
        template class SingletonBridge<EnumDescriptorItemPtr>;
        template class SharedPtrBridge<Reflection::DescribedBase>;
        template class SharedPtrBridge<Reflection::SignalInstance>;
        template bool Bridge<G3D::CoordinateFrame, true>::getValue<Reflection::Value>(lua_State*, size_t, Reflection::Value&);
        template bool Bridge<G3D::Vector3, true>::getValue<Reflection::Value>(lua_State*, size_t, Reflection::Value&);
        template bool Bridge<G3D::Color3, true>::getValue<Reflection::Value>(lua_State*, size_t, Reflection::Value&);
        template bool Bridge<BrickColor, true>::getValue<Reflection::Value>(lua_State*, size_t, Reflection::Value&);
        template bool Bridge<boost::shared_ptr<Reflection::DescribedBase>, false>::getValue<Reflection::Value>(lua_State*, size_t, Reflection::Value&);
        template bool SharedPtrBridge<Reflection::DescribedBase>::getPtr<Reflection::Value>(lua_State*, size_t, Reflection::Value&);
    }
}
