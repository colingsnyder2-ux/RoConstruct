// from server: 100% by auto
// roc 2007-08 005a9110  unit: RBX::VHumanoid::?$SignalDesc  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005a9110
//
// 005a9110  8b442404             mov eax, dword ptr [esp + 4]
// 005a9114  8b08                 mov ecx, dword ptr [eax]
// 005a9116  80791100             cmp byte ptr [ecx + 0x11], 0
// 005a911a  750e                 jne 0x5a912a
// 005a911c  8d642400             lea esp, [esp]
// 005a9120  8bc1                 mov eax, ecx
// 005a9122  8b08                 mov ecx, dword ptr [eax]
// 005a9124  80791100             cmp byte ptr [ecx + 0x11], 0
// 005a9128  74f6                 je 0x5a9120
// 005a912a  c3                   ret 
// standard library set<ptr> (function ?_Min@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
