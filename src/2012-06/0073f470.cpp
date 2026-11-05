// from server: 100% by auto
// roc 2012-06 0073f470  unit: RBX::PluginManager  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0073f470
//
// 0073f470  8b442404             mov eax, dword ptr [esp + 4]
// 0073f474  8b08                 mov ecx, dword ptr [eax]
// 0073f476  80792100             cmp byte ptr [ecx + 0x21], 0
// 0073f47a  750e                 jne 0x73f48a
// 0073f47c  8d642400             lea esp, [esp]
// 0073f480  8bc1                 mov eax, ecx
// 0073f482  8b08                 mov ecx, dword ptr [eax]
// 0073f484  80792100             cmp byte ptr [ecx + 0x21], 0
// 0073f488  74f6                 je 0x73f480
// 0073f48a  c3                   ret 
// standard library set<pod20> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
