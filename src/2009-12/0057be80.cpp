// from server: 100% by auto
// roc 2009-12 0057be80  unit: RBX::VCylinderMesh::?$FactoryProduct::Creator  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057be80
//
// 0057be80  6a10                 push 0x10
// 0057be82  e8d9792700           call 0x7f3860
// 0057be87  83c404               add esp, 4
// 0057be8a  85c0                 test eax, eax
// 0057be8c  7402                 je 0x57be90
// 0057be8e  8900                 mov dword ptr [eax], eax
// 0057be90  8d4804               lea ecx, [eax + 4]
// 0057be93  85c9                 test ecx, ecx
// 0057be95  7402                 je 0x57be99
// 0057be97  8901                 mov dword ptr [ecx], eax
// 0057be99  c3                   ret 
// standard library list<double> (function ?_Buynode@?$list@NV?$allocator@N@std@@@std@@IAEPAU_Node@?$_List_nod@NV?$allocator@N@std@@@2@XZ)

// stl: list<double>
typedef double E;
#include <list>
template class std::list<E>;
