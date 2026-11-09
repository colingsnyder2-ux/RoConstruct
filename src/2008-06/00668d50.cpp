// from server: 100% by auto
// roc 2008-06 00668d50  unit: RBX::JointStage  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00668d50
//
// 00668d50  8b442404             mov eax, dword ptr [esp + 4]
// 00668d54  8b4808               mov ecx, dword ptr [eax + 8]
// 00668d57  80791100             cmp byte ptr [ecx + 0x11], 0
// 00668d5b  750e                 jne 0x668d6b
// 00668d5d  8d4900               lea ecx, [ecx]
// 00668d60  8bc1                 mov eax, ecx
// 00668d62  8b4808               mov ecx, dword ptr [eax + 8]
// 00668d65  80791100             cmp byte ptr [ecx + 0x11], 0
// 00668d69  74f5                 je 0x668d60
// 00668d6b  c3                   ret 
// standard library set<ptr> (function ?_Max@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
