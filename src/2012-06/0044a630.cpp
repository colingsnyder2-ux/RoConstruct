// from server: 100% by Xemicl
// roc 2012-06 0044a630  unit: CDeclarationView  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0044a630
//
// 0044a630  56                   push esi
// 0044a631  8bf1                 mov esi, ecx
// 0044a633  e82c7f5300           call 0x982564
// 0044a638  68d2000000           push 0xd2
// 0044a63d  8bce                 mov ecx, esi
// 0044a63f  e8f8855300           call 0x982c3c
// 0044a644  5e                   pop esi
// 0044a645  c3                   ret 
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