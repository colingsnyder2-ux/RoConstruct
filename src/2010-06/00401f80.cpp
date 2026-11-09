// from server: 100% by auto
// roc 2010-06 00401f80  unit: RBX::VTaskSchedulerSettings::?$FactoryProduct::Creator  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00401f80
//
// 00401f80  8b442404             mov eax, dword ptr [esp + 4]
// 00401f84  8b08                 mov ecx, dword ptr [eax]
// 00401f86  80791100             cmp byte ptr [ecx + 0x11], 0
// 00401f8a  750e                 jne 0x401f9a
// 00401f8c  8d642400             lea esp, [esp]
// 00401f90  8bc1                 mov eax, ecx
// 00401f92  8b08                 mov ecx, dword ptr [eax]
// 00401f94  80791100             cmp byte ptr [ecx + 0x11], 0
// 00401f98  74f6                 je 0x401f90
// 00401f9a  c3                   ret 
// standard library set<ptr> (function ?_Min@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
