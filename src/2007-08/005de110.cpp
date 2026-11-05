// from server: 100% by auto
// roc 2007-08 005de110  unit: RBX::VMotorFeature::?$FactoryProduct  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005de110
//
// 005de110  8b442404             mov eax, dword ptr [esp + 4]
// 005de114  8b4808               mov ecx, dword ptr [eax + 8]
// 005de117  80791100             cmp byte ptr [ecx + 0x11], 0
// 005de11b  750e                 jne 0x5de12b
// 005de11d  8d4900               lea ecx, [ecx]
// 005de120  8bc1                 mov eax, ecx
// 005de122  8b4808               mov ecx, dword ptr [eax + 8]
// 005de125  80791100             cmp byte ptr [ecx + 0x11], 0
// 005de129  74f5                 je 0x5de120
// 005de12b  c3                   ret 
// standard library set<ptr> (function ?_Max@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
