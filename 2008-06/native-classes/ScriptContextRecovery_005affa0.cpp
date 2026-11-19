// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::ScriptContext::startScript 005affa0 (donor tools/rbxgs script/ScriptContext.cpp shape).
#include "script/ScriptContext.h"
#include "script/Script.h"
#include "LuaBridge2008/LuaBridge2008.h"
#include "LuaBridge2008/LuaInstanceBridge2008.h"
#include "script/ThreadRef.h"
#include "util/standardout.h"
#include "lua/lua.hpp"
#include "lualib.h"
#include <stdexcept>
#include <G3D/format.h>

using namespace RBX;

void ScriptContext::startScript(boost::shared_ptr<Script> script)
{
	if (scriptsDisabled)
	{
		pendingScripts.push_back(script);
		return;
	}

	boost::shared_ptr<const std::string> code = script->requestCode();

	if (!code)
	{
		pendingScripts.push_back(script);
		return;
	}

	openState();
	lua_State* thread = lua_newthread(globalState);

	if (!thread)
	{
		throw std::runtime_error(G3D::format("Unable to create a new thread for %s", script->getName().c_str()));
	}

	Lua::ScopedPopper popper(globalState, 1);

	// INFERRED: the target inlines ScriptContext::sandboxThread here
	lua_newtable(thread);
	lua_newtable(thread);
	lua_pushliteral(thread, "__index");
	lua_pushvalue(thread, LUA_GLOBALSINDEX);
	lua_settable(thread, -3);
	lua_setmetatable(thread, -2);
	lua_replace(thread, LUA_GLOBALSINDEX);
	setThreadIdentity(thread, Security::GameScript);

	script->assoc.get<Lua::ThreadRef::NodePtr>() = Lua::ThreadRef::Node::create(thread);

	Lua::ObjectBridge::push(thread, script);
	lua_setfield(thread, LUA_GLOBALSINDEX, "script");

	std::string name = std::string("=") + script->getFullName();

	int loadResult = luaL_loadbuffer(thread, code->c_str(), code->length(), name.c_str());
	if (loadResult)
	{
		StandardOut::singleton()->print(MESSAGE_ERROR, Lua::tostringOrEmpty(thread, -1));
		lua_pop(thread, 1);
	}
	else
	{
		resume(thread, 0);
	}

	lua_settop(thread, 0);
}
