// from server: 100% by auto
// roc 2008-06 005918f0  unit: RBX::RootInstance  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005918f0
//
// 005918f0  6a34                 push 0x34
// 005918f2  e829f01000           call 0x6a0920
// 005918f7  83c404               add esp, 4
// 005918fa  85c0                 test eax, eax
// 005918fc  7406                 je 0x591904
// 005918fe  c70000000000         mov dword ptr [eax], 0
// 00591904  8d4804               lea ecx, [eax + 4]
// 00591907  85c9                 test ecx, ecx
// 00591909  7406                 je 0x591911
// 0059190b  c70100000000         mov dword ptr [ecx], 0
// 00591911  8d4808               lea ecx, [eax + 8]
// 00591914  85c9                 test ecx, ecx
// 00591916  7406                 je 0x59191e
// 00591918  c70100000000         mov dword ptr [ecx], 0
// 0059191e  c6403001             mov byte ptr [eax + 0x30], 1
// 00591922  c6403100             mov byte ptr [eax + 0x31], 0
// 00591926  c3                   ret 
// standard library set<pod36> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
