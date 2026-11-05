// from server: 100% by auto
// roc 2012-06 00706630  unit: RBX::RootInstance  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00706630
//
// 00706630  6a20                 push 0x20
// 00706632  e8e3ba2700           call 0x98211a
// 00706637  83c404               add esp, 4
// 0070663a  85c0                 test eax, eax
// 0070663c  7406                 je 0x706644
// 0070663e  c70000000000         mov dword ptr [eax], 0
// 00706644  8d4804               lea ecx, [eax + 4]
// 00706647  85c9                 test ecx, ecx
// 00706649  7406                 je 0x706651
// 0070664b  c70100000000         mov dword ptr [ecx], 0
// 00706651  8d4808               lea ecx, [eax + 8]
// 00706654  85c9                 test ecx, ecx
// 00706656  7406                 je 0x70665e
// 00706658  c70100000000         mov dword ptr [ecx], 0
// 0070665e  c6401c01             mov byte ptr [eax + 0x1c], 1
// 00706662  c6401d00             mov byte ptr [eax + 0x1d], 0
// 00706666  c3                   ret 
// standard library set<pod16> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
