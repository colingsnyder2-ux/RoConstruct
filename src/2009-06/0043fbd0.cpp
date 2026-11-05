// from server: 100% by auto
// roc 2009-06 0043fbd0  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043fbd0
//
// 0043fbd0  8b4110               mov eax, dword ptr [ecx + 0x10]
// 0043fbd3  2b410c               sub eax, dword ptr [ecx + 0xc]
// 0043fbd6  c1f802               sar eax, 2
// 0043fbd9  c3                   ret 
// standard library vector<ptr> (function ?size@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEIXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
