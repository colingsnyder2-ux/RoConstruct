// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 0042d3f0: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "script/ScriptContext.h"
#include "boost/shared_ptr.hpp"
#include "util/Name.h"

namespace RBX {

template<>
template<>
boost::shared_ptr<ScriptContext> __cdecl Creatable<Instance>::create<ScriptContext>()
{
	return boost::shared_ptr<ScriptContext>(new ScriptContext, Creatable<Instance>::Deleter());
}

}
