// from server: 100% by auto
// roc 2008-06 004ab070  unit: RBX::Network::Replicator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004ab070
//
// 004ab070  8b442404             mov eax, dword ptr [esp + 4]
// 004ab074  8b4808               mov ecx, dword ptr [eax + 8]
// 004ab077  80791900             cmp byte ptr [ecx + 0x19], 0
// 004ab07b  750e                 jne 0x4ab08b
// 004ab07d  8d4900               lea ecx, [ecx]
// 004ab080  8bc1                 mov eax, ecx
// 004ab082  8b4808               mov ecx, dword ptr [eax + 8]
// 004ab085  80791900             cmp byte ptr [ecx + 0x19], 0
// 004ab089  74f5                 je 0x4ab080
// 004ab08b  c3                   ret 
// standard library set<double> (function ?_Max@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
