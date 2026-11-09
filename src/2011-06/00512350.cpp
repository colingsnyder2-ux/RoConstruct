// from server: 100% by auto
// roc 2011-06 00512350  unit: RBX::Network::ClientReplicator  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00512350
//
// 00512350  6a0c                 push 0xc
// 00512352  e8077d2f00           call 0x80a05e
// 00512357  83c404               add esp, 4
// 0051235a  85c0                 test eax, eax
// 0051235c  7402                 je 0x512360
// 0051235e  8900                 mov dword ptr [eax], eax
// 00512360  8d4804               lea ecx, [eax + 4]
// 00512363  85c9                 test ecx, ecx
// 00512365  7402                 je 0x512369
// 00512367  8901                 mov dword ptr [ecx], eax
// 00512369  c3                   ret 
// standard library list<ptr> (function ?_Buynode@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAU_Node@?$_List_nod@PAUT@@V?$allocator@PAUT@@@std@@@2@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
