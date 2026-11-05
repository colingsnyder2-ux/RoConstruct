// from server: 100% by Yeetserama
// roc 2011-06 0048d8a0  unit: CScriptEditor  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0048d8a0
//
// 0048d8a0  56                   push esi
// 0048d8a1  e84ad7ffff           call 0x48aff0
// 0048d8a6  8bf0                 mov esi, eax
// 0048d8a8  6a01                 push 1
// 0048d8aa  8bce                 mov ecx, esi
// 0048d8ac  e84fc4ffff           call 0x489d00
// 0048d8b1  6a01                 push 1
// 0048d8b3  50                   push eax
// 0048d8b4  8bce                 mov ecx, esi
// 0048d8b6  e875cfffff           call 0x48a830
// 0048d8bb  6a01                 push 1
// 0048d8bd  6a01                 push 1
// 0048d8bf  40                   inc eax
// 0048d8c0  50                   push eax
// 0048d8c1  8bce                 mov ecx, esi
// 0048d8c3  e838c8ffff           call 0x48a100
// 0048d8c8  85c0                 test eax, eax
// 0048d8ca  7c0c                 jl 0x48d8d8
// 0048d8cc  6a01                 push 1
// 0048d8ce  50                   push eax
// 0048d8cf  8bce                 mov ecx, esi
// 0048d8d1  e89ac5ffff           call 0x489e70
// 0048d8d6  5e                   pop esi
// 0048d8d7  c3                   ret 
// 0048d8d8  6a10                 push 0x10
// 0048d8da  ff15cc1ba400         call dword ptr [0xa41bcc]
// 0048d8e0  5e                   pop esi
// 0048d8e1  c3                   ret 
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
