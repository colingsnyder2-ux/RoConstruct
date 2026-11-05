// from server: 50% by colin
// roc 2010-06 0097dd60  unit: CSpinButtonCtrl  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0097dd60
//
// 0097dd60  26b000               mov al, 0
// 0097dd63  e9ecabe2ff           jmp 0x7a8954

extern "C" void __stdcall sub_7a8954();

struct CSpinButtonCtrl {
    bool f();
};

bool CSpinButtonCtrl::f() {
    sub_7a8954();
    return false;
}
