// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include
// INFERRED: sub_005a9a50 (placeholder name for 005a9a50 from the identity tier; body byte-proved by the placeholder lane, includes as the lane resolved them)
#include "util/Name.h"
#include "script/ScriptContext.h"
#include "v8datamodel/BrickColor.h"

extern "C" {


}

namespace RBX {

int sub_005a9a50(lua_State* L)
{
	typedef Lua::Bridge<BrickColor, true> B;
	lua_pushboolean(L, B::getObject(L, 1) == B::getObject(L, 2));
	return 1;
}

}
