// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native rows at the head of the script/ThreadRef.cpp unit (application range 00593bb0..00593cb0, inactive):
// ThreadRef::removeRef 00593bb0, NodeBridge::on_index(const NodePtr&, const char*, lua_State*) 00593be0 and
// FunctionRef::removeRef 00593c60. They sit directly before Node::get 00593cb0 (LuaThreadRefNode.cpp / LuaThreadRef.cpp),
// so the linker kept them with the same object. Identity: decorated names ?removeRef@ThreadRef@Lua@RBX@@MAEXXZ,
// ?on_index@?$Bridge@V?$shared_ptr@VNode@ThreadRef@Lua@RBX@@@boost@@$00@Lua@RBX@@KAHABV?$shared_ptr@VNode@ThreadRef@Lua@RBX@@@boost@@PBDPAUlua_State@@@Z
// and ?removeRef@FunctionRef@Lua@RBX@@MAEXXZ in work/2008-06/identity-registry.json; the generic
// Bridge<NodePtr,1>::on_index(lua_State*) at 005a9870 (className 00949730 = "shared_ptr<ThreadRef::Node>") calls 00593be0;
// both removeRef bodies call luaL_unref(L, LUA_REGISTRYINDEX, ref) 00611170. Layout: script/ThreadRef.h (L +0x18,
// threadId +0x1c, FunctionRef::functionId +0x20). Bodies follow the donor tools/rbxgs script/ThreadRef.cpp.
#include "script/ThreadRef.h"
#include "lua.h"
#include "lauxlib.h"
#include "G3D/format.h"
#include <stdexcept>

namespace RBX
{
	namespace Lua
	{
		// 00593bb0
		void ThreadRef::removeRef()
		{
			if (L)
			{
				lua_unref(L, threadId);
				threadId = 0;
				L = NULL;
			}
		}

		// 00593be0: G3D::format 00509b10, std::runtime_error(const std::string&) 00409d50, _CxxThrowException.
		template<>
		int ThreadRef::NodeBridge::on_index(const ThreadRef::NodePtr& object, const char* name, lua_State* L)
		{
			throw std::runtime_error(G3D::format("%s is not a valid member", name));
		}

		// 00593c60: ThreadRef::removeRef inlined after the function reference is released.
		void FunctionRef::removeRef()
		{
			if (functionId && !empty())
			{
				lua_unref(thread(), functionId);
				functionId = 0;
			}

			ThreadRef::removeRef();
		}
	}
}
