// from server: 100% by auto
// roc 2007-08 004d8640  unit: RBX::View::MegaTextureProxy  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004d8640
//
// 004d8640  6a24                 push 0x24
// 004d8642  e8af781500           call 0x62fef6
// 004d8647  83c404               add esp, 4
// 004d864a  85c0                 test eax, eax
// 004d864c  7406                 je 0x4d8654
// 004d864e  c70000000000         mov dword ptr [eax], 0
// 004d8654  8d4804               lea ecx, [eax + 4]
// 004d8657  85c9                 test ecx, ecx
// 004d8659  7406                 je 0x4d8661
// 004d865b  c70100000000         mov dword ptr [ecx], 0
// 004d8661  8d4808               lea ecx, [eax + 8]
// 004d8664  85c9                 test ecx, ecx
// 004d8666  7406                 je 0x4d866e
// 004d8668  c70100000000         mov dword ptr [ecx], 0
// 004d866e  c6402001             mov byte ptr [eax + 0x20], 1
// 004d8672  c6402100             mov byte ptr [eax + 0x21], 0
// 004d8676  c3                   ret 
// standard library set<pod20> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
