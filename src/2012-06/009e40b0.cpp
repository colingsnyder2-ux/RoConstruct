// roc 2012-06 009e40b0  unit: CXTPDockingPane  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e40b0
//
// 009e40b0  8d41a8               lea eax, [ecx - 0x58]
// 009e40b3  c3                   ret 
// copied from an identical function in another client (function ?f@CXTPDockingPane@ns_ROCX000018@@QAEHXZ)

namespace ns_ROCX000018 {
struct CXTPDockingPane {
    int f();
};

int CXTPDockingPane::f() {
    return (int)(this - 0x58);
}
}
