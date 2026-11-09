// from server: 100% by auto
// roc 2007-08 005a93b0  unit: RBX::VHumanoid::?$SignalDesc  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005a93b0
//
// 005a93b0  6a14                 push 0x14
// 005a93b2  e83f6b0800           call 0x62fef6
// 005a93b7  83c404               add esp, 4
// 005a93ba  85c0                 test eax, eax
// 005a93bc  7406                 je 0x5a93c4
// 005a93be  c70000000000         mov dword ptr [eax], 0
// 005a93c4  8d4804               lea ecx, [eax + 4]
// 005a93c7  85c9                 test ecx, ecx
// 005a93c9  7406                 je 0x5a93d1
// 005a93cb  c70100000000         mov dword ptr [ecx], 0
// 005a93d1  8d4808               lea ecx, [eax + 8]
// 005a93d4  85c9                 test ecx, ecx
// 005a93d6  7406                 je 0x5a93de
// 005a93d8  c70100000000         mov dword ptr [ecx], 0
// 005a93de  c6401001             mov byte ptr [eax + 0x10], 1
// 005a93e2  c6401100             mov byte ptr [eax + 0x11], 0
// 005a93e6  c3                   ret 
// standard library set<ptr> (function ?_Buynode@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
