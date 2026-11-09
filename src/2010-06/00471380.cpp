// from server: 100% by Yeetserama
// roc 2010-06 00471380  unit: CScriptEditor  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00471380
//
// 00471380  56                   push esi
// 00471381  8bf1                 mov esi, ecx
// 00471383  e8e86b3300           call 0x7a7f70
// 00471388  8bce                 mov ecx, esi
// 0047138a  e861d3ffff           call 0x46e6f0
// 0047138f  837c240800           cmp dword ptr [esp + 8], 0
// 00471394  8bf0                 mov esi, eax
// 00471396  7516                 jne 0x4713ae
// 00471398  6a01                 push 1
// 0047139a  8bce                 mov ecx, esi
// 0047139c  e81fd0ffff           call 0x46e3c0
// 004713a1  85c0                 test eax, eax
// 004713a3  7409                 je 0x4713ae
// 004713a5  6a01                 push 1
// 004713a7  8bce                 mov ecx, esi
// 004713a9  e8e2cfffff           call 0x46e390
// 004713ae  5e                   pop esi
// 004713af  c20c00               ret 0xc
// copied from an identical function in another client (function ?fn_ROCX000015_00463ed0@CScriptEditor@ns_ROCX000015@@QAEXIII@Z)

namespace ns_ROCX000015 {
// from server: 100% by king_originala
struct Control {
    int fn_ROCX000015_004610b0(int);
    int fn_ROCX000015_00461080(int);
};

struct CScriptEditor {
    void fn_ROCX000015_006a0c68();
    int* fn_ROCX000015_004613d0();
    void fn_ROCX000015_00463ed0(unsigned int, unsigned int, unsigned int);
};

void CScriptEditor::fn_ROCX000015_00463ed0(unsigned int key, unsigned int, unsigned int)
{
    fn_ROCX000015_006a0c68();
    Control* control = reinterpret_cast<Control*>(fn_ROCX000015_004613d0());
    if (key == 0 && control->fn_ROCX000015_004610b0(1))
        control->fn_ROCX000015_00461080(1);
}
}
