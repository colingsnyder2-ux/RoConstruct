// from server: 100% by auto
// roc 2012-06 0082f9f0  unit: RBX::BallBlockContact  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0082f9f0
//
// 0082f9f0  8b442404             mov eax, dword ptr [esp + 4]
// 0082f9f4  8b08                 mov ecx, dword ptr [eax]
// 0082f9f6  80791900             cmp byte ptr [ecx + 0x19], 0
// 0082f9fa  750e                 jne 0x82fa0a
// 0082f9fc  8d642400             lea esp, [esp]
// 0082fa00  8bc1                 mov eax, ecx
// 0082fa02  8b08                 mov ecx, dword ptr [eax]
// 0082fa04  80791900             cmp byte ptr [ecx + 0x19], 0
// 0082fa08  74f6                 je 0x82fa00
// 0082fa0a  c3                   ret 
// standard library set<double> (function ?_Min@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
