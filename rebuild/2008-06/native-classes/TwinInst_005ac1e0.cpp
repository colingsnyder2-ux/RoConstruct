// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 005ac1e0: explicit instantiation of the class the body at 005ac1e0 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include <G3D/Color3.h>
#include "lua/LuaBridge.h"
#include <g3d/color3.h>
#include "reflection/reflection.h"
#include "LuaBridge2008/LuaInstanceBridge2008.h"
#include <boost/any.hpp>
template class RBX::Lua::Bridge<G3D::Color3, true>;
template bool RBX::Lua::Bridge<G3D::Color3, true>::getValue<RBX::Reflection::Value>(lua_State*, size_t, RBX::Reflection::Value&);
template bool RBX::Lua::Bridge<G3D::Color3, true>::getValue<boost::any>(lua_State*, size_t, boost::any&);
template bool RBX::Lua::Bridge<G3D::Color3, true>::getValue<G3D::Color3>(lua_State*, size_t, G3D::Color3&);
