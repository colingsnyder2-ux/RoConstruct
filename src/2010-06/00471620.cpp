// from server: 100% by Yeetserama
// roc 2010-06 00471620  unit: CScriptEditor  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00471620
//
// 00471620  56                   push esi
// 00471621  e8cad0ffff           call 0x46e6f0
// 00471626  8bf0                 mov esi, eax
// 00471628  6a01                 push 1
// 0047162a  6a00                 push 0
// 0047162c  8bce                 mov ecx, esi
// 0047162e  e8fdc2ffff           call 0x46d930
// 00471633  6a01                 push 1
// 00471635  8bce                 mov ecx, esi
// 00471637  85c0                 test eax, eax
// 00471639  740b                 je 0x471646
// 0047163b  6a00                 push 0
// 0047163d  6a00                 push 0
// 0047163f  e89cc2ffff           call 0x46d8e0
// 00471644  5e                   pop esi
// 00471645  c3                   ret 
// 00471646  6a20                 push 0x20
// 00471648  6a00                 push 0
// 0047164a  e891c2ffff           call 0x46d8e0
// 0047164f  5e                   pop esi
// 00471650  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000000_00464170@CScriptEditor@ns_ROCX000000@@QAEXXZ)

namespace ns_ROCX000000 {
// from server: 100% by king_originala
struct Control {
    int query(int, bool);
    void update(int, int, bool);
};

struct CScriptEditor {
    int* control();
    void fn_ROCX000000_00464170();
};

void CScriptEditor::fn_ROCX000000_00464170()
{
    Control* p = reinterpret_cast<Control*>(control());
    if (p->query(0, true))
        p->update(0, 0, true);
    else
        p->update(0, 32, true);
}
}
