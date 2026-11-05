// from server: 100% by auto
// roc 2011-06 00736940  unit: RBX::VStudioTool::?$EventDesc  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00736940
//
// 00736940  8b442404             mov eax, dword ptr [esp + 4]
// 00736944  8b08                 mov ecx, dword ptr [eax]
// 00736946  80790e00             cmp byte ptr [ecx + 0xe], 0
// 0073694a  750e                 jne 0x73695a
// 0073694c  8d642400             lea esp, [esp]
// 00736950  8bc1                 mov eax, ecx
// 00736952  8b08                 mov ecx, dword ptr [eax]
// 00736954  80790e00             cmp byte ptr [ecx + 0xe], 0
// 00736958  74f6                 je 0x736950
// 0073695a  c3                   ret 
// standard library set<char> (function ?_Min@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
