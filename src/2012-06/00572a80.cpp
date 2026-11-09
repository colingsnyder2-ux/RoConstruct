// from server: 100% by auto
// roc 2012-06 00572a80  unit: AsyncResult  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00572a80
//
// 00572a80  6a28                 push 0x28
// 00572a82  e893f64000           call 0x98211a
// 00572a87  83c404               add esp, 4
// 00572a8a  85c0                 test eax, eax
// 00572a8c  7406                 je 0x572a94
// 00572a8e  c70000000000         mov dword ptr [eax], 0
// 00572a94  8d4804               lea ecx, [eax + 4]
// 00572a97  85c9                 test ecx, ecx
// 00572a99  7406                 je 0x572aa1
// 00572a9b  c70100000000         mov dword ptr [ecx], 0
// 00572aa1  8d4808               lea ecx, [eax + 8]
// 00572aa4  85c9                 test ecx, ecx
// 00572aa6  7406                 je 0x572aae
// 00572aa8  c70100000000         mov dword ptr [ecx], 0
// 00572aae  c6402401             mov byte ptr [eax + 0x24], 1
// 00572ab2  c6402500             mov byte ptr [eax + 0x25], 0
// 00572ab6  c3                   ret 
// standard library set<pod24> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
