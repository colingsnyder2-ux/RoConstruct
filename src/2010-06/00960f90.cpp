// from server: 100% by auto
// roc 2010-06 00960f90  unit: RBX::SphereBuilder  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00960f90
//
// 00960f90  6a10                 push 0x10
// 00960f92  e8096ae4ff           call 0x7a79a0
// 00960f97  83c404               add esp, 4
// 00960f9a  85c0                 test eax, eax
// 00960f9c  7402                 je 0x960fa0
// 00960f9e  8900                 mov dword ptr [eax], eax
// 00960fa0  8d4804               lea ecx, [eax + 4]
// 00960fa3  85c9                 test ecx, ecx
// 00960fa5  7402                 je 0x960fa9
// 00960fa7  8901                 mov dword ptr [ecx], eax
// 00960fa9  c3                   ret 
// standard library list<double> (function ?_Buynode@?$list@NV?$allocator@N@std@@@std@@IAEPAU_Node@?$_List_nod@NV?$allocator@N@std@@@2@XZ)

// stl: list<double>
typedef double E;
#include <list>
template class std::list<E>;
