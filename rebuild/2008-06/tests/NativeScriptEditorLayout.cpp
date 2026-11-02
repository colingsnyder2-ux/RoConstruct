#include <stddef.h>
#include "CScriptEditor.h"
// Size from CRuntimeClass 0081b208 (0x160) and CreateObject 00465160 (operator new 0x160).
// Base offsets from RTTI class hierarchy (mdisp 0, 0xec, 0xf0, 0x114) and the vtable stores in
// constructor 00465010 / destructor 00465830 (0081b3dc +0, 0081b3d0 +0xec, 0081b3bc +0xf0,
// 0081b3a8 +0x114). Member offsets from the same constructor and destructor.
struct ScriptEditorLayout : CScriptEditor {
    static void check();
};
void ScriptEditorLayout::check()
{
    typedef char Size[sizeof(CScriptEditor) == 0x160 ? 1 : -1];
    typedef char ViewSize[sizeof(Scintilla::CScintillaView) == 0xec ? 1 : -1];
    typedef char CtrlSize[sizeof(Scintilla::CScintillaCtrl) == 0x5c ? 1 : -1];
    typedef char Edit[offsetof(ScriptEditorLayout, m_Edit) == 0x58 ? 1 : -1];
    typedef char PageStart[offsetof(ScriptEditorLayout, m_aPageStart) == 0xb4 ? 1 : -1];
    typedef char Metric[offsetof(ScriptEditorLayout, m_bUsingMetric) == 0xe8 ? 1 : -1];
    typedef char Mutex[offsetof(ScriptEditorLayout, mutex) == 0x138 ? 1 : -1];
    typedef char Frame[offsetof(ScriptEditorLayout, frame) == 0x140 ? 1 : -1];
    typedef char Script[offsetof(ScriptEditorLayout, script) == 0x144 ? 1 : -1];
    typedef char Run[offsetof(ScriptEditorLayout, runService) == 0x14c ? 1 : -1];
    typedef char Loading[offsetof(ScriptEditorLayout, loading) == 0x154 ? 1 : -1];
    typedef char Running[offsetof(ScriptEditorLayout, running) == 0x155 ? 1 : -1];
    typedef char Embedded[offsetof(ScriptEditorLayout, embedded) == 0x156 ? 1 : -1];
    typedef char Font[offsetof(ScriptEditorLayout, font) == 0x158 ? 1 : -1];
}
typedef char ScriptDocSize[sizeof(CScriptDoc) == 0x5c ? 1 : -1];
typedef char PropertyListenerSize[sizeof(RBX::MarshaledListener<RBX::Instance, RBX::PropertyChanged>) == 0x24 ? 1 : -1];
typedef char RunListenerSize[sizeof(RBX::MarshaledListener<RBX::RunService, RBX::RunState>) == 0x24 ? 1 : -1];
