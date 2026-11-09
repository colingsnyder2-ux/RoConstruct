// from server: 100% by Yeetserama
// roc 2012-06 004a0720  unit: CScriptEditor  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a0720
//
// 004a0720  56                   push esi
// 004a0721  e86a350500           call 0x4f3c90
// 004a0726  8bf0                 mov esi, eax
// 004a0728  6a01                 push 1
// 004a072a  6a00                 push 0
// 004a072c  8bce                 mov ecx, esi
// 004a072e  e83dc8ffff           call 0x49cf70
// 004a0733  6a01                 push 1
// 004a0735  8bce                 mov ecx, esi
// 004a0737  85c0                 test eax, eax
// 004a0739  740b                 je 0x4a0746
// 004a073b  6a00                 push 0
// 004a073d  6a00                 push 0
// 004a073f  e8dcc7ffff           call 0x49cf20
// 004a0744  5e                   pop esi
// 004a0745  c3                   ret 
// 004a0746  6a20                 push 0x20
// 004a0748  6a00                 push 0
// 004a074a  e8d1c7ffff           call 0x49cf20
// 004a074f  5e                   pop esi
// 004a0750  c3                   ret 
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
