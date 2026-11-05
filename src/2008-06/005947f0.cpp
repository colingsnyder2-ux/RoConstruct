// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_nativefunctionrefconvertc8dd1859e965d579.cpp

// Candidate translation unit (score above; library headers required).
#define NDEBUG 1
#define _CPPUNWIND 1
#undef _DEBUG
#include <stdexcept>
#include "reflection/type.h"
#include "script/ThreadRef.h"
namespace RBX { namespace Reflection {
template<> Lua::FunctionRef& Value::convert<Lua::FunctionRef>() {
 if(isType<void>()) {value=Lua::FunctionRef();_type=&Type::singleton<Lua::FunctionRef>();}
 Lua::FunctionRef* result=boost::any_cast<Lua::FunctionRef>(&value);
 if(!result)throw std::runtime_error("Unable to cast value to RBX::Lua::FunctionRef");
 return *result;
}
}}
