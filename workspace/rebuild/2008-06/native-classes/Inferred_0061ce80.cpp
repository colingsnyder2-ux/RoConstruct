// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_0061ce80 (placeholder name for 0061ce80 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include <lua.h>
#include <algorithm>
#include "util/Name.h"
#include "LuaBridge2008/LuaBridge2008.h"

namespace RBX
{
	namespace Lua
	{
		int sub_0061ce80(lua_State* L)
		{
			float v[3];
			int nargs = std::min(3, lua_gettop(L));

			for (int i = 0; i < nargs; i++)
				v[i] = tonumberClamped(L, i + 1);

			for (int i = nargs; i < 3; i++)
				v[i] = 0;

			Vector3Bridge::pushVector3(L, G3D::Vector3(v));
			return 1;
		}
	}
}
