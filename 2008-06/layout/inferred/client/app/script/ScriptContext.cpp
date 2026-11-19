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

size_t ScriptContext::getThreadCount() const
{
    if (globalState)
        return RobloxExtraSpace::get(globalState)->getThreadCount();
    else
        return 0;
}

ScriptContext& ScriptContext::getContext(lua_State* thread)
{
    lua_pushlightuserdata(thread, RBX_LUA_GLOBAL_SCRIPTCONTEXT);
    lua_gettable(thread, LUA_GLOBALSINDEX);
    ScriptContext* sc = static_cast<ScriptContext*>(lua_touserdata(thread, -1));
    lua_pop(thread, 1);
    return *sc;
}

int ScriptContext::tick(lua_State* L)
{
    lua_pushnumber(L, G3D::System::getTick());
    return 1;
}

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

void ScriptContext::onEvent(const RunService* source, RunTransition event)
{
    if (globalState)
        lua_gc(globalState, LUA_GCCOLLECT, 0);
}

// INFERRED: 00976b78 is a file-scope long of this unit: the timeout hook 005ae230 errors while it is > 0
static long timedOutScripts;

void ScriptContext::onEvent(const RunService* source, Heartbeat event)
{
    if (exeTime0 > 0)
        exeTime1 = G3D::System::getLocalTime() + exeTime0;

    if (InterlockedExchange(reinterpret_cast<long*>(&exeState), 0) == 1)
        InterlockedDecrement(&timedOutScripts);

    boost::posix_time::ptime t(boost::posix_time::second_clock::local_time());

    if (t >= nextPendingScripts)
    {
        startPendingScripts();
        nextPendingScripts = boost::posix_time::second_clock::local_time() + boost::posix_time::seconds(1);
    }

    if (yieldEvent)
        yieldEvent->resume(event);

    if (globalState)
        lua_gc(globalState, LUA_GCSTEP, 1);
}

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

int ScriptContext::settings(lua_State* thread)
{
    Security::Context::current().requirePermission(Security::Administrator, "settings()");
    Lua::ObjectBridge::push(thread, GlobalSettings::singleton());
    return 1;
}

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

#include "script/Script.h"
#include "script/ThreadRef.h"
#include "lobject.h"
#include <algorithm>

using namespace RBX;

void ScriptContext::disassociateState(Script* script)
{
	Association<Instance>& assoc = script->assoc;

	if (assoc.contains<Lua::ThreadRef::NodePtr>())
	{
		assoc.get<Lua::ThreadRef::NodePtr>()->eraseAllRefs();
		assoc.remove<Lua::ThreadRef::NodePtr>();
	}
}

void ScriptContext::removeScript(Script* script)
{
	if (scripts.erase(script))
	{
		disassociateState(script);

		std::vector<boost::shared_ptr<Script> >::iterator it = std::find(pendingScripts.begin(), pendingScripts.end(), shared_from(script));
		if (it != pendingScripts.end())
			pendingScripts.erase(it);
	}
}

void ScriptContext::reportError(lua_State* thread)
{
	lua_Debug ar;

	StandardOut::singleton()->print(MESSAGE_ERROR, "%s", lua_tostring(thread, -1));

	if (DebugSettings::singleton().stackTracingEnabled)
	{
		if (lua_getstack(thread, 0, &ar))
		{
			bool hasStack = false;
			int level = 0;
			while (lua_getstack(thread, level++, &ar))
			{
				if (lua_getinfo(thread, "nSlu", &ar) && ar.currentline >= 0)
				{
					hasStack = true;
					char source[0x40];
					luaO_chunkid(source, ar.source, 0x40);
					if (ar.name)
						StandardOut::singleton()->print(MESSAGE_INFO, "%s, line %d - %s %s", source, ar.currentline, ar.namewhat, ar.name);
					else
						StandardOut::singleton()->print(MESSAGE_INFO, "%s, line %d", source, ar.currentline);
				}
				if (level >= 12)
					break;
			}

			if (hasStack && level < 12)
				StandardOut::singleton()->print(MESSAGE_INFO, "   stack end");
		}
	}
	else
	{
		StandardOut::singleton()->print(MESSAGE_ERROR, "%s", lua_tostring(thread, -1));
	}
}

#include "util/Name.h"

namespace RBX {

void ScriptContext::call(const Lua::FunctionRef& f, boost::function1<unsigned int, lua_State*, std::allocator<boost::function_base> > pushArguments, boost::function2<void, lua_State*, unsigned int, std::allocator<boost::function_base> > readResults)
{
	if (f.empty())
		throw std::runtime_error("Cannot call a nil function");
	Lua::lua_pushfunction(f.thread(), f);
	resume(f.thread(), pushArguments, readResults);
}

}

#include "LuaBridge2008/LuaInstanceBridge2008.h"
#include "util/standardout.h"
#include "lua/lua.hpp"
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

#include <boost/date_time/posix_time/posix_time.hpp>

RBX::ScriptContext::ScriptContext()
    : globalState(NULL), scripts(std::less<Script*>()),
      nextPendingScripts(boost::posix_time::second_clock::local_time()),
      scriptsDisabled(false), exeTime0(0), exeTime1(0), exeState(0)
{
    setName("Script Context");
}
RBX::ScriptContext::~ScriptContext() {}

template class boost::date_time::counted_time_rep<boost::posix_time::millisec_posix_time_system_config>;
template class boost::scoped_ptr<RBX::Lua::YieldingThreads>;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Lua::YieldingThreads::WaitingThread> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Script *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<boost::shared_ptr<RBX::Script> > >;
template class std::_Tree<std::_Tset_traits<RBX::Script *,std::less<RBX::Script *>,std::allocator<RBX::Script *>,0> >;
template class std::_Vector_val<RBX::Lua::YieldingThreads::WaitingThread,std::allocator<RBX::Lua::YieldingThreads::WaitingThread> >;
template class std::allocator<RBX::Script *>;
template class std::allocator<std::_Tree_nod<std::_Tset_traits<RBX::Script *,std::less<RBX::Script *>,std::allocator<RBX::Script *>,0> >::_Node *>;

namespace RBX {
int ScriptContext::stats(lua_State* L)
{
    Security::Context::current().requirePermission((Security::Permissions)1, "Stats");
    lua_pushlightuserdata(L, RBX_LUA_GLOBAL_SCRIPTCONTEXT);
    lua_gettable(L, LUA_GLOBALSINDEX);
    Instance* instance = (Instance*)lua_touserdata(L, -1);
    lua_pop(L, 1);
    Lua::SharedPtrBridge<Reflection::DescribedBase>::push(L, shared_from(ServiceProvider::create<Stats::StatsService>(instance)));
    return 1;
}
}
