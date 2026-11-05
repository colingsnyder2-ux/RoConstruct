// from server: 100% by auto
// roc 2008-06 00437f00  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00437f00
//
// 00437f00  8b442404             mov eax, dword ptr [esp + 4]
// 00437f04  8b08                 mov ecx, dword ptr [eax]
// 00437f06  80792900             cmp byte ptr [ecx + 0x29], 0
// 00437f0a  750e                 jne 0x437f1a
// 00437f0c  8d642400             lea esp, [esp]
// 00437f10  8bc1                 mov eax, ecx
// 00437f12  8b08                 mov ecx, dword ptr [eax]
// 00437f14  80792900             cmp byte ptr [ecx + 0x29], 0
// 00437f18  74f6                 je 0x437f10
// 00437f1a  c3                   ret 
// standard library set<string> (function ?_Min@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
