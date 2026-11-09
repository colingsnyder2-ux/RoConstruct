// roc 2009-12 00867970  unit: CXTPDockingPaneManager  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00867970
//
// 00867970  8d41ac               lea eax, [ecx - 0x54]
// 00867973  c3                   ret 
// copied from an identical function in another client (function ?f@CXTPDockingPaneManager@ns_ROCX00007a@@QAEHXZ)

namespace ns_ROCX00007a {
struct CXTPDockingPaneManager {
    int f();
};

int CXTPDockingPaneManager::f() {
    return (int)(this - 0x54);
}
}
