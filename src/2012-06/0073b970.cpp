// from server: 100% by auto
// roc 2012-06 0073b970  unit: RBX::VButton::?$FactoryProduct  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0073b970
//
// 0073b970  6a10                 push 0x10
// 0073b972  e8a3672400           call 0x98211a
// 0073b977  83c404               add esp, 4
// 0073b97a  85c0                 test eax, eax
// 0073b97c  7402                 je 0x73b980
// 0073b97e  8900                 mov dword ptr [eax], eax
// 0073b980  8d4804               lea ecx, [eax + 4]
// 0073b983  85c9                 test ecx, ecx
// 0073b985  7402                 je 0x73b989
// 0073b987  8901                 mov dword ptr [ecx], eax
// 0073b989  c3                   ret 
// standard library list<double> (function ?_Buynode@?$list@NV?$allocator@N@std@@@std@@IAEPAU_Node@?$_List_nod@NV?$allocator@N@std@@@2@XZ)

// stl: list<double>
typedef double E;
#include <list>
template class std::list<E>;
