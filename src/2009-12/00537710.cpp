// from server: 100% by auto
// roc 2009-12 00537710  unit: RBX::Network::Replicator  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00537710
//
// 00537710  8b442404             mov eax, dword ptr [esp + 4]
// 00537714  8b08                 mov ecx, dword ptr [eax]
// 00537716  80791900             cmp byte ptr [ecx + 0x19], 0
// 0053771a  750e                 jne 0x53772a
// 0053771c  8d642400             lea esp, [esp]
// 00537720  8bc1                 mov eax, ecx
// 00537722  8b08                 mov ecx, dword ptr [eax]
// 00537724  80791900             cmp byte ptr [ecx + 0x19], 0
// 00537728  74f6                 je 0x537720
// 0053772a  c3                   ret 
// standard library set<double> (function ?_Min@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
