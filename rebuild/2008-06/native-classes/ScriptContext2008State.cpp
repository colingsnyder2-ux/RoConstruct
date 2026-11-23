// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boost-function-pod-vtable
// 2008-06 native RBX::ScriptContext script bookkeeping rows (inactive): removeScript 005ad030 (with disassociateState
// inlined, as in the target). Shape after the donor tools/rbxgs ScriptContext.cpp; header script/ScriptContext.h.
#include "script/Script.h"
#include "script/ScriptContext.h"
#include "script/ThreadRef.h"
#include "util/StandardOut.h"
#include "v8datamodel/DebugSettings.h"
#include "lobject.h"
#include "LuaBridge2008/LuaArguments2008.h"
#include "v8datamodel/Stats.h"
#include "boost/bind.hpp"
#include "script/LuaMemory.h"
#include <algorithm>
#include "AppUnit4BC_2008/AssociationTimeStamp.h"
#include "lua/lua.hpp"
#include "lauxlib.h"

using namespace RBX;

namespace RBX
{
	// INFERRED: the per-type item index of Association<Associated>. openrbx util/Association.h has a private member
	// template `index<U>()` holding `static const unsigned int i = count()++;`, shared by contains/remove/get of one U
	// (005aae90, 005aaf20 and get 005acd70 all use guard 00976be4 / value 00976be0 and bump count() 00971a80). The
	// read-only donor util/Association.h declares no index(), so this file-local helper keeps one static per U and
	// returns it by const reference (the guard is re-tested at every use, as in the target).
	template<typename Associated, typename U>
	struct AssociationItemIndex
	{
		static const size_t& get(size_t& counter)
		{
			static const size_t index = counter++;
			return index;
		}
	};

	// 005aae90 (registry placeholder func_005aae90): Association<Instance>::contains<Lua::ThreadRef::NodePtr>, called by
	// disassociateState 005ad000 on Script::assoc (+0xec). openrbx statement shape.
	template<typename Associated>
	template<typename U>
	bool Association<Associated>::contains() const
	{
		return items.size() > AssociationItemIndex<Associated, U>::get(count()) && items[AssociationItemIndex<Associated, U>::get(count())] != NULL;
	}

	// 005aaf20 (registry placeholder func_005aaf20): Association<Instance>::remove<Lua::ThreadRef::NodePtr> (virtual
	// scalar deleting destructor slot 0 with push 1, then the slot is cleared). openrbx statement shape.
	template<typename Associated>
	template<typename U>
	void Association<Associated>::remove()
	{
		if (items.size() > AssociationItemIndex<Associated, U>::get(count()))
		{
			delete items[AssociationItemIndex<Associated, U>::get(count())];
			items[AssociationItemIndex<Associated, U>::get(count())] = NULL;
		}
	}
}

// disassociateState (inlined into removeScript 005ad030: ThreadRef node association at Script +0xec)
void ScriptContext::disassociateState(Script* script)
{
	Association<Instance>& assoc = script->assoc;

	if (assoc.contains<Lua::ThreadRef::NodePtr>())
	{
		assoc.get<Lua::ThreadRef::NodePtr>()->eraseAllRefs();
		assoc.remove<Lua::ThreadRef::NodePtr>();
	}
}

// INFERRED: the file-static context counter of the original ScriptContext unit (dword 00976b74; decremented by
// closeState 005ae280, incremented by openState 005aefa0, which keeps its own copy in ScriptContextRecovery_005aefa0.cpp).
static int contextCount = 0;

// 005ae280 (registry placeholder func_005ae280, 524 B; catch funclet prints the std::exception text): identity from
// the donor tools/rbxgs ScriptContext::closeState and the target references: globalState +0x138 test, ThreadRef::reset
// 00594060 on commandLineSandbox +0x13c, ThreadRef::Node::get 00593cb0 + eraseAllRefs 00594210, std::set<Script*> copy
// 005aca50 of scripts +0x15c, for_each 005ac450 with bind(&disassociateState 005ad000, this, _1), scoped_ptr reset of
// yieldEvent +0x1a8 (~vector<WaitingThread> 005ad190), "Exception thrown while cleaning up Lua: %s" 00834728,
// lua_close 00623e30, contextCount 00976b74, LuaAllocator::getHeapStats 005c8960 / clearHeapMax 005c8930 on
// allocator +0x1f0 and "Script memory leaks..." 008346fc. 2008 difference: no "Script Heap Stats" info line.
void ScriptContext::closeState()
{
	if (globalState)
	{
		commandLineSandbox.reset();

		try
		{
			Lua::ThreadRef::Node::get(globalState)->eraseAllRefs();

			std::set<Script*> copy = scripts;
			std::for_each(copy.begin(), copy.end(), boost::bind(&ScriptContext::disassociateState, this, _1));

			yieldEvent.reset(NULL);
		}
		catch (std::exception& e)
		{
			StandardOut::singleton()->print(MESSAGE_ERROR, "Exception thrown while cleaning up Lua: %s", e.what());
		}

		lua_close(globalState);
		contextCount--;

		{
			size_t heapSize, heapCount, maxHeapSize, maxHeapCount;
			allocator->getHeapStats(heapSize, heapCount, maxHeapSize, maxHeapCount);
			allocator->clearHeapMax();

			if (contextCount == 0 && (heapSize > 0 || heapCount > 0))
				StandardOut::singleton()->print(MESSAGE_ERROR, "Script memory leaks: %d bytes, %d blocks", heapSize, heapCount);
		}

		globalState = NULL;
	}
}

// 005ad030
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

// 005ac610 (donor reportError with the 2008 differences: the "%s" error line is printed first; with stack tracing off
// it is printed once more (jump 005ac84f); at most 12 levels, "%s, line %d[ - %s %s]" per level, "   stack end" only
// when the walk ran out of levels before the cap).
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
			do
			{
				if (!lua_getstack(thread, level++, &ar))
					break;

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
			} while (level < 12);

			if (hasStack && level < 12)
				StandardOut::singleton()->print(MESSAGE_INFO, "   stack end");
		}
	}
	else
	{
		StandardOut::singleton()->print(MESSAGE_ERROR, "%s", lua_tostring(thread, -1));
	}
}

// 005afd60 (donor onServiceProvider without the Instance::onServiceProvider call: the original has none between the
// statsItem release (00456e80 at 005afdf5) and the newProvider test (005afdfa), as in Script::onServiceProvider 00586bf0).
// Calls: removeListener 005e5a80 (+0x170 RunTransition, +0x130 Heartbeat), closeState 005ae280, setParent 0055a8f0,
// create<StatsService> 00458610, create<Stats::Item, const char*> 005adb70 ("Lua" 0083498c),
// createBoundChildItem<bool> 004b60c0 ("disabled" 00834980, scriptsDisabled +0x1ac), createChildItem<int> 005a55a0
// ("threads" 00834978, getThreadCount 005a9120), create<RunService> 004530f0, shared_from 00618a40, addListener 004218a0.
void ScriptContext::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
{
	Notifier<RunService, RunTransition>::disconnect(runService, this);
	Notifier<RunService, Heartbeat>::disconnect(runService, this);

	if (oldProvider && !newProvider)
		closeState();

	if (statsItem)
	{
		statsItem->setParent(NULL);
		statsItem.reset();
	}

	RunService* newRunService;

	if (newProvider)
	{
		Stats::StatsService* statsService = newProvider->create<Stats::StatsService>();
		if (statsService)
		{
			statsItem = Creatable<Instance>::create<Stats::Item>("Lua");
			statsItem->setParent(statsService);
			statsItem->createBoundChildItem("disabled", scriptsDisabled);
			statsItem->createChildItem<int>("threads", boost::bind(&ScriptContext::getThreadCount, this));
		}

		newRunService = newProvider->create<RunService>();
	}
	else
	{
		newRunService = NULL;
	}

	runService = shared_from(newRunService);
	Notifier<RunService, RunTransition>::connect(runService, this);
	Notifier<RunService, Heartbeat>::connect(runService, this);
}

// 005abf90 (static pushArguments of the donor; bound by executeInNewThread 005b0480 through function_obj vtable
// 008345ac): checked vector iteration calling LuaArguments::push 005aba50 per value, summing the pushed counts.
static size_t pushArguments(const Reflection::ValueCollection& arguments, lua_State* thread)
{
	size_t result = 0;
	for (Reflection::ValueCollection::const_iterator it = arguments.begin(), end = arguments.end(); it != end; ++it)
		result += Lua::LuaArguments2008::push(*it, thread);

	return result;
}

// readResults of the donor is the existing native body 005ad6d0 (Inferred_005ad6d0.cpp, placeholder name
// sub_005ad6d0, bound through function_obj vtable 008345b4); referenced here rather than duplicated.
namespace RBX
{
	void sub_005ad6d0(std::auto_ptr<std::vector<Reflection::Value> >& values, lua_State* L, unsigned int count);
}

// 005b0480: auto_ptr result cleared first (005b04a9), readResults bound with boost::ref(result) constructed before the
// pushArguments bind (right-to-left argument order), then executeInNewThread(..., closures) 005af940.
std::auto_ptr<Reflection::ValueCollection> ScriptContext::executeInNewThread(Security::Identities identity, const char* script, const char* name, const Reflection::ValueCollection& arguments)
{
	std::auto_ptr<Reflection::ValueCollection> result;
	executeInNewThread(
		identity,
		script,
		name,
		boost::bind(&pushArguments, boost::cref(arguments), _1),
		boost::bind(&sub_005ad6d0, boost::ref(result), _1, _2)
	);
	return result;
}

// INFERRED: 005b03b0 binds two trivial free functions, identical-code folded in the client: readResults 0047d410
// (a bare ret, void(lua_State*, size_t), function_obj vtable 00834564) and pushArguments 00416690 (xor eax,eax; ret:
// size_t(lua_State*) returning 0, function_obj vtable 0083456c). The names are not in the client.
static size_t pushNoArguments(lua_State*)
{
	return 0;
}

static void readNoResults(lua_State*, size_t)
{
}

// 005b03b0
void ScriptContext::executeInNewThread(Security::Identities identity, const char* script, const char* name)
{
	executeInNewThread(identity, script, name, boost::bind(&pushNoArguments, _1), boost::bind(&readNoResults, _1, _2));
}

// 005aeb80 (registry placeholder func_005aeb80, 323 B, ret 0x44 = thread + two boost::function closures by
// value). Identity: the donor tools/openrbx ScriptContext.cpp ScriptContext::resume(thread, pushArguments, readResults)
// (lua_gettop 00611c10; PushArgumentsClosure operator() 00595b90; resume(thread, narg) 005ae0d0 compared with Error 2;
// ReadResultsClosure operator() 005aae30 inside try with a catch(...) funclet that pops and rethrows; lua_settop
// 00611c20 with -1 - returnCount). 2008 difference: the error text comes from Lua::LuaArguments(thread, -1) 0061c790
// (script/ScriptContext.h) instead of lua_tostring; then lua_settop(thread, 0) and std::runtime_error 00409d50.
void ScriptContext::resume(lua_State* thread, PushArgumentsClosure pushArguments, ReadResultsClosure readResults)
{
	int top = lua_gettop(thread);

	int narg = pushArguments(thread);

	if (resume(thread, narg) != Error)
	{
		const int returnCount = lua_gettop(thread) - top + 1;

		try
		{
			readResults(thread, returnCount);
		}
		catch (...)
		{
			lua_pop(thread, returnCount);
			throw;
		}

		lua_pop(thread, returnCount);
	}
	else
	{
		std::string err = Lua::LuaArguments(thread, -1);
		lua_settop(thread, 0);
		throw std::runtime_error(err);
	}
}

// 005af940 (registry placeholder func_005af940, 1049 B, ret 0x4c = identity, script, name + two boost::function closures
// by value). Donor tools/rbxgs ScriptContext.cpp executeInNewThread(identity, script, name, pushArguments, readResults):
// openState 005aefa0; CmdLine (3) builds commandLineSandbox (+0x13c, thread at +0x154) from lua_newthread(globalState
// +0x138) 00612f60 via ThreadRef 00593e40 / operator= 00594100 / ~ThreadRef 00594380, sandboxThread 005a8660,
// setThreadIdentity 005aeaf0, lua_settop(-2) 00611c20; "Unable to create ..." through StandardOut print 005693a0 and
// std::runtime_error 00409d50; ScopedPopper(L, 1); "=" + (name or "Script"); luaL_loadbuffer 006114a0; the 2008 error
// text comes from Lua::LuaArguments(newThread, -1) 0061c790 (as in resume 005aeb80); resume(newThread, closures) 005aeb80.
void ScriptContext::executeInNewThread(Security::Identities identity, const char* script, const char* name, PushArgumentsClosure pushArguments, ReadResultsClosure readResults)
{
	openState();

	lua_State* L;
	lua_State* newThread;

	if (identity == Security::CmdLine)
	{
		if (commandLineSandbox.empty())
		{
			{
				Lua::ThreadRef threadRef(lua_newthread(globalState));
				commandLineSandbox = threadRef;
			}

			if (commandLineSandbox.empty())
				throw std::runtime_error("Unable to create trusted sandbox thread");

			sandboxThread(commandLineSandbox.thread());
			setThreadIdentity(commandLineSandbox.thread(), Security::CmdLine);
			lua_pop(globalState, 1);
		}

		L = commandLineSandbox.thread();
		newThread = lua_newthread(L);
	}
	else
	{
		L = globalState;
		newThread = lua_newthread(L);
		sandboxThread(newThread);
		setThreadIdentity(newThread, identity);
	}

	if (!newThread)
	{
		StandardOut::singleton()->print(MESSAGE_ERROR, "ScriptContext::execute: Unable to create a new thread");
		throw std::runtime_error("Unable to create a new thread");
	}

	Lua::ScopedPopper popper(L, 1);

	std::string sName("=");

	if (name)
		sName += name;
	else
		sName += "Script";

	if (luaL_loadbuffer(newThread, script, strlen(script), sName.c_str()))
	{
		std::string err = Lua::LuaArguments(newThread, -1);
		lua_pop(newThread, 1);

		StandardOut::singleton()->print(MESSAGE_ERROR, err.c_str());
		throw std::runtime_error(err);
	}

	resume(newThread, pushArguments, readResults);
}
