// from server: 100% by auto
// roc 2010-06 004e0940  unit: G3D::Ray  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004e0940
//
// 004e0940  8b442404             mov eax, dword ptr [esp + 4]
// 004e0944  8b08                 mov ecx, dword ptr [eax]
// 004e0946  80791500             cmp byte ptr [ecx + 0x15], 0
// 004e094a  750e                 jne 0x4e095a
// 004e094c  8d642400             lea esp, [esp]
// 004e0950  8bc1                 mov eax, ecx
// 004e0952  8b08                 mov ecx, dword ptr [eax]
// 004e0954  80791500             cmp byte ptr [ecx + 0x15], 0
// 004e0958  74f6                 je 0x4e0950
// 004e095a  c3                   ret 
// standard library set<pod8> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
