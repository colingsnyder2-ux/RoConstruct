// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0042d3f0 ??$create@VScriptContext@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VScriptContext@RBX@@@boost@@XZ: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "script/ScriptContext.h"
#include "util/Object.h"

template boost::shared_ptr<RBX::ScriptContext> RBX::Creatable<RBX::Instance>::create<RBX::ScriptContext>();
