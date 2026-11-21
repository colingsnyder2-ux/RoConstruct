// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 005aed40: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "script/ScriptContext.h"
#include "util/Name.h"

namespace RBX {

void ScriptContext::call(const Lua::FunctionRef& f, boost::function1<unsigned int, lua_State*, std::allocator<boost::function_base> > pushArguments, boost::function2<void, lua_State*, unsigned int, std::allocator<boost::function_base> > readResults)
{
	if (f.empty())
		throw std::runtime_error("Cannot call a nil function");
	Lua::lua_pushfunction(f.thread(), f);
	resume(f.thread(), pushArguments, readResults);
}

}
