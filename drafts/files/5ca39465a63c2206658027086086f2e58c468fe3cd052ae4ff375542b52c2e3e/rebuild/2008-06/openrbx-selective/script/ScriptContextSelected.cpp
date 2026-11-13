#include "script/ScriptContext.h"

#include "lua/lua.hpp"
#include "reflection/signal.h"
#include "script/LuaArguments.h"
#include "script/LuaAtomicClasses.h"
#include "script/LuaInstanceBridge.h"
#include "script/LuaMemory.h"
#include "script/LuaSignalBridge.h"
#include "script/Script.h"
#include "script/ScriptEvent.h"
#include "security/SecurityContext.h"
#include "util/ContentProvider.h"
#include "util/Name.h"
#include "util/StandardOut.h"
#include "v8datamodel/DebugSettings.h"
#include "v8datamodel/Stats.h"
#include "v8datamodel/Workspace.h"

#include <G3D/System.h>
#include <algorithm>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/signals/connection.hpp>
#include <lualib.h>
#include <stdio.h>

// PORT: selective unit; remaining functions use the 2008 object.
namespace RBX {

void ScriptContext::addScript(Script* script)
{
	if (scripts.insert(script).second == true) {
		if (!script->isDisabled()) {
			startScript(shared_from(script));
		}
	}
}

} // namespace RBX
