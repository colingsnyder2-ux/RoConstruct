// from server: 100% by auto
// roc 2009-06 006d31e0  unit: RBX::Block  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d31e0
//
// 006d31e0  6a20                 push 0x20
// 006d31e2  e851580400           call 0x718a38
// 006d31e7  83c404               add esp, 4
// 006d31ea  85c0                 test eax, eax
// 006d31ec  7406                 je 0x6d31f4
// 006d31ee  c70000000000         mov dword ptr [eax], 0
// 006d31f4  8d4804               lea ecx, [eax + 4]
// 006d31f7  85c9                 test ecx, ecx
// 006d31f9  7406                 je 0x6d3201
// 006d31fb  c70100000000         mov dword ptr [ecx], 0
// 006d3201  8d4808               lea ecx, [eax + 8]
// 006d3204  85c9                 test ecx, ecx
// 006d3206  7406                 je 0x6d320e
// 006d3208  c70100000000         mov dword ptr [ecx], 0
// 006d320e  c6401c01             mov byte ptr [eax + 0x1c], 1
// 006d3212  c6401d00             mov byte ptr [eax + 0x1d], 0
// 006d3216  c3                   ret 
// standard library set<pod16> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
