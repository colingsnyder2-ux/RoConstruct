// from server: 100% by auto
// roc 2011-06 007b19f0  unit: RBX::CleanStage  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007b19f0
//
// 007b19f0  8b442404             mov eax, dword ptr [esp + 4]
// 007b19f4  8b4808               mov ecx, dword ptr [eax + 8]
// 007b19f7  80791100             cmp byte ptr [ecx + 0x11], 0
// 007b19fb  750e                 jne 0x7b1a0b
// 007b19fd  8d4900               lea ecx, [ecx]
// 007b1a00  8bc1                 mov eax, ecx
// 007b1a02  8b4808               mov ecx, dword ptr [eax + 8]
// 007b1a05  80791100             cmp byte ptr [ecx + 0x11], 0
// 007b1a09  74f5                 je 0x7b1a00
// 007b1a0b  c3                   ret 
// standard library set<ptr> (function ?_Max@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
