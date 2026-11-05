// from server: 100% by auto
// roc 2008-06 00650e90  unit: RBX::ChatOutput  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00650e90
//
// 00650e90  8b442404             mov eax, dword ptr [esp + 4]
// 00650e94  8b4808               mov ecx, dword ptr [eax + 8]
// 00650e97  80793100             cmp byte ptr [ecx + 0x31], 0
// 00650e9b  750e                 jne 0x650eab
// 00650e9d  8d4900               lea ecx, [ecx]
// 00650ea0  8bc1                 mov eax, ecx
// 00650ea2  8b4808               mov ecx, dword ptr [eax + 8]
// 00650ea5  80793100             cmp byte ptr [ecx + 0x31], 0
// 00650ea9  74f5                 je 0x650ea0
// 00650eab  c3                   ret 
// standard library set<pod36> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
