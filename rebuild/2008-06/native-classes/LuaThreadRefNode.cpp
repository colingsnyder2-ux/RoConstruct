// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::Lua::ThreadRef::Node and FunctionRef rows of the script/ThreadRef.cpp unit (application range
// 00593cb0..00594570, inactive), beside LuaThreadRef.cpp (same unit, flags copied from it): Node::eraseAllRefs 00594210,
// Node::~Node 00594290, FunctionRef(const FunctionRef&) 005944e0, Node::get 00593cb0, FunctionRef(lua_State*, int)
// 00594400, ~FunctionRef 00594470. Identity: decorated names in
// work/2008-06/identity-registry.json (?eraseAllRefs@Node@ThreadRef@Lua@RBX@@QAEXXZ, ??1Node@ThreadRef@Lua@RBX@@QAE@XZ,
// ??0FunctionRef@Lua@RBX@@QAE@ABV012@@Z); callers ScriptContext::closeState 005ae280 (eraseAllRefs) and the
// LuaSignalBridge slot copy (FunctionRef copy, +0x0c). Layouts: the donor script/ThreadRef.h (Node: first +0, sync +4;
// ThreadRef: node +0xc, next +0x14, L +0x18; FunctionRef: vtable 0080ebd0, functionId +0x20).
// Bodies follow the donor tools/rbxgs script/ThreadRef.cpp.
#include "script/ThreadRef.h"
#include "script/ScriptContext.h"
#include "lua.h"
#include "lauxlib.h"

namespace RBX
{
	namespace Lua
	{
		// 00594210: lock *sync (boost::mutex lock 00594ce0 / unlock 00594d00), for each ref in the node's list call the
		// virtual removeRef (vtable slot 0) and clear ref->node (+0xc), following ref->next (+0x14); then first = NULL.
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

		// 00594290: eraseAllRefs 00594210, then the inlined release of the shared_ptr<mutex> sync (+4/+8).
		ThreadRef::Node::~Node()
		{
			eraseAllRefs();
		}

		// 005944e0: ThreadRef copy 00593f70, FunctionRef vtable 0080ebd0, then functionId = 0 for an empty ref or
		// lua_rawgeti(L, LUA_REGISTRYINDEX, other.functionId) 00612530 + luaL_ref 006110c0.
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

		// 00593cb0 ?get@Node@ThreadRef@Lua@RBX@@SA?AV?$shared_ptr@VNode@ThreadRef@Lua@RBX@@@boost@@PAUlua_State@@@Z
		// (101 B). Donor script/ThreadRef.cpp body: lua_pushlightuserdata 00612410 (RBX_LUA_GLOBAL_THREADREFNODE 0x4e),
		// lua_gettable(LUA_GLOBALSINDEX) 00612460, NodeBridge::getObject inlined as luaL_checkudata 006115b0 at
		// lua_gettop 00611c10 with className 00949730, lua_settop(-2) 00611c20, then the shared_ptr copy (lock xadd).
		// Caller ThreadRef(lua_State*) 00593e40 and ScriptContext::closeState (eraseAllRefs).
		ThreadRef::NodePtr ThreadRef::Node::get(lua_State* thread)
		{
			lua_pushlightuserdata(thread, RBX_LUA_GLOBAL_THREADREFNODE);
			lua_gettable(thread, LUA_GLOBALSINDEX);
			ThreadRef::NodePtr& node = NodeBridge::getObject(thread, lua_gettop(thread));
			lua_pop(thread, 1);
			return node;
		}

		// 00594400 ??0FunctionRef@Lua@RBX@@QAE@PAUlua_State@@H@Z (103 B, ret 8): ThreadRef(lua_State*) 00593e40,
		// FunctionRef vtable 0080ebd0, lua_pushvalue 00611dd0, luaL_ref(L, LUA_REGISTRYINDEX) 006110c0 into +0x20.
		FunctionRef::FunctionRef(lua_State* thread, int functionIndex)
			: ThreadRef(thread)
		{
			lua_pushvalue(thread, functionIndex);
			functionId = luaL_ref(thread, LUA_REGISTRYINDEX);
		}

		// 00594470 ??1FunctionRef@Lua@RBX@@QAE@XZ (103 B): vtable 0080ebd0, luaL_unref(L, LUA_REGISTRYINDEX, functionId)
		// 00611170 when functionId (+0x20) and L (+0x18) are set, then ~ThreadRef 00594380.
		FunctionRef::~FunctionRef()
		{
			if (functionId && !empty())
				lua_unref(thread(), functionId);
		}
	}
}
