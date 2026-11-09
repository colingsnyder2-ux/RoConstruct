// from server: 100% by auto
// roc 2012-06 0086f890  unit: RBX::VDebrisService::?$BoundFuncDesc  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0086f890
//
// 0086f890  8b442404             mov eax, dword ptr [esp + 4]
// 0086f894  8b08                 mov ecx, dword ptr [eax]
// 0086f896  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 0086f89a  750e                 jne 0x86f8aa
// 0086f89c  8d642400             lea esp, [esp]
// 0086f8a0  8bc1                 mov eax, ecx
// 0086f8a2  8b08                 mov ecx, dword ptr [eax]
// 0086f8a4  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 0086f8a8  74f6                 je 0x86f8a0
// 0086f8aa  c3                   ret 
// standard library set<pod16> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
