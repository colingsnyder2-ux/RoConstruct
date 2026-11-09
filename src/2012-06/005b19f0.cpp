// from server: 100% by auto
// roc 2012-06 005b19f0  unit: RBX::Network::ErrorCompPhysicsSender2  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005b19f0
//
// 005b19f0  6a0c                 push 0xc
// 005b19f2  e823073d00           call 0x98211a
// 005b19f7  83c404               add esp, 4
// 005b19fa  85c0                 test eax, eax
// 005b19fc  7402                 je 0x5b1a00
// 005b19fe  8900                 mov dword ptr [eax], eax
// 005b1a00  8d4804               lea ecx, [eax + 4]
// 005b1a03  85c9                 test ecx, ecx
// 005b1a05  7402                 je 0x5b1a09
// 005b1a07  8901                 mov dword ptr [ecx], eax
// 005b1a09  c3                   ret 
// standard library list<ptr> (function ?_Buynode@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAU_Node@?$_List_nod@PAUT@@V?$allocator@PAUT@@@std@@@2@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
