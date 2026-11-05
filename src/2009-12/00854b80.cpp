// roc 2009-12 00854b80  unit: CXTPDockingPane  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00854b80
//
// 00854b80  8d41a8               lea eax, [ecx - 0x58]
// 00854b83  c3                   ret 
// copied from an identical function in another client (function ?f@CXTPDockingPane@ns_ROCX000006@@QAEHXZ)

namespace ns_ROCX000006 {
struct CXTPDockingPane {
    int f();
};

int CXTPDockingPane::f() {
    return (int)(this - 0x58);
}
}
