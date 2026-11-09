// from server: 100% by auto
// roc 2007-08 00438e90  unit: CXTPPropertyGridItem  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00438e90
//
// 00438e90  8b442404             mov eax, dword ptr [esp + 4]
// 00438e94  8b08                 mov ecx, dword ptr [eax]
// 00438e96  80792100             cmp byte ptr [ecx + 0x21], 0
// 00438e9a  750e                 jne 0x438eaa
// 00438e9c  8d642400             lea esp, [esp]
// 00438ea0  8bc1                 mov eax, ecx
// 00438ea2  8b08                 mov ecx, dword ptr [eax]
// 00438ea4  80792100             cmp byte ptr [ecx + 0x21], 0
// 00438ea8  74f6                 je 0x438ea0
// 00438eaa  c3                   ret 
// standard library set<pod20> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
