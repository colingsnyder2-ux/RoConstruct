// from server: 100% by Yeetserama
// roc 2012-06 004a06b0  unit: CScriptEditor  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a06b0
//
// 004a06b0  56                   push esi
// 004a06b1  e8da350500           call 0x4f3c90
// 004a06b6  8bf0                 mov esi, eax
// 004a06b8  6a01                 push 1
// 004a06ba  6a01                 push 1
// 004a06bc  8bce                 mov ecx, esi
// 004a06be  e8adc8ffff           call 0x49cf70
// 004a06c3  6a01                 push 1
// 004a06c5  8bce                 mov ecx, esi
// 004a06c7  85c0                 test eax, eax
// 004a06c9  740b                 je 0x4a06d6
// 004a06cb  6a00                 push 0
// 004a06cd  6a01                 push 1
// 004a06cf  e84cc8ffff           call 0x49cf20
// 004a06d4  5e                   pop esi
// 004a06d5  c3                   ret 
// 004a06d6  6a10                 push 0x10
// 004a06d8  6a01                 push 1
// 004a06da  e841c8ffff           call 0x49cf20
// 004a06df  5e                   pop esi
// 004a06e0  c3                   ret 
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
