// from server: 100% by auto
// roc 2007-08 004a7ad0  unit: RBX::Network::Replicator::ChangePropertyItem  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a7ad0
//
// 004a7ad0  6a10                 push 0x10
// 004a7ad2  e81f841800           call 0x62fef6
// 004a7ad7  83c404               add esp, 4
// 004a7ada  85c0                 test eax, eax
// 004a7adc  7402                 je 0x4a7ae0
// 004a7ade  8900                 mov dword ptr [eax], eax
// 004a7ae0  8d4804               lea ecx, [eax + 4]
// 004a7ae3  85c9                 test ecx, ecx
// 004a7ae5  7402                 je 0x4a7ae9
// 004a7ae7  8901                 mov dword ptr [ecx], eax
// 004a7ae9  c3                   ret 
// standard library list<double> (function ?_Buynode@?$list@NV?$allocator@N@std@@@std@@IAEPAU_Node@?$_List_nod@NV?$allocator@N@std@@@2@XZ)

// stl: list<double>
typedef double E;
#include <list>
template class std::list<E>;
