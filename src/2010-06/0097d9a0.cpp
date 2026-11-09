// from server: 57% by colin
// roc 2010-06 0097d9a0  unit: CSpinButtonCtrl  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0097d9a0

struct CSpinButtonCtrl {
    int f();
};

int CSpinButtonCtrl::f() {
    int x = 0xace900b0;
    return x;
}
