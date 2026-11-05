// from server: 100% by auto
// roc 2010-06 004e5a90  unit: RBX::Network::Replicator  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004e5a90
//
// 004e5a90  8b442404             mov eax, dword ptr [esp + 4]
// 004e5a94  8b08                 mov ecx, dword ptr [eax]
// 004e5a96  80791900             cmp byte ptr [ecx + 0x19], 0
// 004e5a9a  750e                 jne 0x4e5aaa
// 004e5a9c  8d642400             lea esp, [esp]
// 004e5aa0  8bc1                 mov eax, ecx
// 004e5aa2  8b08                 mov ecx, dword ptr [eax]
// 004e5aa4  80791900             cmp byte ptr [ecx + 0x19], 0
// 004e5aa8  74f6                 je 0x4e5aa0
// 004e5aaa  c3                   ret 
// standard library set<double> (function ?_Min@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
