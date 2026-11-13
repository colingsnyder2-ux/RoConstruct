#include "script/LuaSignalBridge.h"

#include "reflection/property.h"
#include "reflection/signal.h"
#include "script/Script.h"
#include "script/ScriptContext.h"
#include "script/ThreadRef.h"

#include "util/standardout.h"
#include "v8tree/Instance.h"

#include <G3D/format.h>
#include <boost/any.hpp>
#include <lua.h>
#include <stdexcept>
#include <string.h>
#include <string>
#include <typeinfo>
#include <vector>


namespace RBX { namespace Lua {

// PORT: selective unit; remaining functions use the 2008 object.
int SignalConnectionBridge::disconnect(lua_State* L)
{
	getObject(L, 1).disconnect();
	return 0;
}

} } // namespace RBX::Lua
