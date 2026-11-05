// from server: 100% by EspClaude
// roc 2009-06 00464b40  unit: CScriptEditor  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00464b40
//
// 00464b40  56                   push esi
// 00464b41  8bf1                 mov esi, ecx
// 00464b43  e8c0442b00           call 0x719008
// 00464b48  8bce                 mov ecx, esi
// 00464b4a  e8f1d4ffff           call 0x462040
// 00464b4f  837c240800           cmp dword ptr [esp + 8], 0
// 00464b54  8bf0                 mov esi, eax
// 00464b56  7516                 jne 0x464b6e
// 00464b58  6a01                 push 1
// 00464b5a  8bce                 mov ecx, esi
// 00464b5c  e8bfd1ffff           call 0x461d20
// 00464b61  85c0                 test eax, eax
// 00464b63  7409                 je 0x464b6e
// 00464b65  6a01                 push 1
// 00464b67  8bce                 mov ecx, esi
// 00464b69  e882d1ffff           call 0x461cf0
// 00464b6e  5e                   pop esi
// 00464b6f  c20c00               ret 0xc
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
