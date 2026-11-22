// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native Lua::Bridge<T, true>::on_eq for the float atomic bridges (inactive): the __eq metamethods of
// CoordinateFrame 005a9580, Vector3 005a96a0 and Color3 005a9940 (registry placeholders func_005a9580 / func_005a96a0
// / func_005a9940). Identity: each sits in its bridge's metamethod run of the ScriptContext unit (on_gc, on_tostring,
// on_newindex, on_index, on_eq: CoordinateFrame 005a94e0..005a9580, Vector3 005a9600..005a96a0, Color3
// 005a98a0..005a9940), reads both operands through getObject (lua_touserdata check against the bridge metatable
// names 0095b1c8 / 0095b1c0 / 0095b1bc, 006115b0), compares member by member and calls lua_pushboolean 006123f0;
// CoordinateFrame adds Matrix3::operator== 00513280 after the translation compare. The body is the header template
// lua/LuaBridge.h on_eq; AppUnit5A8_2008ScriptContext.cpp instantiates the whole classes without /fp:fast and gets
// fucompp where the target has fld/fcomp (the /fp:fast float == form), so only on_eq is instantiated here.
#include "script/ScriptContext.h"
#include "lua/LuaBridge.h"
#include "script/LuaAtomicClasses.h"
#include "LuaBridge2008/LuaBridge2008.h"

namespace RBX
{
	namespace Lua
	{
		template int Bridge<G3D::CoordinateFrame, true>::on_eq(lua_State*);   // 005a9580
		template int Bridge<G3D::Vector3, true>::on_eq(lua_State*);           // 005a96a0
		template int Bridge<G3D::Color3, true>::on_eq(lua_State*);            // 005a9940
	}
}
