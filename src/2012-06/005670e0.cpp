// from server: 100% by auto
// roc 2012-06 005670e0  unit: RBX::Network::GuidRegistryService  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005670e0
//
// 005670e0  6a1c                 push 0x1c
// 005670e2  e833b04100           call 0x98211a
// 005670e7  83c404               add esp, 4
// 005670ea  85c0                 test eax, eax
// 005670ec  7406                 je 0x5670f4
// 005670ee  c70000000000         mov dword ptr [eax], 0
// 005670f4  8d4804               lea ecx, [eax + 4]
// 005670f7  85c9                 test ecx, ecx
// 005670f9  7406                 je 0x567101
// 005670fb  c70100000000         mov dword ptr [ecx], 0
// 00567101  8d4808               lea ecx, [eax + 8]
// 00567104  85c9                 test ecx, ecx
// 00567106  7406                 je 0x56710e
// 00567108  c70100000000         mov dword ptr [ecx], 0
// 0056710e  c6401801             mov byte ptr [eax + 0x18], 1
// 00567112  c6401900             mov byte ptr [eax + 0x19], 0
// 00567116  c3                   ret 
// standard library set<pod12> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod12>
struct E { int v[3]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
