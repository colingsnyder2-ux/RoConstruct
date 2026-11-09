#include <stddef.h>
#include "CScriptDoc.h"
// Size from CRuntimeClass 0081b1ec (0x5c) and CreateObject 004647b0 (operator new 0x5c); CNullDoc is
// CRuntimeClass 00812410 (0x54 == sizeof(CDocument)). script px/pn stores at +0x54/+0x58 in CreateObject
// 004647b0, pn release at +0x58 in destructor 00464670, +0x54 read by CScriptEditor::OnUpdate 004657f0.
struct ScriptDocLayout : CScriptDoc {
    static void check();
};
void ScriptDocLayout::check()
{
    typedef char Size[sizeof(CScriptDoc) == 0x5c ? 1 : -1];
    typedef char NullDocSize[sizeof(CNullDoc) == 0x54 ? 1 : -1];
    typedef char Script[offsetof(ScriptDocLayout, script) == 0x54 ? 1 : -1];
}
