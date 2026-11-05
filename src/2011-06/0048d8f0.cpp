// from server: 100% by Yeetserama
// roc 2011-06 0048d8f0  unit: CScriptEditor  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0048d8f0
//
// 0048d8f0  56                   push esi
// 0048d8f1  e8fad6ffff           call 0x48aff0
// 0048d8f6  8bf0                 mov esi, eax
// 0048d8f8  6a01                 push 1
// 0048d8fa  8bce                 mov ecx, esi
// 0048d8fc  e8ffc3ffff           call 0x489d00
// 0048d901  6a01                 push 1
// 0048d903  50                   push eax
// 0048d904  8bce                 mov ecx, esi
// 0048d906  e825cfffff           call 0x48a830
// 0048d90b  6a01                 push 1
// 0048d90d  6a01                 push 1
// 0048d90f  48                   dec eax
// 0048d910  50                   push eax
// 0048d911  8bce                 mov ecx, esi
// 0048d913  e838c8ffff           call 0x48a150
// 0048d918  85c0                 test eax, eax
// 0048d91a  7c0c                 jl 0x48d928
// 0048d91c  6a01                 push 1
// 0048d91e  50                   push eax
// 0048d91f  8bce                 mov ecx, esi
// 0048d921  e84ac5ffff           call 0x489e70
// 0048d926  5e                   pop esi
// 0048d927  c3                   ret 
// 0048d928  6a10                 push 0x10
// 0048d92a  ff15cc1ba400         call dword ptr [0xa41bcc]
// 0048d930  5e                   pop esi
// 0048d931  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX00001b_00464040@CScriptEditor@ns_ROCX00001b@@QAEXXZ)

namespace ns_ROCX00001b {
// from server: 100% by king_originala
extern "C" int (__stdcall* MessageBeep)(unsigned int);

struct EditorControl
{
    int currentPosition(int direct);
    int lineFromPosition(int position, int direct);
    int previousMarker(int line, int mask, int direct);
    void goToLine(int line, int direct);
};

struct CScriptEditor
{
    EditorControl* control();
    void fn_ROCX00001b_00464040();
};

void CScriptEditor::fn_ROCX00001b_00464040()
{
    EditorControl* editor = control();
    int position = editor->currentPosition(1);
    int line = editor->lineFromPosition(position, 1);
    int marker = editor->previousMarker(line - 1, 1, 1);
    if (marker >= 0)
        editor->goToLine(marker, 1);
    else
        MessageBeep(16);
}
}
