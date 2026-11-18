// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
// 005ac560: explicit instantiation of the class the body at 005ac560 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include <boost/shared_ptr.hpp>
#include "lua/LuaBridge.h"
#include "reflection/reflection.h"
#include "LuaBridge2008/LuaInstanceBridge2008.h"
#include <boost/any.hpp>
#include "reflection/Metadata.h"
template class RBX::Lua::Bridge<boost::shared_ptr<RBX::Reflection::DescribedBase>, false>;
template bool RBX::Lua::Bridge<boost::shared_ptr<RBX::Reflection::DescribedBase>, false>::getValue<RBX::Reflection::Value>(lua_State*, size_t, RBX::Reflection::Value&);
template bool RBX::Lua::Bridge<boost::shared_ptr<RBX::Reflection::DescribedBase>, false>::getValue<boost::any>(lua_State*, size_t, boost::any&);
template bool RBX::Lua::Bridge<boost::shared_ptr<RBX::Reflection::DescribedBase>, false>::getValue<boost::shared_ptr<RBX::Reflection::DescribedBase>>(lua_State*, size_t, boost::shared_ptr<RBX::Reflection::DescribedBase>&);
template class RBX::Lua::SharedPtrBridge<RBX::Reflection::DescribedBase>;
template bool RBX::Lua::SharedPtrBridge<RBX::Reflection::DescribedBase>::getPtr<RBX::Reflection::Value>(lua_State*, size_t, RBX::Reflection::Value&);
template bool RBX::Lua::SharedPtrBridge<RBX::Reflection::DescribedBase>::getPtr<boost::any>(lua_State*, size_t, boost::any&);
template bool RBX::Lua::SharedPtrBridge<RBX::Reflection::DescribedBase>::getPtr<boost::shared_ptr<RBX::Reflection::DescribedBase>>(lua_State*, size_t, boost::shared_ptr<RBX::Reflection::DescribedBase>&);
