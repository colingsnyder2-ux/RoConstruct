// from server: 100% by auto
// roc 2008-06 004acb10  unit: RBX::Network::Replicator::ChangePropertyItem  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004acb10
//
// 004acb10  6a10                 push 0x10
// 004acb12  e8093e1f00           call 0x6a0920
// 004acb17  83c404               add esp, 4
// 004acb1a  85c0                 test eax, eax
// 004acb1c  7402                 je 0x4acb20
// 004acb1e  8900                 mov dword ptr [eax], eax
// 004acb20  8d4804               lea ecx, [eax + 4]
// 004acb23  85c9                 test ecx, ecx
// 004acb25  7402                 je 0x4acb29
// 004acb27  8901                 mov dword ptr [ecx], eax
// 004acb29  c3                   ret 
// standard library list<double> (function ?_Buynode@?$list@NV?$allocator@N@std@@@std@@IAEPAU_Node@?$_List_nod@NV?$allocator@N@std@@@2@XZ)

// stl: list<double>
typedef double E;
#include <list>
template class std::list<E>;
