// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::Lua::ThreadRef lifetime rows of the script/ThreadRef.cpp unit (application range 00593cb0..00594400,
// inactive): ThreadRef(lua_State*) 00593e40, ThreadRef(const ThreadRef&) 00593f70, reset 00594060, operator= 00594100,
// ~ThreadRef 00594380. Identity: decorated names in work/2008-06/identity-registry.json; vtable 0080ebc8 stored by both
// constructors and the destructor; ThreadRef::syncSingleton 00975c6c (shared_ptr<mutex> copied into +4/+8);
// Node::get 00593cb0 called by ThreadRef(lua_State*); boost::mutex lock/unlock 00594ce0 / 00594d00; lua_pushthread 00612430
// and luaL_ref(L, LUA_REGISTRYINDEX) 006110c0 (addRef). Callers: WaitingThread 00620cd0 (new ThreadRef 0x20),
// the LuaSignalBridge connection copy (+0x30 cachedSlotThread). Layout: the donor script/ThreadRef.h (read-only; vptr +0,
// sync +4, node +0xc, previous +0x10, next +0x14, L +0x18, threadId +0x1c, sizeof 0x20).
// Bodies follow the donor tools/rbxgs script/ThreadRef.cpp.
#include "script/ThreadRef.h"
#include "script/ScriptContext.h"
#include "lua.h"
#include "lauxlib.h"

namespace RBX
{
	namespace Lua
	{
		// 00593e40
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

		// 00593f70
		ThreadRef::ThreadRef(const ThreadRef& other)
			: sync(syncSingleton),
			  node(other.node),
			  L(other.L)
		{
			boost::mutex::scoped_lock lock(*sync);

			addRef();
			addToNode();
		}

		// 00594380
		ThreadRef::~ThreadRef()
		{
			reset();
		}

		// 00594060
		void ThreadRef::reset()
		{
			boost::mutex::scoped_lock lock(*sync);

			removeFromNode();
			removeRef();
		}

		// 00594100
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

		// 005948f0 ?create@Node@ThreadRef@Lua@RBX@@SA?AV?$shared_ptr@VNode@ThreadRef@Lua@RBX@@@boost@@PAUlua_State@@@Z
		// (338 B). Donor script/ThreadRef.cpp body: lua_pushlightuserdata 00612410 (RBX_LUA_GLOBAL_THREADREFNODE 0x4e),
		// NodeBridge::pushNewObject inlined (lua_newuserdata 00612c40 of 8 bytes, getmetatable by className 00949730,
		// lua_setmetatable 006127f0), lua_settable(LUA_GLOBALSINDEX) 00612680, new Node (0xc, sync = syncSingleton
		// 00975c6c) into a temporary shared_ptr (shared_count 00594740) assigned through 004025b0. Called by
		// ScriptContext (005aefa0 / 005affa0).
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
