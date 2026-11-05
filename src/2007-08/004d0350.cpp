// from server: 100% by auto
// roc 2007-08 004d0350  unit: RBX::TextureProxyBase  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004d0350
//
// 004d0350  8b442404             mov eax, dword ptr [esp + 4]
// 004d0354  8b08                 mov ecx, dword ptr [eax]
// 004d0356  80792900             cmp byte ptr [ecx + 0x29], 0
// 004d035a  750e                 jne 0x4d036a
// 004d035c  8d642400             lea esp, [esp]
// 004d0360  8bc1                 mov eax, ecx
// 004d0362  8b08                 mov ecx, dword ptr [eax]
// 004d0364  80792900             cmp byte ptr [ecx + 0x29], 0
// 004d0368  74f6                 je 0x4d0360
// 004d036a  c3                   ret 
// standard library set<string> (function ?_Min@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
