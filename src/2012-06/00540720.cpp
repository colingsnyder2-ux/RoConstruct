// from server: 100% by auto
// roc 2012-06 00540720  unit: RBX::VObjectValue::?$FactoryProduct::Creator  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00540720
//
// 00540720  8b442404             mov eax, dword ptr [esp + 4]
// 00540724  8b08                 mov ecx, dword ptr [eax]
// 00540726  80792900             cmp byte ptr [ecx + 0x29], 0
// 0054072a  750e                 jne 0x54073a
// 0054072c  8d642400             lea esp, [esp]
// 00540730  8bc1                 mov eax, ecx
// 00540732  8b08                 mov ecx, dword ptr [eax]
// 00540734  80792900             cmp byte ptr [ecx + 0x29], 0
// 00540738  74f6                 je 0x540730
// 0054073a  c3                   ret 
// standard library set<string> (function ?_Min@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
