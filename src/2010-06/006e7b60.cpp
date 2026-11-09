// from server: 100% by auto
// roc 2010-06 006e7b60  unit: RBX::P8PVInstance::?$SetImpl  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006e7b60
//
// 006e7b60  6a14                 push 0x14
// 006e7b62  e839fe0b00           call 0x7a79a0
// 006e7b67  83c404               add esp, 4
// 006e7b6a  85c0                 test eax, eax
// 006e7b6c  7406                 je 0x6e7b74
// 006e7b6e  c70000000000         mov dword ptr [eax], 0
// 006e7b74  8d4804               lea ecx, [eax + 4]
// 006e7b77  85c9                 test ecx, ecx
// 006e7b79  7406                 je 0x6e7b81
// 006e7b7b  c70100000000         mov dword ptr [ecx], 0
// 006e7b81  8d4808               lea ecx, [eax + 8]
// 006e7b84  85c9                 test ecx, ecx
// 006e7b86  7406                 je 0x6e7b8e
// 006e7b88  c70100000000         mov dword ptr [ecx], 0
// 006e7b8e  c6401001             mov byte ptr [eax + 0x10], 1
// 006e7b92  c6401100             mov byte ptr [eax + 0x11], 0
// 006e7b96  c3                   ret 
// standard library set<ptr> (function ?_Buynode@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
