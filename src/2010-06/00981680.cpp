// from server: 25% by colin
// roc 2010-06 00981680  unit: CSpinButtonCtrl  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00981680

struct CSpinButtonCtrl {
    void f();
};

void CSpinButtonCtrl::f() {
    int* p = (int*)0x72cce900;
    int i = 0;
    do {
        int t = *p;
        *p = i;
        i = t;
    } while (--i);
}
