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

int ScriptContext::time(lua_State* L)
{
    lua_pushnumber(L, getContext(L).runService->gameTime());
    return 1;
}

#ifdef SECURITY_CONTEXT_EXPOSES_IDENTITY
int ScriptContext::printidentity(lua_State* L)
{
    if (lua_isstring(L, -1))
        StandardOut::singleton()->print(MESSAGE_OUTPUT, "%s %d", lua_tostring(L, -1), Security::Context::current().identity);
    else
        StandardOut::singleton()->print(MESSAGE_OUTPUT, "Current identity is %d", Security::Context::current().identity);
    return 0;
}
#endif

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

#ifdef SECURITY_CONTEXT_EXPOSES_IDENTITY
ScriptContext::Result ScriptContext::resume(lua_State* thread, int narg)
{
    int n;
    {
        ScriptImpersonator impersonate(thread);
        if (*static_cast<volatile int*>(&exeState))
        {
            if (Security::Context::current().identity == Security::GameScript)
                throw std::runtime_error("Game script timout");
        }
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
#endif
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

#include "script/Script.h"

using namespace RBX;

void ScriptContext::addScript(Script* script)
{
	if (scripts.insert(script).second == true)
	{
		if (!script->isDisabled())
			startScript(shared_from(script));
	}
}

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

#include "reflection/reflection.h"

namespace RBX {
	Reflection::BoundProp<bool, true> ScriptContext::propScriptsDisabled("ScriptsDisabled", "State", &ScriptContext::scriptsDisabled, &ScriptContext::onChangedScriptEnabled, Reflection::PropertyDescriptor::UI);   // 00976b7c
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
