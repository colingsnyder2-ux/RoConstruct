// from server: 100% by Yeetserama
// roc 2010-06 004714a0  unit: CScriptEditor  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004714a0
//
// 004714a0  56                   push esi
// 004714a1  e84ad2ffff           call 0x46e6f0
// 004714a6  8bf0                 mov esi, eax
// 004714a8  6a01                 push 1
// 004714aa  8bce                 mov ecx, esi
// 004714ac  e87fbfffff           call 0x46d430
// 004714b1  6a01                 push 1
// 004714b3  50                   push eax
// 004714b4  8bce                 mov ecx, esi
// 004714b6  e865caffff           call 0x46df20
// 004714bb  6a01                 push 1
// 004714bd  6a01                 push 1
// 004714bf  40                   inc eax
// 004714c0  50                   push eax
// 004714c1  8bce                 mov ecx, esi
// 004714c3  e828c3ffff           call 0x46d7f0
// 004714c8  85c0                 test eax, eax
// 004714ca  7c0c                 jl 0x4714d8
// 004714cc  6a01                 push 1
// 004714ce  50                   push eax
// 004714cf  8bce                 mov ecx, esi
// 004714d1  e8cac0ffff           call 0x46d5a0
// 004714d6  5e                   pop esi
// 004714d7  c3                   ret 
// 004714d8  6a10                 push 0x10
// 004714da  ff15c4bb9e00         call dword ptr [0x9ebbc4]
// 004714e0  5e                   pop esi
// 004714e1  c3                   ret 
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
