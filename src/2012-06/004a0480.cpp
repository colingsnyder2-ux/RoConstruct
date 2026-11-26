// from server: 100% by Xemicl
// roc 2012-06 004a0480  unit: CScriptEditor  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a0480
//
// 004a0480  56                   push esi
// 004a0481  8bf1                 mov esi, ecx
// 004a0483  e856224e00           call 0x9826de
// 004a0488  8bce                 mov ecx, esi
// 004a048a  e801380500           call 0x4f3c90
// 004a048f  837c240800           cmp dword ptr [esp + 8], 0
// 004a0494  8bf0                 mov esi, eax
// 004a0496  7516                 jne 0x4a04ae
// 004a0498  6a01                 push 1
// 004a049a  8bce                 mov ecx, esi
// 004a049c  e85fd5ffff           call 0x49da00
// 004a04a1  85c0                 test eax, eax
// 004a04a3  7409                 je 0x4a04ae
// 004a04a5  6a01                 push 1
// 004a04a7  8bce                 mov ecx, esi
// 004a04a9  e822d5ffff           call 0x49d9d0
// 004a04ae  5e                   pop esi
// 004a04af  c20c00               ret 0xc
// copied from an identical function in another client (function ?fn_ROCX00007b_00463ed0@CScriptEditor@ns_ROCX00007b@@QAEXIII@Z)

namespace ns_ROCX00007b {
struct Control {
    int fn_ROCX00007b_004610b0(int);
    int fn_ROCX00007b_00461080(int);
};

struct CScriptEditor {
    void fn_ROCX00007b_006a0c68();
    int* fn_ROCX00007b_004613d0();
    void fn_ROCX00007b_00463ed0(unsigned int, unsigned int, unsigned int);
};

void CScriptEditor::fn_ROCX00007b_00463ed0(unsigned int key, unsigned int, unsigned int)
{
    fn_ROCX00007b_006a0c68();
    Control* control = reinterpret_cast<Control*>(fn_ROCX00007b_004613d0());
    if (key == 0 && control->fn_ROCX00007b_004610b0(1))
        control->fn_ROCX00007b_00461080(1);
}
}