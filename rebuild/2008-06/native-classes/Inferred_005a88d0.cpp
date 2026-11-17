// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_005a88d0 (placeholder name for 005a88d0 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/Name.h"
#include "script/ScriptContext.h"

namespace RBX {

boost::shared_ptr<Instance>& sub_005a88d0(lua_State* L, unsigned int index)
{
	return Lua::Bridge<boost::shared_ptr<Instance>, true>::getObject(L, index);
}

}
