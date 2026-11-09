// from server: 100% by auto
// roc 2009-06 004e32d0  unit: RBX::Network::Replicator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e32d0
//
// 004e32d0  8b442404             mov eax, dword ptr [esp + 4]
// 004e32d4  8b4808               mov ecx, dword ptr [eax + 8]
// 004e32d7  80791900             cmp byte ptr [ecx + 0x19], 0
// 004e32db  750e                 jne 0x4e32eb
// 004e32dd  8d4900               lea ecx, [ecx]
// 004e32e0  8bc1                 mov eax, ecx
// 004e32e2  8b4808               mov ecx, dword ptr [eax + 8]
// 004e32e5  80791900             cmp byte ptr [ecx + 0x19], 0
// 004e32e9  74f5                 je 0x4e32e0
// 004e32eb  c3                   ret 
// standard library set<double> (function ?_Max@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
