// from server: 100% by auto
// roc 2009-06 004e48f0  unit: CRobloxWnd::UserInputJob  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e48f0
//
// 004e48f0  6a30                 push 0x30
// 004e48f2  e841412300           call 0x718a38
// 004e48f7  83c404               add esp, 4
// 004e48fa  85c0                 test eax, eax
// 004e48fc  7406                 je 0x4e4904
// 004e48fe  c70000000000         mov dword ptr [eax], 0
// 004e4904  8d4804               lea ecx, [eax + 4]
// 004e4907  85c9                 test ecx, ecx
// 004e4909  7406                 je 0x4e4911
// 004e490b  c70100000000         mov dword ptr [ecx], 0
// 004e4911  8d4808               lea ecx, [eax + 8]
// 004e4914  85c9                 test ecx, ecx
// 004e4916  7406                 je 0x4e491e
// 004e4918  c70100000000         mov dword ptr [ecx], 0
// 004e491e  c6402c01             mov byte ptr [eax + 0x2c], 1
// 004e4922  c6402d00             mov byte ptr [eax + 0x2d], 0
// 004e4926  c3                   ret 
// standard library set<pod32> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
