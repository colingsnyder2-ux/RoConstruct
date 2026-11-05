// from server: 100% by auto
// roc 2007-08 005696e0  unit: RBX::ModelInstance  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005696e0
//
// 005696e0  6a34                 push 0x34
// 005696e2  e80f680c00           call 0x62fef6
// 005696e7  83c404               add esp, 4
// 005696ea  85c0                 test eax, eax
// 005696ec  7406                 je 0x5696f4
// 005696ee  c70000000000         mov dword ptr [eax], 0
// 005696f4  8d4804               lea ecx, [eax + 4]
// 005696f7  85c9                 test ecx, ecx
// 005696f9  7406                 je 0x569701
// 005696fb  c70100000000         mov dword ptr [ecx], 0
// 00569701  8d4808               lea ecx, [eax + 8]
// 00569704  85c9                 test ecx, ecx
// 00569706  7406                 je 0x56970e
// 00569708  c70100000000         mov dword ptr [ecx], 0
// 0056970e  c6403001             mov byte ptr [eax + 0x30], 1
// 00569712  c6403100             mov byte ptr [eax + 0x31], 0
// 00569716  c3                   ret 
// standard library set<pod36> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
