// from server: 100% by auto
// roc 2007-08 00587c10  unit: RBX::Reflection::EnumDescriptor  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00587c10
//
// 00587c10  8b442404             mov eax, dword ptr [esp + 4]
// 00587c14  8b08                 mov ecx, dword ptr [eax]
// 00587c16  80791900             cmp byte ptr [ecx + 0x19], 0
// 00587c1a  750e                 jne 0x587c2a
// 00587c1c  8d642400             lea esp, [esp]
// 00587c20  8bc1                 mov eax, ecx
// 00587c22  8b08                 mov ecx, dword ptr [eax]
// 00587c24  80791900             cmp byte ptr [ecx + 0x19], 0
// 00587c28  74f6                 je 0x587c20
// 00587c2a  c3                   ret 
// standard library set<double> (function ?_Min@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
