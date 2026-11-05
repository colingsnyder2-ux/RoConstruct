// from server: 100% by auto
// roc 2008-06 004a1660  unit: RBX::Network::Server::ClientProxy  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a1660
//
// 004a1660  8b442404             mov eax, dword ptr [esp + 4]
// 004a1664  8b4808               mov ecx, dword ptr [eax + 8]
// 004a1667  80792900             cmp byte ptr [ecx + 0x29], 0
// 004a166b  750e                 jne 0x4a167b
// 004a166d  8d4900               lea ecx, [ecx]
// 004a1670  8bc1                 mov eax, ecx
// 004a1672  8b4808               mov ecx, dword ptr [eax + 8]
// 004a1675  80792900             cmp byte ptr [ecx + 0x29], 0
// 004a1679  74f5                 je 0x4a1670
// 004a167b  c3                   ret 
// standard library set<string> (function ?_Max@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
