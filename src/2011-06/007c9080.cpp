// from server: 100% by auto
// roc 2011-06 007c9080  unit: RBX::ChatLine  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007c9080
//
// 007c9080  6a40                 push 0x40
// 007c9082  e8d70f0400           call 0x80a05e
// 007c9087  83c404               add esp, 4
// 007c908a  85c0                 test eax, eax
// 007c908c  7406                 je 0x7c9094
// 007c908e  c70000000000         mov dword ptr [eax], 0
// 007c9094  8d4804               lea ecx, [eax + 4]
// 007c9097  85c9                 test ecx, ecx
// 007c9099  7406                 je 0x7c90a1
// 007c909b  c70100000000         mov dword ptr [ecx], 0
// 007c90a1  8d4808               lea ecx, [eax + 8]
// 007c90a4  85c9                 test ecx, ecx
// 007c90a6  7406                 je 0x7c90ae
// 007c90a8  c70100000000         mov dword ptr [ecx], 0
// 007c90ae  c6403c01             mov byte ptr [eax + 0x3c], 1
// 007c90b2  c6403d00             mov byte ptr [eax + 0x3d], 0
// 007c90b6  c3                   ret 
// standard library set<pod48> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod48>
struct E { int v[12]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
