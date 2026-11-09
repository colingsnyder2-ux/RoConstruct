// from server: 100% by auto
// roc 2010-06 00758f80  unit: RBX::PyramidPoly  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00758f80
//
// 00758f80  6a28                 push 0x28
// 00758f82  e819ea0400           call 0x7a79a0
// 00758f87  83c404               add esp, 4
// 00758f8a  85c0                 test eax, eax
// 00758f8c  7406                 je 0x758f94
// 00758f8e  c70000000000         mov dword ptr [eax], 0
// 00758f94  8d4804               lea ecx, [eax + 4]
// 00758f97  85c9                 test ecx, ecx
// 00758f99  7406                 je 0x758fa1
// 00758f9b  c70100000000         mov dword ptr [ecx], 0
// 00758fa1  8d4808               lea ecx, [eax + 8]
// 00758fa4  85c9                 test ecx, ecx
// 00758fa6  7406                 je 0x758fae
// 00758fa8  c70100000000         mov dword ptr [ecx], 0
// 00758fae  c6402401             mov byte ptr [eax + 0x24], 1
// 00758fb2  c6402500             mov byte ptr [eax + 0x25], 0
// 00758fb6  c3                   ret 
// standard library set<pod24> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
