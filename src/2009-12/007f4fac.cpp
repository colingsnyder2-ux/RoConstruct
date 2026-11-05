// roc 2009-12 007f4fac  unit: ActiveDocView  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f4fac
//
// 007f4fac  33c0                 xor eax, eax
// 007f4fae  40                   inc eax
// 007f4faf  c3                   ret 
// copied from an identical function in another client (function ?f@ActiveDocView@ns_ROCX00000c@@QAEHXZ)

namespace ns_ROCX00000c {
struct ActiveDocView {
    int f();
};

int ActiveDocView::f() {
    return 1;
}
}
