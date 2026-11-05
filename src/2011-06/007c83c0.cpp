// from server: 100% by auto
// roc 2011-06 007c83c0  unit: RBX::AdornBillboarder  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007c83c0
//
// 007c83c0  8b442404             mov eax, dword ptr [esp + 4]
// 007c83c4  8b08                 mov ecx, dword ptr [eax]
// 007c83c6  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 007c83ca  750e                 jne 0x7c83da
// 007c83cc  8d642400             lea esp, [esp]
// 007c83d0  8bc1                 mov eax, ecx
// 007c83d2  8b08                 mov ecx, dword ptr [eax]
// 007c83d4  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 007c83d8  74f6                 je 0x7c83d0
// 007c83da  c3                   ret 
// standard library set<pod48> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod48>
struct E { int v[12]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
