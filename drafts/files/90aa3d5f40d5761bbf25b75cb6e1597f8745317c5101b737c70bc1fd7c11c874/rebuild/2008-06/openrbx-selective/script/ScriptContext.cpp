#include "script/ScriptContext.h"

#include "lua/lua.hpp"
#include "reflection/signal.h"
#include "script/LuaArguments.h"
#include "script/LuaAtomicClasses.h"
#include "script/LuaInstanceBridge.h"
#include "script/LuaMemory.h"
#include "script/LuaSignalBridge.h"
#include "script/Script.h"
#include "script/ScriptEvent.h"
#include "security/SecurityContext.h"
#include "util/ContentProvider.h"
#include "util/Name.h"
#include "util/StandardOut.h"
#include "v8datamodel/DebugSettings.h"
#include "v8datamodel/Stats.h"
#include "v8datamodel/Workspace.h"

#include <G3D/System.h>
#include <algorithm>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/signals/connection.hpp>
#include <lualib.h>
#include <stdio.h>

static int contextCount;

bool vvvvv;

static void openLibrary(lua_State* L, lua_CFunction function, const char* name)
{
	lua_pushcfunction(L, function);
	lua_pushstring(L, name);
	lua_call(L, 1, 0);
}

namespace RBX {

// PORT: match 2008 reflection name pointer storage.
char* sScriptContext = "ScriptContext";

Reflection::BoundProp<bool, 1> ScriptContext::propScriptsDisabled(
	"ScriptsDisabled",
	"State",
	&ScriptContext::scriptsDisabled,
	&ScriptContext::onChangedScriptEnabled,
	Reflection::PropertyDescriptor::UI
);

namespace Lua {

template <>
const char* Bridge<boost::shared_ptr<Reflection::DescribedBase>, 0>::className = "Object";

} // namespace Lua

// FUNCTION: WEBSERVICE 0x1005eaa0
// FUNCTION: ROBLOX 0x0056bd10
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

// FUNCTION: ROBLOX 0x0056bd70
// PORT: definition is inline in the 2008 header.


// FUNCTION: WEBSERVICE 0x1005eb00
// FUNCTION: ROBLOX 0x0056bd90
ScriptContext& ScriptContext::getContext(lua_State* thread)
{
	lua_pushlightuserdata(thread, (void*) 0x43);
	lua_gettable(thread, LUA_GLOBALSINDEX);

	ScriptContext* context = static_cast<ScriptContext*>(lua_touserdata(thread, -1));

	lua_settop(thread, -2);

	return *context;
}

// FUNCTION: WEBSERVICE 0x1005eb40
// FUNCTION: ROBLOX 0x0056bdd0
int ScriptContext::tick(lua_State* L)
{
	lua_pushnumber(L, G3D::System::getTick());
	return 1;
}

// FUNCTION: WEBSERVICE 0x1005eb60
// FUNCTION: ROBLOX 0x0056bdf0
void ScriptContext::onEvent(const RunService* source, RunTransition event)
{
	if (globalState) {
		lua_gc(globalState, LUA_GCCOLLECT, 0);
	}
}

} // namespace RBX

// FUNCTION: WEBSERVICE 0x1005eb80
// FUNCTION: ROBLOX 0x0056be10
static std::string getFullName(RBX::Instance* instance)
{
	if (instance->getParent() != NULL) {
		if (instance->getParent()->getParent() != NULL) {
			return getFullName(instance->getParent()) + "." + instance->getName();
		}

		return instance->getName();
	}

	return "";
}

namespace RBX {

// FUNCTION: WEBSERVICE 0x1005f880
// FUNCTION: ROBLOX 0x0056ca90
// PORT: definition is inline in the 2008 header.


// FUNCTION: WEBSERVICE 0x1005f8c0
// FUNCTION: ROBLOX 0x0056cad0
// PORT: definition is inline in the 2008 header.


// FUNCTION: WEBSERVICE 0x1005f910
// FUNCTION: ROBLOX 0x0056cb20
// PORT: definition is inline in the 2008 header.


// FUNCTION: WEBSERVICE 0x1005f9a0
// FUNCTION: ROBLOX 0x0056cb70
unsigned int ScriptContext::getThreadCount() const
{
	return globalState ? RobloxExtraSpace::get(globalState)->getThreadCount() : 0;
}

// FUNCTION: WEBSERVICE 0x1005f9c0
// FUNCTION: ROBLOX 0x0056cb90
int ScriptContext::delay(lua_State* thread)
{
	if (lua_gettop(thread) != 2) {
		throw new std::runtime_error("delay function requires 2 arguments");
	}

	double timout = lua_tonumber(thread, 1);

	Lua::ThreadRef functor(lua_newthread(thread));

	lua_pushvalue(thread, 2);

	lua_xmove(thread, functor.thread(), 1);

	getContext(thread).yieldEvent->queueWaiter(functor.thread(), timout);

	lua_pop(thread, 1);

	return 0;
}

// FUNCTION: WEBSERVICE 0x1005fb00
// FUNCTION: ROBLOX 0x0056ccd0
int ScriptContext::wait(lua_State* thread)
{
	double timout = lua_tonumber(thread, 1);

	getContext(thread).yieldEvent->queueWaiter(thread, timout);

	return lua_yield(thread, 0);
}

// FUNCTION: WEBSERVICE 0x1005fb70
// FUNCTION: ROBLOX 0x0056cd40
int ScriptContext::print(lua_State* L)
{
	std::string message;

	int n = lua_gettop(L);
	int i;
	lua_getglobal(L, "tostring");
	for (i = 1; i <= n; i++) {
		if (i > 1) {
			message += ' ';
		}
		lua_pushvalue(L, -1);
		lua_pushvalue(L, i);
		lua_call(L, 1, 1);
		const char* s = lua_tostring(L, -1);
		if (s == NULL) {
			throw std::runtime_error("'tostring' must return a string to 'print'");
		}
		message += s;
		if (i > 1) {
			fputs("\t", stdout);
		}
		lua_pop(L, 1);
	}

	StandardOut::singleton()->print(MESSAGE_OUTPUT, message.c_str());

	return 0;
}

} // namespace RBX

// FUNCTION: WEBSERVICE 0x10061130
// FUNCTION: ROBLOX 0x0056e240
static int panic(lua_State* L)
{
	std::string error = lua_tostring(L, -1);
	RBX::StandardOut::singleton()->print(
		RBX::MESSAGE_ERROR, "Unprotected error in call to Lua API (%s)\n", error.c_str()
	);

	int* crash = NULL;
	*crash = crash[1];

	return 0;
}

// FUNCTION: WEBSERVICE 0x10062ef0
// FUNCTION: ROBLOX 0x00570310
static unsigned int pushArguments(const std::vector<RBX::Reflection::Value>& arguments, lua_State* thread)
{
	unsigned int count = 0;

	std::vector<RBX::Reflection::Value>::const_iterator iter = arguments.begin();
	std::vector<RBX::Reflection::Value>::const_iterator end = arguments.end();
	while (iter != end) {
		count += RBX::Lua::LuaArguments::push(*iter, thread);
		++iter;
	}

	return count;
}

namespace RBX {

// FUNCTION: WEBSERVICE 0x100636b0
// FUNCTION: ROBLOX 0x00570a60
void ScriptContext::reportError(lua_State* thread)
{
	lua_Debug ar;
	int level = 0;

	if (lua_getstack(thread, level++, &ar)) {
		StandardOut::singleton()->print(MESSAGE_ERROR, lua_tostring(thread, -1));

		if (DebugSettings::singleton().getStackTracingEnabled()) {
			if (lua_getstack(thread, level, &ar)) {
				do {
					level++;
					lua_getinfo(thread, "nSlu", &ar);
					StandardOut::singleton()->print(
						MESSAGE_INFO, "   stack %s, line %d: %s %s", ar.source, ar.currentline, ar.namewhat, ar.name
					);
				} while (lua_getstack(thread, level, &ar));

				StandardOut::singleton()->print(MESSAGE_INFO, "   stack end");
			}
		}
	}
	else {
		StandardOut::singleton()->print(MESSAGE_ERROR, lua_tostring(thread, -1));
	}
}

// FUNCTION: WEBSERVICE 0x100644e0
// FUNCTION: ROBLOX 0x00571ad0
void ScriptContext::disassociateState(Script* script)
{
	if (script->association().contains<boost::shared_ptr<Lua::ThreadRef::Node> >()) {
		script->association().get<boost::shared_ptr<Lua::ThreadRef::Node> >()->eraseAllRefs();
		script->association().remove<boost::shared_ptr<Lua::ThreadRef::Node> >();
	}
}

// FUNCTION: WEBSERVICE 0x10064510
// FUNCTION: ROBLOX 0x00571b00
void ScriptContext::removeScript(Script* script)
{
	if (scripts.erase(script)) {
		disassociateState(script);

		std::vector<boost::shared_ptr<Script> >::iterator iter =
			std::find(pendingScripts.begin(), pendingScripts.end(), shared_from(script));
		if (iter != pendingScripts.end()) {
			pendingScripts.erase(iter);
		}
	}
}

} // namespace RBX

// FUNCTION: WEBSERVICE 0x10065240
// FUNCTION: ROBLOX 0x00572380
static void readResults(
	std::auto_ptr<std::vector<RBX::Reflection::Value> >& result, lua_State* thread, unsigned int returnCount
)
{
	result.reset(new std::vector<RBX::Reflection::Value>(returnCount));

	for (unsigned int i = 0; i < returnCount; i++) {
		RBX::Reflection::Value& value = result->at(i);
		// PORT: 2007 treated nil as a value; preserve that behavior in the 2008 API.
		RBX::Lua::LuaArguments::get(thread, i + 1, value, false);
	}
}

namespace RBX {

// FUNCTION: WEBSERVICE 0x10065f80
// FUNCTION: ROBLOX 0x00572880
void ScriptContext::closeState()
{
	if (!globalState) {
		return;
	}

	commandLineSandbox.reset();

	try {
		Lua::ThreadRef::Node::get(globalState)->eraseAllRefs();

		std::set<Script*> copy(scripts);
		std::for_each(copy.begin(), copy.end(), boost::bind(&ScriptContext::disassociateState, this, _1));

		yieldEvent.reset();
	}
	catch (std::exception& e) {
		StandardOut::singleton()->print(MESSAGE_ERROR, "Exception thrown while cleaning up Lua: %s", e.what());
	}

	lua_close(globalState);
	contextCount--;

	{
		unsigned int heapSize;
		unsigned int heapCount;
		unsigned int maxHeapSize;
		unsigned int maxHeapCount;
		allocator->getHeapStats(heapSize, heapCount, maxHeapSize, maxHeapCount);
		StandardOut::singleton()->print(
			MESSAGE_INFO, "Script Heap Stats: Max Size = %d bytes, Max Count = %d blocks", maxHeapSize, maxHeapCount
		);
		allocator->clearHeapMax();

		if (contextCount == 0 && (heapSize > 0 || heapCount > 0)) {
			StandardOut::singleton()->print(
				MESSAGE_ERROR, "Script memory leaks: %d bytes, %d blocks", heapSize, heapCount
			);
		}
	}

	globalState = NULL;
}

// FUNCTION: WEBSERVICE 0x10066200
// FUNCTION: ROBLOX 0x00572b00
ScriptContext::ScriptContext()
	: globalState(NULL), nextPendingScripts(boost::posix_time::second_clock::local_time()), scriptsDisabled(false)
{
	setName("Script Context");
}

// FUNCTION: WEBSERVICE 0x10066460
// FUNCTION: ROBLOX 0x00572d60
ScriptContext::~ScriptContext()
{
}

// FUNCTION: WEBSERVICE 0x10066990
// FUNCTION: ROBLOX 0x00573070
ScriptContext::ScriptImpersonator::ScriptImpersonator(lua_State* thread) : Impersonator(getThreadIdentity(thread))
{
}

// FUNCTION: WEBSERVICE 0x10066ce0
// FUNCTION: ROBLOX 0x005732a0
int ScriptContext::settings(lua_State* thread)
{
	Security::Context::current().requirePermission(Security::Administrator, NULL);

	Lua::SharedPtrBridge<Reflection::DescribedBase>::push(thread, GlobalSettings::singleton());

	return 1;
}

// FUNCTION: WEBSERVICE 0x10066de0
// FUNCTION: ROBLOX 0x005733a0
int ScriptContext::trustedThread(lua_State* thread)
{
	bool trusted = Security::Context::current().hasPermission(Security::Administrator);
	lua_pushboolean(thread, trusted ? 1 : 0);

	return 1;
}

static int loadAux(lua_State* L, int status)
{
	if (status == 0) {
		return 1;
	}
	else {
		lua_pushnil(L);
		lua_insert(L, -2);
		return 2;
	}
}

// FUNCTION: WEBSERVICE 0x10066e10
// FUNCTION: ROBLOX 0x005733d0
int ScriptContext::loadfile(lua_State* L)
{
	Security::Context::current().requirePermission(Security::Administrator, "loadfile");

	ContentId contentId(lua_tostring(L, -1));
	std::string file = ContentProvider::singleton().getFile(contentId);

	return loadAux(L, luaL_loadfile(L, file.c_str()));
}

// FUNCTION: WEBSERVICE 0x10066f20
// FUNCTION: ROBLOX 0x005734e0
int ScriptContext::stats(lua_State* L)
{
	Security::Context::current().requirePermission(Security::Administrator, "Stats");

	Lua::SharedPtrBridge<Reflection::DescribedBase>::push(
		L, shared_from(ServiceProvider::create<Stats::StatsService>(&getContext(L)))
	);

	return 1;
}

// FUNCTION: WEBSERVICE 0x10067020
// FUNCTION: ROBLOX 0x005735e0
int ScriptContext::dofile(lua_State* L)
{
	Security::Context::current().requirePermission(Security::Administrator, "dofile");

	const char* fname = luaL_optstring(L, 1, NULL);
	int n = lua_gettop(L);

	ContentId contentId(fname);
	std::string file = ContentProvider::singleton().getFile(contentId);

	if (luaL_loadfile(L, file.c_str()) != 0) {
		lua_error(L);
	}

	lua_call(L, 0, LUA_MULTRET);

	return lua_gettop(L) - n;
}

// FUNCTION: WEBSERVICE 0x10067140
// FUNCTION: ROBLOX 0x00573700
void ScriptContext::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
{
	stopListening<RunService, RunTransition>(runService, this);
	stopListening<RunService, Heartbeat>(runService, this);

	if (oldProvider && !newProvider) {
		closeState();
	}

	if (statsItem) {
		statsItem->setParent(NULL);
		statsItem.reset();
	}

	Instance::onServiceProvider(oldProvider, newProvider);

	Stats::StatsService* stats = newProvider ? newProvider->create<Stats::StatsService>() : NULL;
	if (stats) {
		statsItem = Creatable<Instance>::create<Stats::Item>("Lua");
		statsItem->setParent(stats);
		statsItem->createBoundChildItem("disabled", scriptsDisabled);
		statsItem->createChildItem<int>("threads", boost::bind(&ScriptContext::getThreadCount, this));
	}

	runService = shared_from(newProvider ? newProvider->create<RunService>() : NULL);

	startListening<RunService, RunTransition>(runService, this);
	startListening<RunService, Heartbeat>(runService, this);
}

// FUNCTION: WEBSERVICE 0x100673d0
// FUNCTION: ROBLOX 0x00573990
ScriptContext::Result ScriptContext::resume(lua_State* thread, int narg)
{
	int result;

	{
		ScriptImpersonator impersonate(thread);
		result = lua_resume(thread, narg);
	}

	switch (result) {
	case 0:
		return Success;

	case LUA_YIELD:
		if (!RobloxExtraSpace::get(thread)->yieldCaptured) {
			yieldEvent->queueWaiter(thread);
		}
		return Yield;

	default:
		reportError(thread);
		return Error;
	}
}

// FUNCTION: WEBSERVICE 0x100674d0
// FUNCTION: ROBLOX 0x00573a90
void ScriptContext::openState()
{
	if (!globalState) {
		if (vvvvv) {
			lua_getstack(NULL, 0, NULL);
			lua_getinfo(NULL, NULL, NULL);
			lua_getlocal(NULL, NULL, 0);
			lua_setlocal(NULL, NULL, 0);
			lua_getupvalue(NULL, 0, 0);
			lua_setupvalue(NULL, 0, 0);
			lua_sethook(NULL, NULL, 0, 0);
			lua_gethook(NULL);
			lua_gethookmask(NULL);
			lua_gethookcount(NULL);
		}

		allocator.reset(new LuaAllocator());
		globalState = lua_newstate(LuaAllocator::alloc, allocator.get());
		if (!globalState) {
			throw std::runtime_error("Failed to create Lua state");
		}

		contextCount++;

		lua_atpanic(globalState, panic);

		lua_pushlightuserdata(globalState, (void*) 0x43);
		lua_pushlightuserdata(globalState, this);
		lua_settable(globalState, LUA_GLOBALSINDEX);

		lua_pop(globalState, luaopen_base(globalState));
		openLibrary(globalState, luaopen_string, "string");
		openLibrary(globalState, luaopen_math, "math");
		openLibrary(globalState, luaopen_table, "table");

		Lua::SharedPtrBridge<Reflection::DescribedBase>::registerClass(globalState);
		Lua::SharedPtrBridge<Reflection::SignalInstance>::registerClass(globalState);
		Lua::Bridge<boost::signals::connection, 1>::registerClass(globalState);
		Lua::Bridge<G3D::CoordinateFrame, 1>::registerClass(globalState);
		Lua::Bridge<G3D::Vector3, 1>::registerClass(globalState);
		Lua::Bridge<G3D::Color3, 1>::registerClass(globalState);
		Lua::Bridge<BrickColor, 1>::registerClass(globalState);
		Lua::Bridge<boost::shared_ptr<Lua::ThreadRef::Node>, 1>::registerClass(globalState);

		Lua::CoordinateFrameBridge::registerClassLibrary(globalState);
		Lua::Vector3Bridge::registerClassLibrary(globalState);
		Lua::Color3Bridge::registerClassLibrary(globalState);
		Lua::BrickColorBridge::registerClassLibrary(globalState);
		Lua::SharedPtrBridge<Reflection::DescribedBase>::registerClassLibrary(globalState);
		Lua::ObjectBridge::registerInstanceClassLibrary(globalState);
		Lua::SharedPtrBridge<Reflection::SignalInstance>::registerClassLibrary(globalState);

		Lua::ThreadRef::Node::create(globalState);

		lua_pushstring(globalState, "game");
		Lua::SharedPtrBridge<Reflection::DescribedBase>::push(globalState, getRootAncestor()->shared_from_this());
		lua_settable(globalState, LUA_GLOBALSINDEX);

		lua_pushstring(globalState, "workspace");
		Lua::SharedPtrBridge<Reflection::DescribedBase>::push(
			globalState, ServiceProvider::find<Workspace>(this)->shared_from_this()
		);
		lua_settable(globalState, LUA_GLOBALSINDEX);

		lua_pushstring(globalState, "shared");
		lua_newtable(globalState);
		lua_settable(globalState, LUA_GLOBALSINDEX);

		lua_pushstring(globalState, "print");
		lua_pushcfunction(globalState, print);
		lua_settable(globalState, LUA_GLOBALSINDEX);

		lua_pushstring(globalState, "tick");
		lua_pushcfunction(globalState, tick);
		lua_settable(globalState, LUA_GLOBALSINDEX);

		lua_pushstring(globalState, "wait");
		lua_pushcfunction(globalState, wait);
		lua_settable(globalState, LUA_GLOBALSINDEX);

		lua_pushstring(globalState, "delay");
		lua_pushcfunction(globalState, delay);
		lua_settable(globalState, LUA_GLOBALSINDEX);

		lua_pushstring(globalState, "trustedThread");
		lua_pushcfunction(globalState, trustedThread);
		lua_settable(globalState, LUA_GLOBALSINDEX);

		lua_pushstring(globalState, "dofile");
		lua_pushcfunction(globalState, dofile);
		lua_settable(globalState, LUA_GLOBALSINDEX);

		lua_pushstring(globalState, "loadfile");
		lua_pushcfunction(globalState, loadfile);
		lua_settable(globalState, LUA_GLOBALSINDEX);

		lua_pushstring(globalState, "stats");
		lua_pushcfunction(globalState, stats);
		lua_settable(globalState, LUA_GLOBALSINDEX);

		yieldEvent.reset(new Lua::YieldingThreads(this));
	}
}

// FUNCTION: WEBSERVICE 0x10067c20
// FUNCTION: ROBLOX 0x005741e0
void ScriptContext::setThreadIdentity(lua_State* thread, Security::Identities identity)
{
	lua_pushlightuserdata(thread, (void*) 0x54);
	lua_pushinteger(thread, identity);
	lua_settable(thread, LUA_GLOBALSINDEX);

	if (DebugSettings::singleton().getioEnabled()) {
		lua_pushcfunction(thread, luaopen_io);
		lua_pushstring(thread, "io");
		lua_call(thread, 1, 0);
	}

	lua_pushstring(thread, "settings");
	lua_pushcfunction(thread, settings);
	lua_settable(thread, LUA_GLOBALSINDEX);
}

// FUNCTION: WEBSERVICE 0x10067cb0
// FUNCTION: ROBLOX 0x00574270
void ScriptContext::resume(
	lua_State* thread,
	boost::function1<unsigned int, lua_State*> pushArguments,
	boost::function2<void, lua_State*, unsigned int> readResults
)
{
	int top = lua_gettop(thread);

	int narg = pushArguments(thread);

	if (resume(thread, narg) != Error) {
		const int returnCount = lua_gettop(thread) - top + 1;

		try {
			readResults(thread, returnCount);
		}
		catch (...) {
			lua_pop(thread, returnCount);
			throw;
		}

		lua_pop(thread, returnCount);
	}
	else {
		std::string err = lua_tostring(thread, -1);
		lua_settop(thread, 0);
		throw std::runtime_error(err);
	}
}

// FUNCTION: WEBSERVICE 0x10067e00
// FUNCTION: ROBLOX 0x005743c0
void ScriptContext::startScript(boost::shared_ptr<Script> script)
{
	if (scriptsDisabled) {
		pendingScripts.push_back(script);
		return;
	}

	boost::shared_ptr<const std::string> code = script->requestCode();
	if (!code) {
		pendingScripts.push_back(script);
		return;
	}

	openState();

	lua_State* thread = lua_newthread(globalState);
	if (!thread) {
		StandardOut::singleton()->print(
			MESSAGE_ERROR, "Unable to create a new thread for %s. It did not execute", script->getName().c_str()
		);
		return;
	}

	Lua::ScopedPopper popper(globalState, 1);

	lua_newtable(thread);
	lua_newtable(thread);
	lua_pushliteral(thread, "__index");
	lua_pushvalue(thread, LUA_GLOBALSINDEX);
	lua_settable(thread, -3);
	lua_setmetatable(thread, -2);
	lua_replace(thread, LUA_GLOBALSINDEX);

	setThreadIdentity(thread, Security::GameScript);

	script->association().get<boost::shared_ptr<Lua::ThreadRef::Node> >() = Lua::ThreadRef::Node::create(thread);

	Lua::SharedPtrBridge<Reflection::DescribedBase>::push(thread, script);
	lua_setfield(thread, LUA_GLOBALSINDEX, "script");

	std::string name = std::string("=") + getFullName(script.get());
	if (luaL_loadbuffer(thread, code->c_str(), code->size(), name.c_str())) {
		StandardOut::singleton()->print(MESSAGE_ERROR, lua_tostring(thread, -1));
		lua_pop(thread, 1);
	}
	else {
		resume(thread, 0);
	}

	lua_settop(thread, 0);
}

// FUNCTION: WEBSERVICE 0x10068220
// FUNCTION: ROBLOX 0x005747e0
void ScriptContext::executeInNewThread(
	Security::Identities identity,
	const char* script,
	const char* name,
	boost::function1<unsigned int, lua_State*> pushArguments,
	boost::function2<void, lua_State*, unsigned int> readResults
)
{
	openState();

	lua_State* parent;
	lua_State* thread;

	if (identity == Security::CmdLine) {
		if (!commandLineSandbox.thread()) {
			commandLineSandbox = lua_newthread(globalState);
			if (!commandLineSandbox.thread()) {
				throw std::runtime_error("Unable to create trusted sandbox thread");
			}
			sandboxThread(commandLineSandbox.thread());
			setThreadIdentity(commandLineSandbox.thread(), Security::CmdLine);
			lua_pop(globalState, 1);
		}

		parent = commandLineSandbox.thread();
		thread = lua_newthread(parent);
	}
	else {
		parent = globalState;
		thread = lua_newthread(parent);
		sandboxThread(thread);
		setThreadIdentity(thread, identity);
	}

	if (!thread) {
		StandardOut::singleton()->print(MESSAGE_ERROR, "ScriptContext::execute: Unable to create a new thread");
		throw std::runtime_error("Unable to create a new thread");
	}

	Lua::ScopedPopper popper(parent, 1);

	std::string sName = "=";
	if (name) {
		sName += name;
	}
	else {
		sName += "Script";
	}

	if (luaL_loadbuffer(thread, script, strlen(script), sName.c_str())) {
		std::string err = lua_tostring(thread, -1);
		lua_pop(thread, 1);

		StandardOut::singleton()->print(MESSAGE_ERROR, err.c_str());
		throw std::runtime_error(err);
	}

	resume(thread, pushArguments, readResults);
}

// FUNCTION: ROBLOX 0x00574c00
void ScriptContext::call(
	const Lua::FunctionRef& function,
	boost::function1<unsigned int, lua_State*> pushArguments,
	boost::function2<void, lua_State*, unsigned int> readResults
)
{
	if (!function.thread()) {
		throw std::runtime_error("Cannot call a nil function");
	}

	lua_pushfunction(function.thread(), function);
	resume(function.thread(), pushArguments, readResults);
}

// FUNCTION: WEBSERVICE 0x10068640
// FUNCTION: ROBLOX 0x00574d60
void ScriptContext::startPendingScripts()
{
	if (!scriptsDisabled) {
		std::vector<boost::shared_ptr<Script> > copy(pendingScripts);
		pendingScripts.clear();

		std::for_each(copy.begin(), copy.end(), boost::bind(&ScriptContext::startScript, this, _1));
	}
}

// FUNCTION: WEBSERVICE 0x10068760
// FUNCTION: ROBLOX 0x00574e80
void ScriptContext::onChangedScriptEnabled(const Reflection::PropertyDescriptor&)
{
	if (scriptsDisabled) {
		startPendingScripts();
	}
}

// FUNCTION: WEBSERVICE 0x10068780
// FUNCTION: ROBLOX 0x00574ea0
void ScriptContext::addScript(Script* script)
{
	if (scripts.insert(script).second == true) {
		if (!script->isDisabled()) {
			startScript(shared_from(script));
		}
	}
}

static unsigned int FUN_00407390(lua_State* thread)
{
	return 0;
}

static void FUN_00751160(lua_State* thread, unsigned int count)
{
}

// STUB: ROBLOX 0x00574ef0
void ScriptContext::executeInNewThread(Security::Identities identity, const char* script, const char* name)
{
	executeInNewThread(identity, script, name, &FUN_00407390, &FUN_00751160);
}

// FUNCTION: ROBLOX 0x00574f60
std::auto_ptr<std::vector<Reflection::Value> > ScriptContext::call(
	const Lua::FunctionRef& function, const std::vector<Reflection::Value>& arguments
)
{
	std::auto_ptr<std::vector<Reflection::Value> > result;

	call(
		function,
		boost::bind(&pushArguments, boost::cref(arguments), _1),
		boost::bind(&readResults, boost::ref(result), _1, _2)
	);

	return result;
}

// FUNCTION: WEBSERVICE 0x100687d0
// FUNCTION: ROBLOX 0x00575000
std::auto_ptr<std::vector<Reflection::Value> > ScriptContext::executeInNewThread(
	Security::Identities identity, const char* script, const char* name, const std::vector<Reflection::Value>& arguments
)
{
	std::auto_ptr<std::vector<Reflection::Value> > result;

	executeInNewThread(
		identity,
		script,
		name,
		boost::bind(&pushArguments, boost::cref(arguments), _1),
		boost::bind(&readResults, boost::ref(result), _1, _2)
	);

	return result;
}

// FUNCTION: WEBSERVICE 0x10068880
// FUNCTION: ROBLOX 0x005750b0
void ScriptContext::onEvent(const RunService* source, Heartbeat event)
{
	if (boost::posix_time::second_clock::local_time() >= nextPendingScripts) {
		startPendingScripts();
		nextPendingScripts = boost::posix_time::second_clock::local_time() + boost::posix_time::seconds(1);
	}

	if (yieldEvent) {
		yieldEvent->resume(event);
	}

	if (globalState) {
		lua_gc(globalState, LUA_GCSTEP, 1);
	}
}

} // namespace RBX

template void RBX::Lua::SharedPtrBridge<RBX::Reflection::DescribedBase>::push(
	lua_State* L, boost::shared_ptr<RBX::Reflection::DescribedBase> instance
);

template void RBX::Lua::SharedPtrBridge<RBX::Reflection::SignalInstance>::push(
	lua_State* L, boost::shared_ptr<RBX::Reflection::SignalInstance> instance
);

// PORT: 2008 FactoryProduct keeps Creator private and defines creator in its header.


template const RBX::Name& RBX::Name::doDeclare<&RBX::Stats::sStatsItem>();
template const RBX::Name& RBX::Name::doDeclare<&RBX::Stats::sStats>();
template const RBX::Name& RBX::Name::doDeclare<&RBX::sDebugSettings>();
template void RBX::Name::callDoDeclare<&RBX::Stats::sStatsItem>();
template void RBX::Name::callDoDeclare<&RBX::Stats::sStats>();
template void RBX::Name::callDoDeclare<&RBX::sDebugSettings>();

// PORT: 2008 reflection templates take name-pointer variable addresses.
template class RBX::FactoryProduct<RBX::ScriptContext, RBX::Instance, &RBX::sScriptContext>;
template class RBX::Reflection::Described<
	RBX::ScriptContext,
	&RBX::sScriptContext,
	RBX::FactoryProduct<RBX::ScriptContext, RBX::Instance, &RBX::sScriptContext> >;
template class RBX::DescribedCreatable<RBX::ScriptContext, RBX::Instance, &RBX::sScriptContext>;
