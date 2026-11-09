// from server: 100% by auto
// roc 2012-06 008aeab0  unit: RBX::Flag  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008aeab0
//
// 008aeab0  8b442404             mov eax, dword ptr [esp + 4]
// 008aeab4  8b4808               mov ecx, dword ptr [eax + 8]
// 008aeab7  80791100             cmp byte ptr [ecx + 0x11], 0
// 008aeabb  750e                 jne 0x8aeacb
// 008aeabd  8d4900               lea ecx, [ecx]
// 008aeac0  8bc1                 mov eax, ecx
// 008aeac2  8b4808               mov ecx, dword ptr [eax + 8]
// 008aeac5  80791100             cmp byte ptr [ecx + 0x11], 0
// 008aeac9  74f5                 je 0x8aeac0
// 008aeacb  c3                   ret 
// standard library set<ptr> (function ?_Max@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
