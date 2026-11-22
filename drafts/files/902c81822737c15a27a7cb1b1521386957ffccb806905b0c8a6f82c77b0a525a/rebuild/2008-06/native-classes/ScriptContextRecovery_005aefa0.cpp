// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::ScriptContext::openState 005aefa0 (private; donor tools/rbxgs script/ScriptContext.cpp shape).
#include "script/ScriptContext.h"
#include "script/Script.h"
#include "script/LuaMemory.h"
#include "LuaBridge2008/LuaEnumBridge2008.h"
#include "script/LuaAtomicClasses.h"
#include "LuaBridge2008/LuaInstanceBridge2008.h"
#include "LuaBridge2008/LuaSignalBridge2008.h"
#include "script/ThreadRef.h"
#include "v8datamodel/Workspace.h"
#include "util/standardout.h"
#include "lualib.h"
#include "util/Debug.h"

using namespace RBX;

static int contextCount = 0;
bool vvvvv;

static inline void _openLibInline(lua_State* L, lua_CFunction f, const char* name)
{
	lua_pushcfunction(L, f);
	lua_pushstring(L, name);
	lua_call(L, 1, 0);
}

// 005aa5b0 (registry placeholder func_005aa5b0; the lua_atpanic handler openState pushes at 005af0d3). 2008 shape:
// lua_tostring(L, -1) 00612010 passed straight to StandardOut::print 005693a0 (no std::string copy, unlike the
// donor), "Unprotected error in call to Lua API (%s)\n" 00834520, then the donor RBXCRASH() (mov ecx,[4];
// mov [0],ecx) and return 0.
static int panic(lua_State* L)
{
	StandardOut::singleton()->print(MESSAGE_ERROR, "Unprotected error in call to Lua API (%s)\n", lua_tostring(L, -1));
	RBXCRASH();
	return 0;
}

void ScriptContext::openState()
{
	if (!globalState)
	{
		// INFERRED: dead debug-API references kept by the original (target tests a global flag, then calls each with NULLs)
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
		Lua::ObjectBridge::push(globalState, ServiceProvider::find<Workspace>(this)->shared_from_this());
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
		lua_pushcfunction(globalState, ScriptContext::time);
		lua_settable(globalState, LUA_GLOBALSINDEX);
		lua_pushstring(globalState, "wait");
		lua_pushcfunction(globalState, ScriptContext::wait);
		lua_settable(globalState, LUA_GLOBALSINDEX);
		lua_pushstring(globalState, "delay");
		lua_pushcfunction(globalState, ScriptContext::delay);
		lua_settable(globalState, LUA_GLOBALSINDEX);
		lua_pushstring(globalState, "printidentity");
		lua_pushcfunction(globalState, ScriptContext::printidentity);
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
		lua_pushcfunction(globalState, getVersion);
		lua_settable(globalState, LUA_GLOBALSINDEX);
		Lua::Enums::declareAllEnums(globalState);
		yieldEvent.reset(new Lua::YieldingThreads(this));

		// INFERRED: target tests the member at +0x1cc (exeThread in script/ScriptContext.h) and calls lua_sethook(L, hook 005ae230, LUA_MASKCOUNT, 1000)
		if (exeThread)
			lua_sethook(globalState, ScriptContext::scriptHook, LUA_MASKCOUNT, 1000);
	}
}
