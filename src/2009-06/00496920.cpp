// from server: 100% by auto
// roc 2009-06 00496920  unit: Ogre::TwoDManager  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00496920
//
// 00496920  6a0c                 push 0xc
// 00496922  e811212800           call 0x718a38
// 00496927  83c404               add esp, 4
// 0049692a  85c0                 test eax, eax
// 0049692c  7402                 je 0x496930
// 0049692e  8900                 mov dword ptr [eax], eax
// 00496930  8d4804               lea ecx, [eax + 4]
// 00496933  85c9                 test ecx, ecx
// 00496935  7402                 je 0x496939
// 00496937  8901                 mov dword ptr [ecx], eax
// 00496939  c3                   ret 
// standard library list<ptr> (function ?_Buynode@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAU_Node@?$_List_nod@PAUT@@V?$allocator@PAUT@@@std@@@2@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
