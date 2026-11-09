// from server: 100% by auto
// roc 2009-06 006434d0  unit: RBX::WoodTool  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006434d0
//
// 006434d0  8b442404             mov eax, dword ptr [esp + 4]
// 006434d4  8b08                 mov ecx, dword ptr [eax]
// 006434d6  80791900             cmp byte ptr [ecx + 0x19], 0
// 006434da  750e                 jne 0x6434ea
// 006434dc  8d642400             lea esp, [esp]
// 006434e0  8bc1                 mov eax, ecx
// 006434e2  8b08                 mov ecx, dword ptr [eax]
// 006434e4  80791900             cmp byte ptr [ecx + 0x19], 0
// 006434e8  74f6                 je 0x6434e0
// 006434ea  c3                   ret 
// standard library set<double> (function ?_Min@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
