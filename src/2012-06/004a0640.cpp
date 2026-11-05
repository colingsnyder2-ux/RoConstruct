// from server: 100% by Yeetserama
// roc 2012-06 004a0640  unit: CScriptEditor  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a0640
//
// 004a0640  56                   push esi
// 004a0641  e84a360500           call 0x4f3c90
// 004a0646  8bf0                 mov esi, eax
// 004a0648  6a01                 push 1
// 004a064a  6a02                 push 2
// 004a064c  8bce                 mov ecx, esi
// 004a064e  e81dc9ffff           call 0x49cf70
// 004a0653  6a01                 push 1
// 004a0655  8bce                 mov ecx, esi
// 004a0657  85c0                 test eax, eax
// 004a0659  740b                 je 0x4a0666
// 004a065b  6a00                 push 0
// 004a065d  6a02                 push 2
// 004a065f  e8bcc8ffff           call 0x49cf20
// 004a0664  5e                   pop esi
// 004a0665  c3                   ret 
// 004a0666  6a10                 push 0x10
// 004a0668  6a02                 push 2
// 004a066a  e8b1c8ffff           call 0x49cf20
// 004a066f  5e                   pop esi
// 004a0670  c3                   ret 
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
