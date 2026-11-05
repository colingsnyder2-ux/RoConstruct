// from server: 100% by auto
// roc 2009-06 0062afa0  unit: RBX::Workspace  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0062afa0
//
// 0062afa0  8b442404             mov eax, dword ptr [esp + 4]
// 0062afa4  8b4808               mov ecx, dword ptr [eax + 8]
// 0062afa7  80791100             cmp byte ptr [ecx + 0x11], 0
// 0062afab  750e                 jne 0x62afbb
// 0062afad  8d4900               lea ecx, [ecx]
// 0062afb0  8bc1                 mov eax, ecx
// 0062afb2  8b4808               mov ecx, dword ptr [eax + 8]
// 0062afb5  80791100             cmp byte ptr [ecx + 0x11], 0
// 0062afb9  74f5                 je 0x62afb0
// 0062afbb  c3                   ret 
// standard library set<ptr> (function ?_Max@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
