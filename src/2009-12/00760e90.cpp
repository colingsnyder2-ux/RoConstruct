// from server: 100% by auto
// roc 2009-12 00760e90  unit: RBX::P8PVInstance::?$SetImpl  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00760e90
//
// 00760e90  8b442404             mov eax, dword ptr [esp + 4]
// 00760e94  8b08                 mov ecx, dword ptr [eax]
// 00760e96  80793100             cmp byte ptr [ecx + 0x31], 0
// 00760e9a  750e                 jne 0x760eaa
// 00760e9c  8d642400             lea esp, [esp]
// 00760ea0  8bc1                 mov eax, ecx
// 00760ea2  8b08                 mov ecx, dword ptr [eax]
// 00760ea4  80793100             cmp byte ptr [ecx + 0x31], 0
// 00760ea8  74f6                 je 0x760ea0
// 00760eaa  c3                   ret 
// standard library set<pod36> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
