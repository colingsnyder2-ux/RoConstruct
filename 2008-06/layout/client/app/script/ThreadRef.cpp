// =============================================================================
// ThreadRef.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/script/ThreadRef.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "script/ThreadRef.h"
#include "script/ScriptContext.h"
#include "lua.h"
#include "lauxlib.h"

namespace RBX
{
	namespace Lua
	{
		ThreadRef::ThreadRef(lua_State* thread)
			: sync(syncSingleton),
			  node(NULL),
			  previous(NULL),
			  next(NULL),
			  L(thread),
			  threadId(0)
		{
			boost::mutex::scoped_lock lock(*sync);

			node = Node::get(thread).get();
			addToNode();
			addRef();
		}

		ThreadRef::ThreadRef(const ThreadRef& other)
			: sync(syncSingleton),
			  node(other.node),
			  L(other.L)
		{
			boost::mutex::scoped_lock lock(*sync);

			addRef();
			addToNode();
		}

		ThreadRef::~ThreadRef()
		{
			reset();
		}

		void ThreadRef::reset()
		{
			boost::mutex::scoped_lock lock(*sync);

			removeFromNode();
			removeRef();
		}

		ThreadRef& ThreadRef::operator=(const ThreadRef& other)
		{
			if (L != other.L)
			{
				boost::mutex::scoped_lock lock(*sync);

				removeRef();
				L = other.L;

				if (L)
				{
					lua_pushthread(L);
					threadId = luaL_ref(L, LUA_REGISTRYINDEX);
				}
			}

			if (node != other.node)
			{
				boost::mutex::scoped_lock lock(*sync);

				removeFromNode();

				node = other.node;
				addToNode();
			}

			return *this;
		}

		FunctionRef& FunctionRef::operator=(const FunctionRef& other)
		{
			if (thread() != NULL) {
				luaL_unref(thread(), LUA_REGISTRYINDEX, functionId);
			}

			ThreadRef::operator=(other);

			if (thread() == NULL) {
				functionId = 0;
			}
			else {
				lua_rawgeti(thread(), LUA_REGISTRYINDEX, other.functionId);

				functionId = luaL_ref(thread(), LUA_REGISTRYINDEX);
			}

			return *this;
		}

		ThreadRef::NodePtr ThreadRef::Node::create(lua_State* thread)
		{
			lua_pushlightuserdata(thread, RBX_LUA_GLOBAL_THREADREFNODE);
			ThreadRef::NodePtr* newPtr = NodeBridge::pushNewObject(thread);
			lua_settable(thread, LUA_GLOBALSINDEX);

			*newPtr = ThreadRef::NodePtr(new Node());
			return *newPtr;
		}
	}
}

namespace RBX
{
	namespace Lua
	{
		void lua_pushfunction(lua_State* L, const FunctionRef& function)
		{
			lua_rawgeti(L, LUA_REGISTRYINDEX, function.functionId);
		}
	}
}

namespace RBX
{
	namespace Lua
	{
		void ThreadRef::Node::eraseAllRefs()
		{
			boost::mutex::scoped_lock lock(*sync);

			for (ThreadRef* ref = first; ref; ref = ref->next)
			{
				ref->removeRef();
				ref->node = NULL;
			}

			first = NULL;
		}

		ThreadRef::Node::~Node()
		{
			eraseAllRefs();
		}

		FunctionRef::FunctionRef(const FunctionRef& other)
			: ThreadRef(other)
		{
			if (empty())
			{
				functionId = 0;
			}
			else
			{
				lua_getref(thread(), other.functionId);
				functionId = luaL_ref(thread(), LUA_REGISTRYINDEX);
			}
		}

		ThreadRef::NodePtr ThreadRef::Node::get(lua_State* thread)
		{
			lua_pushlightuserdata(thread, RBX_LUA_GLOBAL_THREADREFNODE);
			lua_gettable(thread, LUA_GLOBALSINDEX);
			ThreadRef::NodePtr& node = NodeBridge::getObject(thread, lua_gettop(thread));
			lua_pop(thread, 1);
			return node;
		}

		FunctionRef::FunctionRef(lua_State* thread, int functionIndex)
			: ThreadRef(thread)
		{
			lua_pushvalue(thread, functionIndex);
			functionId = luaL_ref(thread, LUA_REGISTRYINDEX);
		}

		FunctionRef::~FunctionRef()
		{
			if (functionId && !empty())
				lua_unref(thread(), functionId);
		}
	}
}
