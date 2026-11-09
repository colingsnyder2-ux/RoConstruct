// from server: 100% by auto
// roc 2009-12 0044bc10  unit: CRobloxApp  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0044bc10
//
// 0044bc10  8b442404             mov eax, dword ptr [esp + 4]
// 0044bc14  8b08                 mov ecx, dword ptr [eax]
// 0044bc16  80792500             cmp byte ptr [ecx + 0x25], 0
// 0044bc1a  750e                 jne 0x44bc2a
// 0044bc1c  8d642400             lea esp, [esp]
// 0044bc20  8bc1                 mov eax, ecx
// 0044bc22  8b08                 mov ecx, dword ptr [eax]
// 0044bc24  80792500             cmp byte ptr [ecx + 0x25], 0
// 0044bc28  74f6                 je 0x44bc20
// 0044bc2a  c3                   ret 
// standard library set<pod24> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
