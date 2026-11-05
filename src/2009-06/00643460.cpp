// from server: 100% by auto
// roc 2009-06 00643460  unit: RBX::WoodTool  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00643460
//
// 00643460  8b442404             mov eax, dword ptr [esp + 4]
// 00643464  8b08                 mov ecx, dword ptr [eax]
// 00643466  80793500             cmp byte ptr [ecx + 0x35], 0
// 0064346a  750e                 jne 0x64347a
// 0064346c  8d642400             lea esp, [esp]
// 00643470  8bc1                 mov eax, ecx
// 00643472  8b08                 mov ecx, dword ptr [eax]
// 00643474  80793500             cmp byte ptr [ecx + 0x35], 0
// 00643478  74f6                 je 0x643470
// 0064347a  c3                   ret 
// standard library set<pod40> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
