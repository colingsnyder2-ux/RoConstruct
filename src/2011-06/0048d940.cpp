// from server: 100% by Yeetserama
// roc 2011-06 0048d940  unit: CScriptEditor  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0048d940
//
// 0048d940  56                   push esi
// 0048d941  e8aad6ffff           call 0x48aff0
// 0048d946  8bf0                 mov esi, eax
// 0048d948  6a01                 push 1
// 0048d94a  6a02                 push 2
// 0048d94c  8bce                 mov ecx, esi
// 0048d94e  e8edc8ffff           call 0x48a240
// 0048d953  6a01                 push 1
// 0048d955  8bce                 mov ecx, esi
// 0048d957  85c0                 test eax, eax
// 0048d959  740b                 je 0x48d966
// 0048d95b  6a00                 push 0
// 0048d95d  6a02                 push 2
// 0048d95f  e88cc8ffff           call 0x48a1f0
// 0048d964  5e                   pop esi
// 0048d965  c3                   ret 
// 0048d966  6a10                 push 0x10
// 0048d968  6a02                 push 2
// 0048d96a  e881c8ffff           call 0x48a1f0
// 0048d96f  5e                   pop esi
// 0048d970  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX00001c_00464090@CScriptEditor@ns_ROCX00001c@@QAEXXZ)

namespace ns_ROCX00001c {
// from server: 100% by king_originala
struct Control {
    int query(int, bool);
    void update(int, int, bool);
};

struct CScriptEditor {
    int* control();
    void fn_ROCX00001c_00464090();
};

void CScriptEditor::fn_ROCX00001c_00464090()
{
    Control* p = reinterpret_cast<Control*>(control());
    if (p->query(2, true))
        p->update(2, 0, true);
    else
        p->update(2, 16, true);
}
}
