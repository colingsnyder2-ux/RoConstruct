// from server: 100% by auto
// roc 2011-06 00736920  unit: RBX::VStudioTool::?$EventDesc  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00736920
//
// 00736920  8b442404             mov eax, dword ptr [esp + 4]
// 00736924  8b4808               mov ecx, dword ptr [eax + 8]
// 00736927  80790e00             cmp byte ptr [ecx + 0xe], 0
// 0073692b  750e                 jne 0x73693b
// 0073692d  8d4900               lea ecx, [ecx]
// 00736930  8bc1                 mov eax, ecx
// 00736932  8b4808               mov ecx, dword ptr [eax + 8]
// 00736935  80790e00             cmp byte ptr [ecx + 0xe], 0
// 00736939  74f5                 je 0x736930
// 0073693b  c3                   ret 
// standard library set<char> (function ?_Max@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
