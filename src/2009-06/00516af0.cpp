// from server: 100% by auto
// roc 2009-06 00516af0  unit: RBX::MeshRefPartAdapter  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00516af0
//
// 00516af0  8b442404             mov eax, dword ptr [esp + 4]
// 00516af4  8b4808               mov ecx, dword ptr [eax + 8]
// 00516af7  80792100             cmp byte ptr [ecx + 0x21], 0
// 00516afb  750e                 jne 0x516b0b
// 00516afd  8d4900               lea ecx, [ecx]
// 00516b00  8bc1                 mov eax, ecx
// 00516b02  8b4808               mov ecx, dword ptr [eax + 8]
// 00516b05  80792100             cmp byte ptr [ecx + 0x21], 0
// 00516b09  74f5                 je 0x516b00
// 00516b0b  c3                   ret 
// standard library set<pod20> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
