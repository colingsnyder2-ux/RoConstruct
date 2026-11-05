// from server: 100% by auto
// roc 2008-06 005d2260  unit: RBX::P8PartInstance::?$GetSetImpl  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d2260
//
// 005d2260  6a0c                 push 0xc
// 005d2262  e8b9e60c00           call 0x6a0920
// 005d2267  83c404               add esp, 4
// 005d226a  85c0                 test eax, eax
// 005d226c  7402                 je 0x5d2270
// 005d226e  8900                 mov dword ptr [eax], eax
// 005d2270  8d4804               lea ecx, [eax + 4]
// 005d2273  85c9                 test ecx, ecx
// 005d2275  7402                 je 0x5d2279
// 005d2277  8901                 mov dword ptr [ecx], eax
// 005d2279  c3                   ret 
// standard library list<ptr> (function ?_Buynode@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAU_Node@?$_List_nod@PAUT@@V?$allocator@PAUT@@@std@@@2@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
