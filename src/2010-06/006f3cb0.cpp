// from server: 100% by auto
// roc 2010-06 006f3cb0  unit: RBX::VStudioTool::?$EventDesc  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006f3cb0
//
// 006f3cb0  8b442404             mov eax, dword ptr [esp + 4]
// 006f3cb4  8b4808               mov ecx, dword ptr [eax + 8]
// 006f3cb7  80790e00             cmp byte ptr [ecx + 0xe], 0
// 006f3cbb  750e                 jne 0x6f3ccb
// 006f3cbd  8d4900               lea ecx, [ecx]
// 006f3cc0  8bc1                 mov eax, ecx
// 006f3cc2  8b4808               mov ecx, dword ptr [eax + 8]
// 006f3cc5  80790e00             cmp byte ptr [ecx + 0xe], 0
// 006f3cc9  74f5                 je 0x6f3cc0
// 006f3ccb  c3                   ret 
// standard library set<char> (function ?_Max@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
