// from server: 100% by auto
// roc 2011-06 007a9830  unit: RBX::ParallelRampPoly  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007a9830
//
// 007a9830  6a20                 push 0x20
// 007a9832  e827080600           call 0x80a05e
// 007a9837  83c404               add esp, 4
// 007a983a  85c0                 test eax, eax
// 007a983c  7406                 je 0x7a9844
// 007a983e  c70000000000         mov dword ptr [eax], 0
// 007a9844  8d4804               lea ecx, [eax + 4]
// 007a9847  85c9                 test ecx, ecx
// 007a9849  7406                 je 0x7a9851
// 007a984b  c70100000000         mov dword ptr [ecx], 0
// 007a9851  8d4808               lea ecx, [eax + 8]
// 007a9854  85c9                 test ecx, ecx
// 007a9856  7406                 je 0x7a985e
// 007a9858  c70100000000         mov dword ptr [ecx], 0
// 007a985e  c6401c01             mov byte ptr [eax + 0x1c], 1
// 007a9862  c6401d00             mov byte ptr [eax + 0x1d], 0
// 007a9866  c3                   ret 
// standard library set<pod16> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
