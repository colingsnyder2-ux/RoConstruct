// from server: 100% by auto
// roc 2012-06 0082f9d0  unit: RBX::BallBlockContact  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0082f9d0
//
// 0082f9d0  8b442404             mov eax, dword ptr [esp + 4]
// 0082f9d4  8b4808               mov ecx, dword ptr [eax + 8]
// 0082f9d7  80791900             cmp byte ptr [ecx + 0x19], 0
// 0082f9db  750e                 jne 0x82f9eb
// 0082f9dd  8d4900               lea ecx, [ecx]
// 0082f9e0  8bc1                 mov eax, ecx
// 0082f9e2  8b4808               mov ecx, dword ptr [eax + 8]
// 0082f9e5  80791900             cmp byte ptr [ecx + 0x19], 0
// 0082f9e9  74f5                 je 0x82f9e0
// 0082f9eb  c3                   ret 
// standard library set<double> (function ?_Max@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
