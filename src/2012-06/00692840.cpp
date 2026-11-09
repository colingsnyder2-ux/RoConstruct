// from server: 100% by auto
// roc 2012-06 00692840  unit: RBX::VModelInstance::?$BoundFuncDesc  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00692840
//
// 00692840  8b442404             mov eax, dword ptr [esp + 4]
// 00692844  8b08                 mov ecx, dword ptr [eax]
// 00692846  80793500             cmp byte ptr [ecx + 0x35], 0
// 0069284a  750e                 jne 0x69285a
// 0069284c  8d642400             lea esp, [esp]
// 00692850  8bc1                 mov eax, ecx
// 00692852  8b08                 mov ecx, dword ptr [eax]
// 00692854  80793500             cmp byte ptr [ecx + 0x35], 0
// 00692858  74f6                 je 0x692850
// 0069285a  c3                   ret 
// standard library set<pod40> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
