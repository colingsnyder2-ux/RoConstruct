// from server: 100% by auto
// roc 2012-06 007cd1f0  unit: RBX::MegaClusterInstance  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007cd1f0
//
// 007cd1f0  6a18                 push 0x18
// 007cd1f2  e8234f1b00           call 0x98211a
// 007cd1f7  83c404               add esp, 4
// 007cd1fa  85c0                 test eax, eax
// 007cd1fc  7406                 je 0x7cd204
// 007cd1fe  c70000000000         mov dword ptr [eax], 0
// 007cd204  8d4804               lea ecx, [eax + 4]
// 007cd207  85c9                 test ecx, ecx
// 007cd209  7406                 je 0x7cd211
// 007cd20b  c70100000000         mov dword ptr [ecx], 0
// 007cd211  8d4808               lea ecx, [eax + 8]
// 007cd214  85c9                 test ecx, ecx
// 007cd216  7406                 je 0x7cd21e
// 007cd218  c70100000000         mov dword ptr [ecx], 0
// 007cd21e  c6401401             mov byte ptr [eax + 0x14], 1
// 007cd222  c6401500             mov byte ptr [eax + 0x15], 0
// 007cd226  c3                   ret 
// standard library set<pod8> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
