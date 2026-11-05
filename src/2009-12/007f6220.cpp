// roc 2009-12 007f6220  unit: CPatchedControlComboBox  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f6220
//
// 007f6220  8d41e0               lea eax, [ecx - 0x20]
// 007f6223  c3                   ret 
// copied from an identical function in another client (function ?f@CPatchedControlComboBox@ns_ROCX000014@@QAEHXZ)

namespace ns_ROCX000014 {
struct CPatchedControlComboBox {
    int f();
};

int CPatchedControlComboBox::f() {
    return (int)((char*)this - 0x20);
}
}
