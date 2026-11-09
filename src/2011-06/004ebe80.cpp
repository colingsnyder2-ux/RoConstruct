// from server: 100% by auto
// roc 2011-06 004ebe80  unit: RBX::Network::VServer::?$EventDesc  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004ebe80
//
// 004ebe80  8b442404             mov eax, dword ptr [esp + 4]
// 004ebe84  8b08                 mov ecx, dword ptr [eax]
// 004ebe86  80791900             cmp byte ptr [ecx + 0x19], 0
// 004ebe8a  750e                 jne 0x4ebe9a
// 004ebe8c  8d642400             lea esp, [esp]
// 004ebe90  8bc1                 mov eax, ecx
// 004ebe92  8b08                 mov ecx, dword ptr [eax]
// 004ebe94  80791900             cmp byte ptr [ecx + 0x19], 0
// 004ebe98  74f6                 je 0x4ebe90
// 004ebe9a  c3                   ret 
// standard library set<double> (function ?_Min@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
