// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::Lua::ThreadRef::Node and FunctionRef rows of the script/ThreadRef.cpp unit (application range
// 00593cb0..00594570, inactive), beside LuaThreadRef.cpp (same unit, flags copied from it): Node::eraseAllRefs 00594210,
// Node::~Node 00594290, FunctionRef(const FunctionRef&) 005944e0. Identity: decorated names in
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
	}
}
