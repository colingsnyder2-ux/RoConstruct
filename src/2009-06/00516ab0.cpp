// from server: 100% by auto
// roc 2009-06 00516ab0  unit: RBX::MeshRefPartAdapter  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00516ab0
//
// 00516ab0  8b442404             mov eax, dword ptr [esp + 4]
// 00516ab4  8b08                 mov ecx, dword ptr [eax]
// 00516ab6  80792100             cmp byte ptr [ecx + 0x21], 0
// 00516aba  750e                 jne 0x516aca
// 00516abc  8d642400             lea esp, [esp]
// 00516ac0  8bc1                 mov eax, ecx
// 00516ac2  8b08                 mov ecx, dword ptr [eax]
// 00516ac4  80792100             cmp byte ptr [ecx + 0x21], 0
// 00516ac8  74f6                 je 0x516ac0
// 00516aca  c3                   ret 
// standard library set<pod20> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
