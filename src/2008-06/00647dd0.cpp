// from server: 100% by auto
// roc 2008-06 00647dd0  unit: RBX::Block  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00647dd0
//
// 00647dd0  8b442404             mov eax, dword ptr [esp + 4]
// 00647dd4  8b08                 mov ecx, dword ptr [eax]
// 00647dd6  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 00647dda  750e                 jne 0x647dea
// 00647ddc  8d642400             lea esp, [esp]
// 00647de0  8bc1                 mov eax, ecx
// 00647de2  8b08                 mov ecx, dword ptr [eax]
// 00647de4  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 00647de8  74f6                 je 0x647de0
// 00647dea  c3                   ret 
// standard library set<pod16> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
