// roc 2012-06 00992fd0  unit: CXTPControlComboBoxPopupBar  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00992fd0
//
// 00992fd0  8d41a4               lea eax, [ecx - 0x5c]
// 00992fd3  c3                   ret 
// copied from an identical function in another client (function ?f@CXTPControlComboBoxPopupBar@ns_ROCX000003@@QAEHXZ)

namespace ns_ROCX000003 {
struct CXTPControlComboBoxPopupBar {
    int f();
};

int CXTPControlComboBoxPopupBar::f() {
    return (int)(this - 0x5c);
}
}
