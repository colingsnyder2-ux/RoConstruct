// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// boost::any::holder<Lua::FunctionRef> (inactive): the holder a Reflection::Value of a Lua function keeps. Flags line
// and the ThreadRef header path copied from the FunctionRef sibling ReflectionTypeSingletonLeftovers.cpp.
// Identity: vftable 00832278 (.?AV?$holder@VFunctionRef@Lua@RBX@@@any@boost@@) slot 0 is the scalar deleting
// destructor 005946e0 (registry ??_G?$holder@VFunctionRef@Lua@RBX@@@any@boost@@UAEPAXI@Z), which runs
// ~FunctionRef 00594470 on the held value at +4 and restores the placeholder vftable 0080ba1c.
#include <boost/any.hpp>
#include "luafunction-threadref/script/ThreadRef.h"

// 005946e0 (with the other holder members)
template class boost::any::holder<RBX::Lua::FunctionRef>;
