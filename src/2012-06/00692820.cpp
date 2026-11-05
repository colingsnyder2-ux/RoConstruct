// from server: 100% by auto
// roc 2012-06 00692820  unit: RBX::VModelInstance::?$BoundFuncDesc  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00692820
//
// 00692820  8b442404             mov eax, dword ptr [esp + 4]
// 00692824  8b4808               mov ecx, dword ptr [eax + 8]
// 00692827  80793500             cmp byte ptr [ecx + 0x35], 0
// 0069282b  750e                 jne 0x69283b
// 0069282d  8d4900               lea ecx, [ecx]
// 00692830  8bc1                 mov eax, ecx
// 00692832  8b4808               mov ecx, dword ptr [eax + 8]
// 00692835  80793500             cmp byte ptr [ecx + 0x35], 0
// 00692839  74f5                 je 0x692830
// 0069283b  c3                   ret 
// standard library set<pod40> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
