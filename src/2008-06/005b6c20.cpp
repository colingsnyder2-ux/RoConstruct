// from server: 100% by auto
// roc 2008-06 005b6c20  unit: RBX::DropperTool  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b6c20
//
// 005b6c20  8b442404             mov eax, dword ptr [esp + 4]
// 005b6c24  8b08                 mov ecx, dword ptr [eax]
// 005b6c26  80791900             cmp byte ptr [ecx + 0x19], 0
// 005b6c2a  750e                 jne 0x5b6c3a
// 005b6c2c  8d642400             lea esp, [esp]
// 005b6c30  8bc1                 mov eax, ecx
// 005b6c32  8b08                 mov ecx, dword ptr [eax]
// 005b6c34  80791900             cmp byte ptr [ecx + 0x19], 0
// 005b6c38  74f6                 je 0x5b6c30
// 005b6c3a  c3                   ret 
// standard library set<double> (function ?_Min@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
