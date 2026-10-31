// from server: 100% by EspClaude
// roc 2009-06 0042da70  unit: CDeclarationView  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042da70
//
// 0042da70  56                   push esi
// 0042da71  8bf1                 mov esi, ecx
// 0042da73  e810b42e00           call 0x718e88
// 0042da78  68d2000000           push 0xd2
// 0042da7d  8bce                 mov ecx, esi
// 0042da7f  e800bb2e00           call 0x719584
// 0042da84  5e                   pop esi
// 0042da85  c3                   ret 
// copied from an identical function in another client (function ?func@COutputView@ns_ROCX000012@@QAEXXZ)

namespace ns_ROCX000012 {
struct COutputView {
    void sub_6300B8();
    void sub_630670(int);
    void func();
};

void COutputView::func() {
    sub_6300B8();
    sub_630670(0xd2);
}
}