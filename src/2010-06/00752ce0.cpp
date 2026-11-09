// from server: 100% by auto
// roc 2010-06 00752ce0  unit: RBX::PrismPoly  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00752ce0
//
// 00752ce0  8b4110               mov eax, dword ptr [ecx + 0x10]
// 00752ce3  2b410c               sub eax, dword ptr [ecx + 0xc]
// 00752ce6  c1f802               sar eax, 2
// 00752ce9  c3                   ret 
// standard library vector<ptr> (function ?size@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEIXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
