// from server: 100% by auto
// roc 2008-06 004c9b50  unit: RBX::Network::InterpolatingPhysicsReceiver  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c9b50
//
// 004c9b50  8b442404             mov eax, dword ptr [esp + 4]
// 004c9b54  8b08                 mov ecx, dword ptr [eax]
// 004c9b56  80791100             cmp byte ptr [ecx + 0x11], 0
// 004c9b5a  750e                 jne 0x4c9b6a
// 004c9b5c  8d642400             lea esp, [esp]
// 004c9b60  8bc1                 mov eax, ecx
// 004c9b62  8b08                 mov ecx, dword ptr [eax]
// 004c9b64  80791100             cmp byte ptr [ecx + 0x11], 0
// 004c9b68  74f6                 je 0x4c9b60
// 004c9b6a  c3                   ret 
// standard library set<ptr> (function ?_Min@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
