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
