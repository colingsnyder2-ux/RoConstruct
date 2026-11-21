// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 005a9c70: explicit instantiation of the class the body at 005a9c70 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "lua/LuaBridge.h"
#include "LuaBridge2008/LuaEnumBridge2008.h"
#include "reflection/reflection.h"
#include "LuaBridge2008/LuaInstanceBridge2008.h"
template class RBX::Lua::Bridge<RBX::Lua::EnumDescriptorItemPtr, true>;
template bool RBX::Lua::Bridge<RBX::Lua::EnumDescriptorItemPtr, true>::getValue<RBX::Reflection::Value>(lua_State*, size_t, RBX::Reflection::Value&);

// LuaArguments::pushTable instances of the ScriptContext / Lua bridge range (decorated names
// ??$pushTable@V?$_Vector_const_iterator@VValue@Reflection@RBX@@...@LuaArguments@Lua@RBX@@SAH... in the identity registry;
// declared on the 2008 analog class LuaArguments2008, see LuaBridge2008/LuaArguments2008.h).
#include "LuaBridge2008/LuaArguments2008.h"
// @005aa000 pushTable<vector<Value>::const_iterator> (200 B)
template int RBX::Lua::LuaArguments2008::pushTable<std::vector<RBX::Reflection::Value>::const_iterator>(
	std::vector<RBX::Reflection::Value>::const_iterator, std::vector<RBX::Reflection::Value>::const_iterator, lua_State* const);
// @005ac2f0 pushTable<vector<shared_ptr<Instance> >::const_iterator> (350 B)
// PARKED (batch 28, 3 hypotheses): builds 356 B. Same calls and block order, but the target keeps the counter i in ebp,
// the any holder in esi across the push call (its delete reads esi, not the Value's memory) and reloads L from its
// argument slot; this body keeps L in ebp, spills i and re-reads the holder from the temporary. Rejected: donor
// `first++` (kept), `++first` (same 356 B), a named `const Value value(*first)` local (367 B; Value instance 303 B).
template int RBX::Lua::LuaArguments2008::pushTable<std::vector<boost::shared_ptr<RBX::Instance> >::const_iterator>(
	std::vector<boost::shared_ptr<RBX::Instance> >::const_iterator, std::vector<boost::shared_ptr<RBX::Instance> >::const_iterator,
	lua_State* const);
