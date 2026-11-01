// from server: 100% by auto
// roc 2009-12 005376f0  unit: RBX::Network::Replicator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005376f0
//
// 005376f0  8b442404             mov eax, dword ptr [esp + 4]
// 005376f4  8b4808               mov ecx, dword ptr [eax + 8]
// 005376f7  80791900             cmp byte ptr [ecx + 0x19], 0
// 005376fb  750e                 jne 0x53770b
// 005376fd  8d4900               lea ecx, [ecx]
// 00537700  8bc1                 mov eax, ecx
// 00537702  8b4808               mov ecx, dword ptr [eax + 8]
// 00537705  80791900             cmp byte ptr [ecx + 0x19], 0
// 00537709  74f5                 je 0x537700
// 0053770b  c3                   ret 
// standard library set<double> (function ?_Max@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
