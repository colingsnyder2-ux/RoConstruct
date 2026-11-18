// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 005aade0: explicit instantiation of the class the body at 005aade0 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include <boost/shared_ptr.hpp>
#include "lua/LuaBridge.h"
#include "reflection/reflection.h"
#include "LuaBridge2008/LuaInstanceBridge2008.h"
#include "reflection/Metadata.h"
#include "reflection/signal.h"
template class RBX::Lua::Bridge<boost::shared_ptr<RBX::Reflection::SignalInstance>, false>;
template bool RBX::Lua::Bridge<boost::shared_ptr<RBX::Reflection::SignalInstance>, false>::getValue<RBX::Reflection::Value>(lua_State*, size_t, RBX::Reflection::Value&);
template class RBX::Lua::SharedPtrBridge<RBX::Reflection::SignalInstance>;
template bool RBX::Lua::SharedPtrBridge<RBX::Reflection::SignalInstance>::getPtr<RBX::Reflection::Value>(lua_State*, size_t, RBX::Reflection::Value&);
