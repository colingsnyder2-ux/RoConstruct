// from server: 100% by Yeetserama
// roc 2011-06 0048d9b0  unit: CScriptEditor  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0048d9b0
//
// 0048d9b0  56                   push esi
// 0048d9b1  e83ad6ffff           call 0x48aff0
// 0048d9b6  8bf0                 mov esi, eax
// 0048d9b8  6a01                 push 1
// 0048d9ba  6a01                 push 1
// 0048d9bc  8bce                 mov ecx, esi
// 0048d9be  e87dc8ffff           call 0x48a240
// 0048d9c3  6a01                 push 1
// 0048d9c5  8bce                 mov ecx, esi
// 0048d9c7  85c0                 test eax, eax
// 0048d9c9  740b                 je 0x48d9d6
// 0048d9cb  6a00                 push 0
// 0048d9cd  6a01                 push 1
// 0048d9cf  e81cc8ffff           call 0x48a1f0
// 0048d9d4  5e                   pop esi
// 0048d9d5  c3                   ret 
// 0048d9d6  6a10                 push 0x10
// 0048d9d8  6a01                 push 1
// 0048d9da  e811c8ffff           call 0x48a1f0
// 0048d9df  5e                   pop esi
// 0048d9e0  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX00001e_00464100@CScriptEditor@ns_ROCX00001e@@QAEXXZ)

namespace ns_ROCX00001e {
// from server: 100% by king_originala
struct Control {
    int query(int, bool);
    void update(int, int, bool);
};

struct CScriptEditor {
    int* control();
    void fn_ROCX00001e_00464100();
};

void CScriptEditor::fn_ROCX00001e_00464100()
{
    Control* p = reinterpret_cast<Control*>(control());
    if (p->query(1, true))
        p->update(1, 0, true);
    else
        p->update(1, 16, true);
}
}
