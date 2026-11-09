// from server: 100% by auto
// roc 2011-06 007c84f0  unit: RBX::AdornBillboarder  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007c84f0
//
// 007c84f0  8b442404             mov eax, dword ptr [esp + 4]
// 007c84f4  8b4808               mov ecx, dword ptr [eax + 8]
// 007c84f7  80791900             cmp byte ptr [ecx + 0x19], 0
// 007c84fb  750e                 jne 0x7c850b
// 007c84fd  8d4900               lea ecx, [ecx]
// 007c8500  8bc1                 mov eax, ecx
// 007c8502  8b4808               mov ecx, dword ptr [eax + 8]
// 007c8505  80791900             cmp byte ptr [ecx + 0x19], 0
// 007c8509  74f5                 je 0x7c8500
// 007c850b  c3                   ret 
// standard library set<double> (function ?_Max@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
