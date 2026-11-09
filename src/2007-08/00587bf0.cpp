// from server: 100% by auto
// roc 2007-08 00587bf0  unit: RBX::Reflection::EnumDescriptor  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00587bf0
//
// 00587bf0  8b442404             mov eax, dword ptr [esp + 4]
// 00587bf4  8b4808               mov ecx, dword ptr [eax + 8]
// 00587bf7  80791900             cmp byte ptr [ecx + 0x19], 0
// 00587bfb  750e                 jne 0x587c0b
// 00587bfd  8d4900               lea ecx, [ecx]
// 00587c00  8bc1                 mov eax, ecx
// 00587c02  8b4808               mov ecx, dword ptr [eax + 8]
// 00587c05  80791900             cmp byte ptr [ecx + 0x19], 0
// 00587c09  74f5                 je 0x587c00
// 00587c0b  c3                   ret 
// standard library set<double> (function ?_Max@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
