// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::ScriptContext script bookkeeping rows (inactive): removeScript 005ad030 (with disassociateState
// inlined, as in the target). Shape after the donor tools/rbxgs ScriptContext.cpp; header script/ScriptContext.h.
#include "script/Script.h"
#include "script/ScriptContext.h"
#include "script/ThreadRef.h"
#include "util/StandardOut.h"
#include "v8datamodel/DebugSettings.h"
#include "lobject.h"
#include <algorithm>

using namespace RBX;

// disassociateState (inlined into removeScript 005ad030: ThreadRef node association at Script +0xec)
void ScriptContext::disassociateState(Script* script)
{
	Association<Instance>& assoc = script->assoc;

	if (assoc.contains<Lua::ThreadRef::NodePtr>())
	{
		assoc.get<Lua::ThreadRef::NodePtr>()->eraseAllRefs();
		assoc.remove<Lua::ThreadRef::NodePtr>();
	}
}

// 005ad030
void ScriptContext::removeScript(Script* script)
{
	if (scripts.erase(script))
	{
		disassociateState(script);

		std::vector<boost::shared_ptr<Script> >::iterator it = std::find(pendingScripts.begin(), pendingScripts.end(), shared_from(script));
		if (it != pendingScripts.end())
			pendingScripts.erase(it);
	}
}

// 005ac610 (donor reportError with the 2008 differences: the "%s" error line is printed first; with stack tracing off
// it is printed once more (jump 005ac84f); at most 12 levels, "%s, line %d[ - %s %s]" per level, "   stack end" only
// when the walk ran out of levels before the cap).
void ScriptContext::reportError(lua_State* thread)
{
	lua_Debug ar;

	StandardOut::singleton()->print(MESSAGE_ERROR, "%s", lua_tostring(thread, -1));

	if (DebugSettings::singleton().stackTracingEnabled)
	{
		if (lua_getstack(thread, 0, &ar))
		{
			bool hasStack = false;
			int level = 0;
			while (lua_getstack(thread, level++, &ar))
			{
				if (lua_getinfo(thread, "nSlu", &ar) && ar.currentline >= 0)
				{
					hasStack = true;
					char source[0x40];
					luaO_chunkid(source, ar.source, 0x40);
					if (ar.name)
						StandardOut::singleton()->print(MESSAGE_INFO, "%s, line %d - %s %s", source, ar.currentline, ar.namewhat, ar.name);
					else
						StandardOut::singleton()->print(MESSAGE_INFO, "%s, line %d", source, ar.currentline);
				}
				if (level >= 12)
					break;
			}

			if (hasStack && level < 12)
				StandardOut::singleton()->print(MESSAGE_INFO, "   stack end");
		}
	}
	else
	{
		StandardOut::singleton()->print(MESSAGE_ERROR, "%s", lua_tostring(thread, -1));
	}
}
