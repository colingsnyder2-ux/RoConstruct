// from server: 100% by Yeetserama
// roc 2010-06 004714f0  unit: CScriptEditor  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004714f0
//
// 004714f0  56                   push esi
// 004714f1  e8fad1ffff           call 0x46e6f0
// 004714f6  8bf0                 mov esi, eax
// 004714f8  6a01                 push 1
// 004714fa  8bce                 mov ecx, esi
// 004714fc  e82fbfffff           call 0x46d430
// 00471501  6a01                 push 1
// 00471503  50                   push eax
// 00471504  8bce                 mov ecx, esi
// 00471506  e815caffff           call 0x46df20
// 0047150b  6a01                 push 1
// 0047150d  6a01                 push 1
// 0047150f  48                   dec eax
// 00471510  50                   push eax
// 00471511  8bce                 mov ecx, esi
// 00471513  e828c3ffff           call 0x46d840
// 00471518  85c0                 test eax, eax
// 0047151a  7c0c                 jl 0x471528
// 0047151c  6a01                 push 1
// 0047151e  50                   push eax
// 0047151f  8bce                 mov ecx, esi
// 00471521  e87ac0ffff           call 0x46d5a0
// 00471526  5e                   pop esi
// 00471527  c3                   ret 
// 00471528  6a10                 push 0x10
// 0047152a  ff15c4bb9e00         call dword ptr [0x9ebbc4]
// 00471530  5e                   pop esi
// 00471531  c3                   ret 
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
