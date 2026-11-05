// from server: 100% by auto
// roc 2010-06 005e9bf0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005e9bf0
//
// 005e9bf0  6a0c                 push 0xc
// 005e9bf2  e8a9dd1b00           call 0x7a79a0
// 005e9bf7  83c404               add esp, 4
// 005e9bfa  85c0                 test eax, eax
// 005e9bfc  7402                 je 0x5e9c00
// 005e9bfe  8900                 mov dword ptr [eax], eax
// 005e9c00  8d4804               lea ecx, [eax + 4]
// 005e9c03  85c9                 test ecx, ecx
// 005e9c05  7402                 je 0x5e9c09
// 005e9c07  8901                 mov dword ptr [ecx], eax
// 005e9c09  c3                   ret 
// standard library list<ptr> (function ?_Buynode@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAU_Node@?$_List_nod@PAUT@@V?$allocator@PAUT@@@std@@@2@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
