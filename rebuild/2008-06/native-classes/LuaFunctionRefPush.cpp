// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::Lua::lua_pushfunction (script/ThreadRef.cpp, inactive). Flags copied from LuaThreadRef.cpp
// (same compilation unit, application range 00593bb0..00594400).
// Identity: 00593c40 ?lua_pushfunction@Lua@RBX@@YAXPAUlua_State@@ABVFunctionRef@12@@Z (identity-registry.json), between
// ThreadRef::removeRef 00593bb0 / Bridge<NodePtr>::on_index 00593be0 and FunctionRef::removeRef 00593c60; callers in the
// signal/instance bridges (LuaBridge2008Signal.cpp, LuaBridge2008Instance.cpp, Inferred_005aed40.cpp). The body reads
// FunctionRef::functionId at +0x20 (after the 0x20-byte ThreadRef base) and calls lua_rawgeti 00612530 with
// LUA_REGISTRYINDEX (-10000).
#include "script/ThreadRef.h"
#include "lua.h"

namespace RBX {
	namespace Lua {
		// 00593c40
		void lua_pushfunction(lua_State* L, const FunctionRef& function)
		{
			lua_rawgeti(L, LUA_REGISTRYINDEX, function.functionId);
		}
	}
}
