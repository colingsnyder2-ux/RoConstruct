// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::ScriptContext::addScript 005b06c0 (script/ScriptContext.cpp unit, inactive).
// Identity: decorated name ?addScript@ScriptContext@RBX@@QAEXPAVScript@2@@Z in work/2008-06/identity-registry.json
// (identity-closure); the body calls std::set<Script*>::insert on this+0x15c (scripts; COMDAT-folded with the
// set<PartInstance*> insert 005e8c40), reads Script::disabled at script+0x158, builds shared_from(script) (folded
// 00618a40) and calls startScript 005affa0 (ScriptContextRecovery_005affa0.cpp). Caller: Workspace script
// registration (AppUnit5A0_2008Workspace.cpp context->addScript). Body follows the donor tools/rbxgs
// script/ScriptContext.cpp.
#include "script/ScriptContext.h"
#include "script/Script.h"

using namespace RBX;

// 005b06c0
void ScriptContext::addScript(Script* script)
{
	if (scripts.insert(script).second == true)
	{
		if (!script->isDisabled())
			startScript(shared_from(script));
	}
}
