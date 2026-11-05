// from server: 100% by auto
// roc 2009-12 0071a450  unit: RBX::VPhysicsService::?$EventDesc  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0071a450
//
// 0071a450  6a14                 push 0x14
// 0071a452  e809940d00           call 0x7f3860
// 0071a457  83c404               add esp, 4
// 0071a45a  85c0                 test eax, eax
// 0071a45c  7406                 je 0x71a464
// 0071a45e  c70000000000         mov dword ptr [eax], 0
// 0071a464  8d4804               lea ecx, [eax + 4]
// 0071a467  85c9                 test ecx, ecx
// 0071a469  7406                 je 0x71a471
// 0071a46b  c70100000000         mov dword ptr [ecx], 0
// 0071a471  8d4808               lea ecx, [eax + 8]
// 0071a474  85c9                 test ecx, ecx
// 0071a476  7406                 je 0x71a47e
// 0071a478  c70100000000         mov dword ptr [ecx], 0
// 0071a47e  c6401001             mov byte ptr [eax + 0x10], 1
// 0071a482  c6401100             mov byte ptr [eax + 0x11], 0
// 0071a486  c3                   ret 
// standard library set<ptr> (function ?_Buynode@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
