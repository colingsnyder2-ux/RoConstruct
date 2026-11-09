// from server: 100% by auto
// roc 2009-12 007afd10  unit: RBX::Block  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007afd10
//
// 007afd10  6a20                 push 0x20
// 007afd12  e8493b0400           call 0x7f3860
// 007afd17  83c404               add esp, 4
// 007afd1a  85c0                 test eax, eax
// 007afd1c  7406                 je 0x7afd24
// 007afd1e  c70000000000         mov dword ptr [eax], 0
// 007afd24  8d4804               lea ecx, [eax + 4]
// 007afd27  85c9                 test ecx, ecx
// 007afd29  7406                 je 0x7afd31
// 007afd2b  c70100000000         mov dword ptr [ecx], 0
// 007afd31  8d4808               lea ecx, [eax + 8]
// 007afd34  85c9                 test ecx, ecx
// 007afd36  7406                 je 0x7afd3e
// 007afd38  c70100000000         mov dword ptr [ecx], 0
// 007afd3e  c6401c01             mov byte ptr [eax + 0x1c], 1
// 007afd42  c6401d00             mov byte ptr [eax + 0x1d], 0
// 007afd46  c3                   ret 
// standard library set<pod16> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
