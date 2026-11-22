// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 005a9c70: explicit instantiation of the class the body at 005a9c70 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "lua/LuaBridge.h"
#include "LuaBridge2008/LuaEnumBridge2008.h"
#include "reflection/reflection.h"
#include "LuaBridge2008/LuaInstanceBridge2008.h"
template class RBX::Lua::Bridge<RBX::Lua::EnumDescriptorItemPtr, true>;
template bool RBX::Lua::Bridge<RBX::Lua::EnumDescriptorItemPtr, true>::getValue<RBX::Reflection::Value>(lua_State*, size_t, RBX::Reflection::Value&);

// LuaArguments::pushTable instances of the ScriptContext / Lua bridge range. Identity: the registry decorated names
// ??$pushTable@V?$_Vector_const_iterator@VValue@Reflection@RBX@@...@LuaArguments@Lua@RBX@@SAH... (005aa000) and
// ...shared_ptr@VInstance...@LuaArguments@Lua@RBX@@SAH... (005ac2f0) and the RTTI .?AVLuaArguments@Lua@RBX@@ of vtable
// 00844174 name the class RBX::Lua::LuaArguments. The shared LuaBridge2008/LuaArguments2008.h declares the same shape
// under the analog name LuaArguments2008 (the donor script/LuaArguments.h still needs RBX::Instances), so this unit
// declares the class under its RTTI name, member for member as LuaArguments2008 (header proposal: rename the analog).
#include "reflection/function.h"
#include "lua.h"
namespace RBX
{
	namespace Lua
	{
		// INFERRED: unit-local declaration; layout and members copied from LuaBridge2008/LuaArguments2008.h (vtable
		// 00844174: size() 0061a5f0, get(int, Value&) 0061bcb0; offset +0xc, L +0x10).
		class LuaArguments : public Reflection::FunctionDescriptor::Arguments
		{
		private:
			const int offset;
			lua_State* L;

		public:
			LuaArguments(lua_State* L, int offset)
				: offset(offset),
				  L(L)
			{
			}
			virtual size_t size() const;
			virtual void get(int index, Reflection::Value& value) const;

		public:
			static bool get(lua_State* L, int luaIndex, Reflection::Value& value, bool nested); // 005ad380
			static int push(const Reflection::Value& value, lua_State* const L);                // 005aba50

			// Donor script/LuaArguments.h pushTable: lua_createtable 00612570, push 005aba50 per element,
			// lua_rawseti(L, -2, ++i) 00612780, return 1.
			template<typename T>
			static int pushTable(T first, T last, lua_State* const L)
			{
				lua_createtable(L, last - first, 0);

				int i = 0;
				for (; first != last; first++)
				{
					push(*first, L);
					lua_rawseti(L, -2, ++i);
				}

				return 1;
			}
		};
	}
}
// @005aa000 pushTable<vector<Value>::const_iterator> (200 B)
template int RBX::Lua::LuaArguments::pushTable<std::vector<RBX::Reflection::Value>::const_iterator>(
	std::vector<RBX::Reflection::Value>::const_iterator, std::vector<RBX::Reflection::Value>::const_iterator, lua_State* const);
// @005ac2f0 pushTable<vector<shared_ptr<Instance> >::const_iterator> (350 B)
// PARKED (batch 28, 3 hypotheses): builds 356 B. Same calls and block order, but the target keeps the counter i in ebp,
// the any holder in esi across the push call (its delete reads esi, not the Value's memory) and reloads L from its
// argument slot; this body keeps L in ebp, spills i and re-reads the holder from the temporary. Rejected: donor
// `first++` (kept), `++first` (same 356 B), a named `const Value value(*first)` local (367 B; Value instance 303 B).
template int RBX::Lua::LuaArguments::pushTable<std::vector<boost::shared_ptr<RBX::Instance> >::const_iterator>(
	std::vector<boost::shared_ptr<RBX::Instance> >::const_iterator, std::vector<boost::shared_ptr<RBX::Instance> >::const_iterator,
	lua_State* const);
