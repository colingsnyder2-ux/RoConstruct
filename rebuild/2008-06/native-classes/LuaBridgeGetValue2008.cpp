// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Inactive 2008-06 native recovery: Bridge<T, true>::getValue<Reflection::Value> (lua userdata -> Value).
// 005ac0d0: T = G3D::CoordinateFrame (callee 584750 assigns the frame into Value). Body shape follows the
// header lua/LuaBridge.h getValue, but reads the userdata as T and assigns into the Value (2008 template shape).
#include "LuaBridge2008/LuaBridge2008.h"
#include "G3D/CoordinateFrame.h"
#include "v8datamodel/Value.h"

namespace RBX {
namespace Lua {

// 005ac0d0 (registry: getValue<Value> for Bridge<CoordinateFrame, true>)
template<>
template<>
bool Bridge<G3D::CoordinateFrame, true>::getValue<Reflection::Value>(lua_State* L, size_t index, Reflection::Value& value)
{
	const G3D::CoordinateFrame* object = static_cast<const G3D::CoordinateFrame*>(lua_touserdata(L, static_cast<int>(index)));
	if (object)
	{
		if (lua_getmetatable(L, static_cast<int>(index)))
		{
			luaL_getmetatable(L, className);
			if (lua_rawequal(L, -1, -2))
			{
				lua_pop(L, 2);
				value = *object;
				return true;
			}
		}
		else
		{
			lua_pop(L, 1);
		}
	}

	return false;
}

}
}
