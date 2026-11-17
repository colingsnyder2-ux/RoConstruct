// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include
// 005947f0: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "reflection/type.h"
#include "luafunction-threadref/script/ThreadRef.h"

namespace RBX { namespace Reflection {

template<>
Lua::FunctionRef& Value::convert<Lua::FunctionRef>()
{
	if (isType<void>())
	{
		value = Lua::FunctionRef();
		_type = &Type::singleton<Lua::FunctionRef>();
	}
	Lua::FunctionRef* result = boost::any_cast<Lua::FunctionRef>(&value);
	if (!result)
		throw std::runtime_error("Unable to cast value to RBX::Lua::FunctionRef");
	return *result;
}

}}
