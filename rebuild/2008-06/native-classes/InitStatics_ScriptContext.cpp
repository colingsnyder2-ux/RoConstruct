// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 script/ScriptContext.cpp reflection static: dynamic initializer 007f4f50.  Name and arguments from the 2007
// donor script/ScriptContext.cpp; the 2008 initializer pushes "ScriptsDisabled", "State", +0x1ac, 005b06a0, flags 1.
#include "script/ScriptContext.h"
#include "reflection/reflection.h"
namespace RBX {
	Reflection::BoundProp<bool, true> ScriptContext::propScriptsDisabled("ScriptsDisabled", "State", &ScriptContext::scriptsDisabled, &ScriptContext::onChangedScriptEnabled, Reflection::PropertyDescriptor::UI);   // 00976b7c
}
