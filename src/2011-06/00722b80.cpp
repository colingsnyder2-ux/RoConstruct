// from server: 100% by auto
// roc 2011-06 00722b80  unit: RBX::P8PVInstance::?$SetImpl  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00722b80
//
// 00722b80  8b442404             mov eax, dword ptr [esp + 4]
// 00722b84  8b08                 mov ecx, dword ptr [eax]
// 00722b86  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 00722b8a  750e                 jne 0x722b9a
// 00722b8c  8d642400             lea esp, [esp]
// 00722b90  8bc1                 mov eax, ecx
// 00722b92  8b08                 mov ecx, dword ptr [eax]
// 00722b94  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 00722b98  74f6                 je 0x722b90
// 00722b9a  c3                   ret 
// standard library set<pod16> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
