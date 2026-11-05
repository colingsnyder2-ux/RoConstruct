// from server: 100% by auto
// roc 2010-06 008c7110  unit: RBX::AdornRbxGfx  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008c7110
//
// 008c7110  6a30                 push 0x30
// 008c7112  e88908eeff           call 0x7a79a0
// 008c7117  83c404               add esp, 4
// 008c711a  85c0                 test eax, eax
// 008c711c  7406                 je 0x8c7124
// 008c711e  c70000000000         mov dword ptr [eax], 0
// 008c7124  8d4804               lea ecx, [eax + 4]
// 008c7127  85c9                 test ecx, ecx
// 008c7129  7406                 je 0x8c7131
// 008c712b  c70100000000         mov dword ptr [ecx], 0
// 008c7131  8d4808               lea ecx, [eax + 8]
// 008c7134  85c9                 test ecx, ecx
// 008c7136  7406                 je 0x8c713e
// 008c7138  c70100000000         mov dword ptr [ecx], 0
// 008c713e  c6402c01             mov byte ptr [eax + 0x2c], 1
// 008c7142  c6402d00             mov byte ptr [eax + 0x2d], 0
// 008c7146  c3                   ret 
// standard library set<pod32> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
