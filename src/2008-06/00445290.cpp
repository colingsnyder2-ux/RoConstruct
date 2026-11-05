// from server: 100% by auto
// roc 2008-06 00445290  unit: 1RBX::Metadata::VReflection::?$FactoryProduct  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00445290
//
// 00445290  8b4110               mov eax, dword ptr [ecx + 0x10]
// 00445293  2b410c               sub eax, dword ptr [ecx + 0xc]
// 00445296  c1f802               sar eax, 2
// 00445299  c3                   ret 
// standard library vector<ptr> (function ?size@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEIXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
