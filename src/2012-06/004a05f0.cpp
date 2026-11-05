// from server: 100% by Yeetserama
// roc 2012-06 004a05f0  unit: CScriptEditor  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a05f0
//
// 004a05f0  56                   push esi
// 004a05f1  e89a360500           call 0x4f3c90
// 004a05f6  8bf0                 mov esi, eax
// 004a05f8  6a01                 push 1
// 004a05fa  8bce                 mov ecx, esi
// 004a05fc  e82fc4ffff           call 0x49ca30
// 004a0601  6a01                 push 1
// 004a0603  50                   push eax
// 004a0604  8bce                 mov ecx, esi
// 004a0606  e855cfffff           call 0x49d560
// 004a060b  6a01                 push 1
// 004a060d  6a01                 push 1
// 004a060f  48                   dec eax
// 004a0610  50                   push eax
// 004a0611  8bce                 mov ecx, esi
// 004a0613  e868c8ffff           call 0x49ce80
// 004a0618  85c0                 test eax, eax
// 004a061a  7c0c                 jl 0x4a0628
// 004a061c  6a01                 push 1
// 004a061e  50                   push eax
// 004a061f  8bce                 mov ecx, esi
// 004a0621  e87ac5ffff           call 0x49cba0
// 004a0626  5e                   pop esi
// 004a0627  c3                   ret 
// 004a0628  6a10                 push 0x10
// 004a062a  ff15683bb200         call dword ptr [0xb23b68]
// 004a0630  5e                   pop esi
// 004a0631  c3                   ret 
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
