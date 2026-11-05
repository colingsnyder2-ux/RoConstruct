// from server: 100% by auto
// roc 2009-12 00401f90  unit: RBX::VTaskSchedulerSettings::?$FactoryProduct::Creator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00401f90
//
// 00401f90  8b442404             mov eax, dword ptr [esp + 4]
// 00401f94  8b4808               mov ecx, dword ptr [eax + 8]
// 00401f97  80791100             cmp byte ptr [ecx + 0x11], 0
// 00401f9b  750e                 jne 0x401fab
// 00401f9d  8d4900               lea ecx, [ecx]
// 00401fa0  8bc1                 mov eax, ecx
// 00401fa2  8b4808               mov ecx, dword ptr [eax + 8]
// 00401fa5  80791100             cmp byte ptr [ecx + 0x11], 0
// 00401fa9  74f5                 je 0x401fa0
// 00401fab  c3                   ret 
// standard library set<ptr> (function ?_Max@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
