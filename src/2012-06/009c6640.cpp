// roc 2012-06 009c6640  unit: CXTPDockingPaneManager  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009c6640
//
// 009c6640  8d41ac               lea eax, [ecx - 0x54]
// 009c6643  c3                   ret 
// copied from an identical function in another client (function ?f@CXTPDockingPaneManager@ns_ROCX0000d5@@QAEHXZ)

namespace ns_ROCX0000d5 {
struct CXTPDockingPaneManager {
    int f();
};

int CXTPDockingPaneManager::f() {
    return (int)(this - 0x54);
}
}
