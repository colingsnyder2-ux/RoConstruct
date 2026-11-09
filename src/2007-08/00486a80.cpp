// from server: 100% by auto
// roc 2007-08 00486a80  unit: G3D::GWindow  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00486a80
//
// 00486a80  8b442404             mov eax, dword ptr [esp + 4]
// 00486a84  8b08                 mov ecx, dword ptr [eax]
// 00486a86  80790e00             cmp byte ptr [ecx + 0xe], 0
// 00486a8a  750e                 jne 0x486a9a
// 00486a8c  8d642400             lea esp, [esp]
// 00486a90  8bc1                 mov eax, ecx
// 00486a92  8b08                 mov ecx, dword ptr [eax]
// 00486a94  80790e00             cmp byte ptr [ecx + 0xe], 0
// 00486a98  74f6                 je 0x486a90
// 00486a9a  c3                   ret 
// standard library set<char> (function ?_Min@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
