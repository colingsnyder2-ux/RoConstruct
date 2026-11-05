// from server: 100% by Yeetserama
// roc 2011-06 0048d780  unit: CScriptEditor  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0048d780
//
// 0048d780  56                   push esi
// 0048d781  8bf1                 mov esi, ecx
// 0048d783  e8a6ce3700           call 0x80a62e
// 0048d788  8bce                 mov ecx, esi
// 0048d78a  e861d8ffff           call 0x48aff0
// 0048d78f  837c240800           cmp dword ptr [esp + 8], 0
// 0048d794  8bf0                 mov esi, eax
// 0048d796  7516                 jne 0x48d7ae
// 0048d798  6a01                 push 1
// 0048d79a  8bce                 mov ecx, esi
// 0048d79c  e82fd5ffff           call 0x48acd0
// 0048d7a1  85c0                 test eax, eax
// 0048d7a3  7409                 je 0x48d7ae
// 0048d7a5  6a01                 push 1
// 0048d7a7  8bce                 mov ecx, esi
// 0048d7a9  e8f2d4ffff           call 0x48aca0
// 0048d7ae  5e                   pop esi
// 0048d7af  c20c00               ret 0xc
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
