// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::Lua::LuaArguments2008::get 005ad380 (static; the 2008 shape of donor script/LuaArguments.h get with
// a fourth nilIsMissing argument and a bool result). Statement order follows the byte-exact analog src/2008-06/005ad380.cpp.
#include "LuaBridge2008/LuaArguments2008.h"
#include "LuaBridge2008/LuaInstanceBridge2008.h"
#include "script/LuaAtomicClasses.h"
#include "script/ThreadRef.h"

namespace RBX
{
	namespace Lua
	{
		bool LuaArguments2008::get(lua_State* L, int luaIndex, Reflection::Value& value, bool nested)
		{
			if (luaIndex > lua_gettop(L))
				return false;

			switch (lua_type(L, luaIndex))
			{
			case LUA_TNUMBER:
			{
				double rhs = lua_tonumber(L, luaIndex);
				value = rhs;
				break;
			}
			case LUA_TBOOLEAN:
			{
				bool rhs = lua_toboolean(L, luaIndex) != 0;
				value = rhs;
				break;
			}
			case LUA_TSTRING:
				value = std::string(lua_tostring(L, luaIndex));
				break;
			case LUA_TTABLE:
			{
				const int n = static_cast<const int>(lua_objlen(L, luaIndex));
				value = Reflection::ValueCollection(n);
				int i = 1;
				Reflection::ValueCollection& values = value.cast<Reflection::ValueCollection&>();
				if (n >= 1)
				{
					do
					{
						Reflection::Value& ival = values[i - 1];
						lua_rawgeti(L, luaIndex, i);
						get(L, -1, ival, false);
						lua_pop(L, 1);
						i++;
					} while (i <= n);
				}
				return true;
			}
			case LUA_TNIL:
				if (nested)
					return false;
				value = Reflection::Value();
				break;
			case LUA_TFUNCTION:
				value = lua_tofunction(L, luaIndex);
				break;
			default:
				value = Reflection::Value();
				break;
			case LUA_TUSERDATA:
				if (CoordinateFrameBridge::getValue(L, luaIndex, value)
					|| Vector3Bridge::getValue(L, luaIndex, value)
					|| Color3Bridge::getValue(L, luaIndex, value)
					|| BrickColorBridge::getValue(L, luaIndex, value)
					|| ObjectBridge::getPtr(L, luaIndex, value))
					break;
				value = Reflection::Value();
				break;
			}
			return true;
		}
	}
}
