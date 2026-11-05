// from server: 100% by auto
// roc 2009-06 0067e7a0  unit: RBX::Mechanism  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0067e7a0
//
// 0067e7a0  8b442404             mov eax, dword ptr [esp + 4]
// 0067e7a4  8b08                 mov ecx, dword ptr [eax]
// 0067e7a6  80791100             cmp byte ptr [ecx + 0x11], 0
// 0067e7aa  750e                 jne 0x67e7ba
// 0067e7ac  8d642400             lea esp, [esp]
// 0067e7b0  8bc1                 mov eax, ecx
// 0067e7b2  8b08                 mov ecx, dword ptr [eax]
// 0067e7b4  80791100             cmp byte ptr [ecx + 0x11], 0
// 0067e7b8  74f6                 je 0x67e7b0
// 0067e7ba  c3                   ret 
// standard library set<ptr> (function ?_Min@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
