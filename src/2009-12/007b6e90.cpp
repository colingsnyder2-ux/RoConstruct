// from server: 100% by auto
// roc 2009-12 007b6e90  unit: RBX::CleanStage  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007b6e90
//
// 007b6e90  8b4110               mov eax, dword ptr [ecx + 0x10]
// 007b6e93  2b410c               sub eax, dword ptr [ecx + 0xc]
// 007b6e96  c1f802               sar eax, 2
// 007b6e99  c3                   ret 
// standard library vector<ptr> (function ?size@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEIXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
