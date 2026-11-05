// from server: 100% by auto
// roc 2011-06 00736960  unit: RBX::VStudioTool::?$EventDesc  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00736960
//
// 00736960  8b442404             mov eax, dword ptr [esp + 4]
// 00736964  8b08                 mov ecx, dword ptr [eax]
// 00736966  80791100             cmp byte ptr [ecx + 0x11], 0
// 0073696a  750e                 jne 0x73697a
// 0073696c  8d642400             lea esp, [esp]
// 00736970  8bc1                 mov eax, ecx
// 00736972  8b08                 mov ecx, dword ptr [eax]
// 00736974  80791100             cmp byte ptr [ecx + 0x11], 0
// 00736978  74f6                 je 0x736970
// 0073697a  c3                   ret 
// standard library set<ptr> (function ?_Min@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
