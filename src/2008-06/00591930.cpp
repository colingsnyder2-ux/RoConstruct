// from server: 100% by auto
// roc 2008-06 00591930  unit: RBX::RootInstance  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00591930
//
// 00591930  6a1c                 push 0x1c
// 00591932  e8e9ef1000           call 0x6a0920
// 00591937  83c404               add esp, 4
// 0059193a  85c0                 test eax, eax
// 0059193c  7406                 je 0x591944
// 0059193e  c70000000000         mov dword ptr [eax], 0
// 00591944  8d4804               lea ecx, [eax + 4]
// 00591947  85c9                 test ecx, ecx
// 00591949  7406                 je 0x591951
// 0059194b  c70100000000         mov dword ptr [ecx], 0
// 00591951  8d4808               lea ecx, [eax + 8]
// 00591954  85c9                 test ecx, ecx
// 00591956  7406                 je 0x59195e
// 00591958  c70100000000         mov dword ptr [ecx], 0
// 0059195e  c6401801             mov byte ptr [eax + 0x18], 1
// 00591962  c6401900             mov byte ptr [eax + 0x19], 0
// 00591966  c3                   ret 
// standard library set<pod12> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod12>
struct E { int v[3]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
