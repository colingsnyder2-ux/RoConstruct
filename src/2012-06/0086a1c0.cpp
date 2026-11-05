// from server: 100% by auto
// roc 2012-06 0086a1c0  unit: RBX::VDataModel::?$BoundFuncDesc  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0086a1c0
//
// 0086a1c0  6a34                 push 0x34
// 0086a1c2  e8537f1100           call 0x98211a
// 0086a1c7  83c404               add esp, 4
// 0086a1ca  85c0                 test eax, eax
// 0086a1cc  7406                 je 0x86a1d4
// 0086a1ce  c70000000000         mov dword ptr [eax], 0
// 0086a1d4  8d4804               lea ecx, [eax + 4]
// 0086a1d7  85c9                 test ecx, ecx
// 0086a1d9  7406                 je 0x86a1e1
// 0086a1db  c70100000000         mov dword ptr [ecx], 0
// 0086a1e1  8d4808               lea ecx, [eax + 8]
// 0086a1e4  85c9                 test ecx, ecx
// 0086a1e6  7406                 je 0x86a1ee
// 0086a1e8  c70100000000         mov dword ptr [ecx], 0
// 0086a1ee  c6403001             mov byte ptr [eax + 0x30], 1
// 0086a1f2  c6403100             mov byte ptr [eax + 0x31], 0
// 0086a1f6  c3                   ret 
// standard library set<pod36> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
