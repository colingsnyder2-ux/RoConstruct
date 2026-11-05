// roc 2009-12 008047a0  unit: CXTPControlComboBoxPopupBar  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008047a0
//
// 008047a0  8d41a4               lea eax, [ecx - 0x5c]
// 008047a3  c3                   ret 
// copied from an identical function in another client (function ?f@CXTPControlComboBoxPopupBar@ns_ROCX000000@@QAEHXZ)

namespace ns_ROCX000000 {
struct CXTPControlComboBoxPopupBar {
    int f();
};

int CXTPControlComboBoxPopupBar::f() {
    return (int)(this - 0x5c);
}
}
