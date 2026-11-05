// from server: 100% by auto
// roc 2012-06 008773d0  unit: DummyJob  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008773d0
//
// 008773d0  8b442404             mov eax, dword ptr [esp + 4]
// 008773d4  8b08                 mov ecx, dword ptr [eax]
// 008773d6  80790e00             cmp byte ptr [ecx + 0xe], 0
// 008773da  750e                 jne 0x8773ea
// 008773dc  8d642400             lea esp, [esp]
// 008773e0  8bc1                 mov eax, ecx
// 008773e2  8b08                 mov ecx, dword ptr [eax]
// 008773e4  80790e00             cmp byte ptr [ecx + 0xe], 0
// 008773e8  74f6                 je 0x8773e0
// 008773ea  c3                   ret 
// standard library set<char> (function ?_Min@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
