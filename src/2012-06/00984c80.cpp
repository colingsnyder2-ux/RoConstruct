// roc 2012-06 00984c80  unit: CPatchedControlComboBox  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00984c80
//
// 00984c80  8d41e0               lea eax, [ecx - 0x20]
// 00984c83  c3                   ret 
// copied from an identical function in another client (function ?f@CPatchedControlComboBox@ns_ROCX000031@@QAEHXZ)

namespace ns_ROCX000031 {
struct CPatchedControlComboBox {
    int f();
};

int CPatchedControlComboBox::f() {
    return (int)((char*)this - 0x20);
}
}
