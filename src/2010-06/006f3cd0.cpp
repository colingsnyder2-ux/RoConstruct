// from server: 100% by auto
// roc 2010-06 006f3cd0  unit: RBX::VStudioTool::?$EventDesc  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006f3cd0
//
// 006f3cd0  8b442404             mov eax, dword ptr [esp + 4]
// 006f3cd4  8b08                 mov ecx, dword ptr [eax]
// 006f3cd6  80790e00             cmp byte ptr [ecx + 0xe], 0
// 006f3cda  750e                 jne 0x6f3cea
// 006f3cdc  8d642400             lea esp, [esp]
// 006f3ce0  8bc1                 mov eax, ecx
// 006f3ce2  8b08                 mov ecx, dword ptr [eax]
// 006f3ce4  80790e00             cmp byte ptr [ecx + 0xe], 0
// 006f3ce8  74f6                 je 0x6f3ce0
// 006f3cea  c3                   ret 
// standard library set<char> (function ?_Min@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
