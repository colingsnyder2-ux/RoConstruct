// from server: 100% by auto
// roc 2011-06 00718d40  unit: RBX::NotificationBox  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00718d40
//
// 00718d40  6a10                 push 0x10
// 00718d42  e817130f00           call 0x80a05e
// 00718d47  83c404               add esp, 4
// 00718d4a  85c0                 test eax, eax
// 00718d4c  7402                 je 0x718d50
// 00718d4e  8900                 mov dword ptr [eax], eax
// 00718d50  8d4804               lea ecx, [eax + 4]
// 00718d53  85c9                 test ecx, ecx
// 00718d55  7402                 je 0x718d59
// 00718d57  8901                 mov dword ptr [ecx], eax
// 00718d59  c3                   ret 
// standard library list<double> (function ?_Buynode@?$list@NV?$allocator@N@std@@@std@@IAEPAU_Node@?$_List_nod@NV?$allocator@N@std@@@2@XZ)

// stl: list<double>
typedef double E;
#include <list>
template class std::list<E>;
