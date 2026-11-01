// from server: 100% by auto
// roc 2009-12 007c21f0  unit: RBX::ImageButton  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c21f0
//
// 007c21f0  6a50                 push 0x50
// 007c21f2  e869160300           call 0x7f3860
// 007c21f7  83c404               add esp, 4
// 007c21fa  85c0                 test eax, eax
// 007c21fc  7406                 je 0x7c2204
// 007c21fe  c70000000000         mov dword ptr [eax], 0
// 007c2204  8d4804               lea ecx, [eax + 4]
// 007c2207  85c9                 test ecx, ecx
// 007c2209  7406                 je 0x7c2211
// 007c220b  c70100000000         mov dword ptr [ecx], 0
// 007c2211  8d4808               lea ecx, [eax + 8]
// 007c2214  85c9                 test ecx, ecx
// 007c2216  7406                 je 0x7c221e
// 007c2218  c70100000000         mov dword ptr [ecx], 0
// 007c221e  c6404c01             mov byte ptr [eax + 0x4c], 1
// 007c2222  c6404d00             mov byte ptr [eax + 0x4d], 0
// 007c2226  c3                   ret 
// standard library set<pod64> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod64>
struct E { int v[16]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
