// from server: 100% by auto
// roc 2007-08 00486a60  unit: G3D::GWindow  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00486a60
//
// 00486a60  8b442404             mov eax, dword ptr [esp + 4]
// 00486a64  8b4808               mov ecx, dword ptr [eax + 8]
// 00486a67  80790e00             cmp byte ptr [ecx + 0xe], 0
// 00486a6b  750e                 jne 0x486a7b
// 00486a6d  8d4900               lea ecx, [ecx]
// 00486a70  8bc1                 mov eax, ecx
// 00486a72  8b4808               mov ecx, dword ptr [eax + 8]
// 00486a75  80790e00             cmp byte ptr [ecx + 0xe], 0
// 00486a79  74f5                 je 0x486a70
// 00486a7b  c3                   ret 
// standard library set<char> (function ?_Max@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
