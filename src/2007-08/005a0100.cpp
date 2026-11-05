// from server: 100% by auto
// roc 2007-08 005a0100  unit: RBX::P8ModelInstance::?$GetSetImpl  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005a0100
//
// 005a0100  6a0c                 push 0xc
// 005a0102  e8effd0800           call 0x62fef6
// 005a0107  83c404               add esp, 4
// 005a010a  85c0                 test eax, eax
// 005a010c  7402                 je 0x5a0110
// 005a010e  8900                 mov dword ptr [eax], eax
// 005a0110  8d4804               lea ecx, [eax + 4]
// 005a0113  85c9                 test ecx, ecx
// 005a0115  7402                 je 0x5a0119
// 005a0117  8901                 mov dword ptr [ecx], eax
// 005a0119  c3                   ret 
// standard library list<ptr> (function ?_Buynode@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAU_Node@?$_List_nod@PAUT@@V?$allocator@PAUT@@@std@@@2@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
