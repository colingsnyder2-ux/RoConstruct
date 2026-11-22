// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::Lua::Bridge<boost::shared_ptr<RBX::Reflection::DescribedBase>,0> rows of the script/ScriptContext.cpp
// object range (inactive): the typed on_tostring(const shared_ptr<DescribedBase>&, lua_State*) 005a8ec0 and the generic
// lua_CFunction thunks on_index(lua_State*) 005a8a00 and on_tostring(lua_State*) 005a9d40.
// Identity: 005a8a00 and 005a9d40 both read Bridge<shared_ptr<DescribedBase>,0>::className 0095af74 (-> "Object",
// 00821634) for luaL_checkudata 006115b0; 005a8a00 calls luaL_checklstring 006116c0 and the typed ObjectBridge::on_index
// 0061c2c0 (LuaBridge2008Instance.cpp), 005a9d40 calls the typed on_tostring 005a8ec0. The registry names 005a8a00
// ?on_index@?$Bridge@V?$shared_ptr@VDescribedBase@...$0A@@Lua@RBX@@KAHPAUlua_State@@@Z (correct) but names 005a9d40
// Bridge<CoordinateFrame,1>::on_tostring, which is 005a9500 (className 0095b1c8 "CFrame"); see the batch 33 proposals.
// 005a8ec0 is the same body as the placeholder sub_005a8ec0 (Inferred_005a8ec0.cpp) under its real decorated name:
// dynamic_cast<Instance*> (__RTDynamicCast, RTTI 009291fc -> 0092907c), Instance::getName (+0x114) or else
// getDescriptor() (+8) ->name.toString(), lua_pushstring 00612280.
// The shared LuaBridge2008/LuaInstanceBridge2008.h defines this specialization with classDescriptor().name.c_str(),
// which compiles to 156 bytes (target 161), so this unit does not include it (header proposal in batch 33 notes).
#include "lua/LuaBridge.h"
#include "reflection/reflection.h"
#include "v8tree/Instance.h"
#include "lua.h"
#include "lauxlib.h"

namespace RBX
{
	namespace Lua
	{
#ifdef LUA_OBJECT_BRIDGE_HEADER_DECLARES_ON_TOSTRING
		// Blocked (batch 33 verifier): LuaBridge2008/LuaInstanceBridge2008.h still DEFINES this specialization
		// (SharedPtrBridge<DescribedBase>::on_tostring, classDescriptor().name.c_str() shape, 156 B), so an active copy
		// here is a second definition of the same function. This body compiles to the 161-byte 005a8ec0 target, which is
		// already exact as placeholder sub_005a8ec0 in Inferred_005a8ec0.cpp. Enable once that header only declares it.
		// 005a8ec0
		template<>
		int Bridge<boost::shared_ptr<Reflection::DescribedBase>, false>::on_tostring(const boost::shared_ptr<Reflection::DescribedBase>& object, lua_State* L)
		{
			if (Instance* instance = dynamic_cast<Instance*>(object.get()))
			{
				lua_pushstring(L, instance->getName().c_str());
				return 1;
			}
			lua_pushstring(L, object->getDescriptor().name.toString().c_str());
			return 1;
		}

#endif
		// 005a8a00 / 005a9d40 (generic on_index/on_tostring thunks) are already exact in ScriptContextRecovery_005aefa0.cpp
		// through its explicit 'template class Bridge<boost::shared_ptr<Reflection::DescribedBase>, false>;', so they are
		// not instantiated again here (batch 33 verifier: duplicate removed).
	}
}
