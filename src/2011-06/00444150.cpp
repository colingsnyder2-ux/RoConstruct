// from server: 100% by auto
// roc 2011-06 00444150  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00444150
//
// 00444150  8b442404             mov eax, dword ptr [esp + 4]
// 00444154  8b08                 mov ecx, dword ptr [eax]
// 00444156  80792100             cmp byte ptr [ecx + 0x21], 0
// 0044415a  750e                 jne 0x44416a
// 0044415c  8d642400             lea esp, [esp]
// 00444160  8bc1                 mov eax, ecx
// 00444162  8b08                 mov ecx, dword ptr [eax]
// 00444164  80792100             cmp byte ptr [ecx + 0x21], 0
// 00444168  74f6                 je 0x444160
// 0044416a  c3                   ret 
// standard library set<pod20> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
