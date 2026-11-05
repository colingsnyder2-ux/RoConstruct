// from server: 100% by auto
// roc 2012-06 005a6390  unit: RBX::Network::NetworkOwnerJob  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005a6390
//
// 005a6390  8b442404             mov eax, dword ptr [esp + 4]
// 005a6394  8b4808               mov ecx, dword ptr [eax + 8]
// 005a6397  80792900             cmp byte ptr [ecx + 0x29], 0
// 005a639b  750e                 jne 0x5a63ab
// 005a639d  8d4900               lea ecx, [ecx]
// 005a63a0  8bc1                 mov eax, ecx
// 005a63a2  8b4808               mov ecx, dword ptr [eax + 8]
// 005a63a5  80792900             cmp byte ptr [ecx + 0x29], 0
// 005a63a9  74f5                 je 0x5a63a0
// 005a63ab  c3                   ret 
// standard library set<string> (function ?_Max@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
