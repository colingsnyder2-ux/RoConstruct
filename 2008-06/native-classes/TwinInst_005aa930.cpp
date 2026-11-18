// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 005aa930: explicit instantiation of the class the body at 005aa930 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "lua/LuaBridge.h"
#include "v8datamodel/BrickColor.h"
#include "reflection/reflection.h"
#include "LuaBridge2008/LuaInstanceBridge2008.h"
template class RBX::Lua::Bridge<RBX::BrickColor, true>;
template bool RBX::Lua::Bridge<RBX::BrickColor, true>::getValue<RBX::Reflection::Value>(lua_State*, size_t, RBX::Reflection::Value&);
