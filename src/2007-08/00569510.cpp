// from server: 100% by auto
// roc 2007-08 00569510  unit: RBX::ModelInstance  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00569510
//
// 00569510  8b442404             mov eax, dword ptr [esp + 4]
// 00569514  8b08                 mov ecx, dword ptr [eax]
// 00569516  80793100             cmp byte ptr [ecx + 0x31], 0
// 0056951a  750e                 jne 0x56952a
// 0056951c  8d642400             lea esp, [esp]
// 00569520  8bc1                 mov eax, ecx
// 00569522  8b08                 mov ecx, dword ptr [eax]
// 00569524  80793100             cmp byte ptr [ecx + 0x31], 0
// 00569528  74f6                 je 0x569520
// 0056952a  c3                   ret 
// standard library set<pod36> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
