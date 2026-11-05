// from server: 100% by auto
// roc 2009-06 00445930  unit: CRobloxApp  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00445930
//
// 00445930  8b442404             mov eax, dword ptr [esp + 4]
// 00445934  8b08                 mov ecx, dword ptr [eax]
// 00445936  80792500             cmp byte ptr [ecx + 0x25], 0
// 0044593a  750e                 jne 0x44594a
// 0044593c  8d642400             lea esp, [esp]
// 00445940  8bc1                 mov eax, ecx
// 00445942  8b08                 mov ecx, dword ptr [eax]
// 00445944  80792500             cmp byte ptr [ecx + 0x25], 0
// 00445948  74f6                 je 0x445940
// 0044594a  c3                   ret 
// standard library set<pod24> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
