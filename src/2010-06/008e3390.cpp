// from server: 100% by auto
// roc 2010-06 008e3390  unit: RBX::RbxTextureProxy  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008e3390
//
// 008e3390  6a24                 push 0x24
// 008e3392  e80946ecff           call 0x7a79a0
// 008e3397  83c404               add esp, 4
// 008e339a  85c0                 test eax, eax
// 008e339c  7406                 je 0x8e33a4
// 008e339e  c70000000000         mov dword ptr [eax], 0
// 008e33a4  8d4804               lea ecx, [eax + 4]
// 008e33a7  85c9                 test ecx, ecx
// 008e33a9  7406                 je 0x8e33b1
// 008e33ab  c70100000000         mov dword ptr [ecx], 0
// 008e33b1  8d4808               lea ecx, [eax + 8]
// 008e33b4  85c9                 test ecx, ecx
// 008e33b6  7406                 je 0x8e33be
// 008e33b8  c70100000000         mov dword ptr [ecx], 0
// 008e33be  c6402001             mov byte ptr [eax + 0x20], 1
// 008e33c2  c6402100             mov byte ptr [eax + 0x21], 0
// 008e33c6  c3                   ret 
// standard library set<pod20> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
