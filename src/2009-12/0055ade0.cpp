// from server: 100% by auto
// roc 2009-12 0055ade0  unit: RBX::Network::ServerReplicator  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0055ade0
//
// 0055ade0  8b442404             mov eax, dword ptr [esp + 4]
// 0055ade4  8b08                 mov ecx, dword ptr [eax]
// 0055ade6  80791100             cmp byte ptr [ecx + 0x11], 0
// 0055adea  750e                 jne 0x55adfa
// 0055adec  8d642400             lea esp, [esp]
// 0055adf0  8bc1                 mov eax, ecx
// 0055adf2  8b08                 mov ecx, dword ptr [eax]
// 0055adf4  80791100             cmp byte ptr [ecx + 0x11], 0
// 0055adf8  74f6                 je 0x55adf0
// 0055adfa  c3                   ret 
// standard library set<ptr> (function ?_Min@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
