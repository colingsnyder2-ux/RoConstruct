// from server: 100% by Yeetserama
// roc 2012-06 004a05a0  unit: CScriptEditor  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a05a0
//
// 004a05a0  56                   push esi
// 004a05a1  e8ea360500           call 0x4f3c90
// 004a05a6  8bf0                 mov esi, eax
// 004a05a8  6a01                 push 1
// 004a05aa  8bce                 mov ecx, esi
// 004a05ac  e87fc4ffff           call 0x49ca30
// 004a05b1  6a01                 push 1
// 004a05b3  50                   push eax
// 004a05b4  8bce                 mov ecx, esi
// 004a05b6  e8a5cfffff           call 0x49d560
// 004a05bb  6a01                 push 1
// 004a05bd  6a01                 push 1
// 004a05bf  40                   inc eax
// 004a05c0  50                   push eax
// 004a05c1  8bce                 mov ecx, esi
// 004a05c3  e868c8ffff           call 0x49ce30
// 004a05c8  85c0                 test eax, eax
// 004a05ca  7c0c                 jl 0x4a05d8
// 004a05cc  6a01                 push 1
// 004a05ce  50                   push eax
// 004a05cf  8bce                 mov ecx, esi
// 004a05d1  e8cac5ffff           call 0x49cba0
// 004a05d6  5e                   pop esi
// 004a05d7  c3                   ret 
// 004a05d8  6a10                 push 0x10
// 004a05da  ff15683bb200         call dword ptr [0xb23b68]
// 004a05e0  5e                   pop esi
// 004a05e1  c3                   ret 
// copied from an identical function in another client (function ?MoveToNextLine@CScriptEditor@ns_ROCX00001a@@QAEXXZ)

namespace ns_ROCX00001a {
// from server: 100% by king_originala
extern "C" int (__stdcall *MessageBeep)(unsigned int);

struct EditorControl {
    int GetCurrentPos(int direct);
    int LineFromPosition(int position, int direct);
    int FindColumn(int line, int column, int direct);
    void GotoPos(int position, int direct);
};

struct CScriptEditor {
    EditorControl* GetControl();
    void MoveToNextLine();
};

void CScriptEditor::MoveToNextLine()
{
    EditorControl* control = GetControl();
    int position = control->GetCurrentPos(1);
    int line = control->LineFromPosition(position, 1);
    position = control->FindColumn(line + 1, 1, 1);
    if (position >= 0)
        control->GotoPos(position, 1);
    else
        MessageBeep(0x10);
}
}
