// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_scriptcontext_genuine_singleton_enums17e79b7e49ea6c20.cpp

// Candidate translation unit (score above; library headers required).
#include "roc_genuine_lua_singleton_enum_headerf079742c7efc6c9f.cpp"
#pragma include_alias("v8tree/Instance.h", "roc_instance_genuine_guiditem_headerf016862b4461fbce.cpp")
#include "script/ScriptContext.h"
#include "script/Script.h"
#include "script/ScriptEvent.h"
#include "script/LuaMemory.h"
#include "script/LuaAtomicClasses.h"
#include "script/LuaInstanceBridge.h"
#include "script/LuaSignalBridge.h"
#include "script/LuaArguments.h"
#include "lua/lua.hpp"
#include "lua/LuaBridge.h"
// Workspace's genuine first base reaches Instance at offset zero.
namespace RBX { class Workspace; template<> Workspace* ServiceProvider::find<Workspace>(const Instance*); }
#include "v8datamodel/DebugSettings.h"
#include "v8datamodel/Stats.h"
#include "util/standardout.h"
#include "util/Debug.h"
#include "boost/date_time/posix_time/posix_time.hpp"
#include "lua.h"
#include "lualib.h"
#include "lstate.h"

static int contextCount = 0;
bool vvvvv;

using namespace RBX;
using namespace boost::posix_time;

// unidentified inlines

static inline void _openLibInline(lua_State* L, lua_CFunction f, const char* name)
{
    lua_pushcfunction(L, f);
    lua_pushstring(L, name);
    lua_call(L, 1, 0);
}

// end unidentified inlines

Reflection::BoundProp<bool, true> ScriptContext::propScriptsDisabled("ScriptsDisabled", "State", &ScriptContext::scriptsDisabled, &ScriptContext::onChangedScriptEnabled, Reflection::PropertyDescriptor::LEGACY); 

static int panic(lua_State* L)
{
    std::string message = lua_tostring(L, -1);
    StandardOut::singleton()->print(MESSAGE_ERROR, "Unprotected error in call to Lua API (%s)\n", message.c_str());
    RBXCRASH();
    return 0;
}

const char* RBX::sScriptContext = "ScriptContext";

// Native2008 members on the opaque owner, proven by openState loads/stores.
#define globalState (*reinterpret_cast<lua_State**>(reinterpret_cast<char*>(this)+0x138))
#define allocator (*reinterpret_cast<boost::scoped_ptr<LuaAllocator>*>(reinterpret_cast<char*>(this)+0x1f0))
#define yieldEvent (*reinterpret_cast<boost::scoped_ptr<Lua::YieldingThreads>*>(reinterpret_cast<char*>(this)+0x1a8))
// Native Lua callbacks: lua_CFunction / lua_Hook contracts and observed calls.
extern int luaTime(lua_State*);
extern int luaVersion(lua_State*);
extern int luaPrintIdentity(lua_State*);
extern void luaInstructionHook(lua_State*, lua_Debug*);

namespace RBX { namespace Lua {
template<> const char* Bridge<AllEnumDescriptorsPtr, false>::className = "Enums";
template<> const char* Bridge<EnumDescriptorPtr, false>::className = "Enum";
template<> const char* Bridge<EnumDescriptorItemPtr, false>::className = "EnumItem";
} }

void ScriptContext::openState()
{
    if (!globalState)
    {
        // ???
        if (vvvvv)
        {
            lua_getstack(NULL, NULL, NULL);
            lua_getinfo(NULL, NULL, NULL);
            lua_getlocal(NULL, NULL, NULL);
            lua_setlocal(NULL, NULL, NULL);
            lua_getupvalue(NULL, NULL, NULL);
            lua_setupvalue(NULL, NULL, NULL);
            lua_sethook(NULL, NULL, NULL, NULL);
            lua_gethook(NULL);
            lua_gethookmask(NULL);
            lua_gethookcount(NULL);
        }

        allocator.reset(new LuaAllocator());
        lua_State* L = lua_newstate(LuaAllocator::alloc, allocator.get());
        globalState = L;

        if (!globalState)
            throw std::runtime_error("Failed to create Lua state");

        contextCount++;

        lua_atpanic(L, panic);

        lua_pushlightuserdata(globalState, RBX_LUA_GLOBAL_SCRIPTCONTEXT);
        lua_pushlightuserdata(globalState, this);
        lua_settable(globalState, LUA_GLOBALSINDEX);

        lua_pop(globalState, luaopen_base(globalState));

        _openLibInline(globalState, luaopen_string, LUA_STRLIBNAME);
        _openLibInline(globalState, luaopen_math, LUA_MATHLIBNAME);
        _openLibInline(globalState, luaopen_table, LUA_TABLIBNAME);

        Lua::Enums::registerClass(globalState);
        Lua::Enum::registerClass(globalState);
        Lua::EnumItem::registerClass(globalState);
        Lua::ObjectBridge::registerClass(globalState);
        Lua::SignalBridge::registerClass(globalState);
        Lua::SignalConnectionBridge::registerClass(globalState);
        Lua::CoordinateFrameBridge::registerClass(globalState);
        Lua::Vector3Bridge::registerClass(globalState);
        Lua::Color3Bridge::registerClass(globalState);
        Lua::BrickColorBridge::registerClass(globalState);
        Lua::ThreadRef::NodeBridge::registerClass(globalState);

        Lua::Enums::registerClassLibrary(globalState);
        Lua::Enum::registerClassLibrary(globalState);
        Lua::EnumItem::registerClassLibrary(globalState);
        Lua::CoordinateFrameBridge::registerClassLibrary(globalState);
        Lua::Vector3Bridge::registerClassLibrary(globalState);
        Lua::Color3Bridge::registerClassLibrary(globalState);
        Lua::BrickColorBridge::registerClassLibrary(globalState);
        Lua::ObjectBridge::registerClassLibrary(globalState);
        Lua::ObjectBridge::registerInstanceClassLibrary(globalState);
        Lua::SignalBridge::registerClassLibrary(globalState);

        Lua::ThreadRef::Node::create(globalState);

        lua_pushstring(globalState, "game");
        Lua::ObjectBridge::push(globalState, getRootAncestor()->shared_from_this());
        lua_settable(globalState, LUA_GLOBALSINDEX);

        lua_pushstring(globalState, "workspace");
        Lua::ObjectBridge::push(globalState, reinterpret_cast<Instance*>(ServiceProvider::find<Workspace>(this))->shared_from_this());
        lua_settable(globalState, LUA_GLOBALSINDEX);

        lua_pushstring(globalState, "shared");
        lua_newtable(globalState);
        lua_settable(globalState, LUA_GLOBALSINDEX);

        lua_pushstring(globalState, "print");
        lua_pushcfunction(globalState, ScriptContext::print);
        lua_settable(globalState, LUA_GLOBALSINDEX);

        lua_pushstring(globalState, "tick");
        lua_pushcfunction(globalState, ScriptContext::tick);
        lua_settable(globalState, LUA_GLOBALSINDEX);

        lua_pushstring(globalState, "time");
        lua_pushcfunction(globalState, luaTime);
        lua_settable(globalState, LUA_GLOBALSINDEX);

        lua_pushstring(globalState, "wait");
        lua_pushcfunction(globalState, ScriptContext::wait);
        lua_settable(globalState, LUA_GLOBALSINDEX);

        lua_pushstring(globalState, "delay");
        lua_pushcfunction(globalState, ScriptContext::delay);
        lua_settable(globalState, LUA_GLOBALSINDEX);

        lua_pushstring(globalState, "printidentity");
        lua_pushcfunction(globalState, luaPrintIdentity);
        lua_settable(globalState, LUA_GLOBALSINDEX);

        lua_pushstring(globalState, "dofile");
        lua_pushcfunction(globalState, ScriptContext::dofile);
        lua_settable(globalState, LUA_GLOBALSINDEX);

        lua_pushstring(globalState, "loadfile");
        lua_pushcfunction(globalState, ScriptContext::loadfile);
        lua_settable(globalState, LUA_GLOBALSINDEX);

        lua_pushstring(globalState, "stats");
        lua_pushcfunction(globalState, ScriptContext::stats);
        lua_settable(globalState, LUA_GLOBALSINDEX);

        lua_pushstring(globalState, "version");
        lua_pushcfunction(globalState, luaVersion);
        lua_settable(globalState, LUA_GLOBALSINDEX);

        Lua::Enums::declareAllEnums(globalState);
        yieldEvent.reset(new Lua::YieldingThreads(this));
        if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x1cc))
            lua_sethook(globalState, luaInstructionHook, LUA_MASKCOUNT, 1000);
    }
}


#undef globalState
#undef allocator
#undef yieldEvent
