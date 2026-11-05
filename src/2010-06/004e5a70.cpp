// from server: 100% by auto
// roc 2010-06 004e5a70  unit: RBX::Network::Replicator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004e5a70
//
// 004e5a70  8b442404             mov eax, dword ptr [esp + 4]
// 004e5a74  8b4808               mov ecx, dword ptr [eax + 8]
// 004e5a77  80791100             cmp byte ptr [ecx + 0x11], 0
// 004e5a7b  750e                 jne 0x4e5a8b
// 004e5a7d  8d4900               lea ecx, [ecx]
// 004e5a80  8bc1                 mov eax, ecx
// 004e5a82  8b4808               mov ecx, dword ptr [eax + 8]
// 004e5a85  80791100             cmp byte ptr [ecx + 0x11], 0
// 004e5a89  74f5                 je 0x4e5a80
// 004e5a8b  c3                   ret 
// standard library set<ptr> (function ?_Max@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
