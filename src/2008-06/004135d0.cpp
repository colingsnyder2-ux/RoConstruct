// from server: 100% by auto
// roc 2008-06 004135d0  unit: CutVerb  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004135d0
//
// 004135d0  8b442404             mov eax, dword ptr [esp + 4]
// 004135d4  8b08                 mov ecx, dword ptr [eax]
// 004135d6  80794500             cmp byte ptr [ecx + 0x45], 0
// 004135da  750e                 jne 0x4135ea
// 004135dc  8d642400             lea esp, [esp]
// 004135e0  8bc1                 mov eax, ecx
// 004135e2  8b08                 mov ecx, dword ptr [eax]
// 004135e4  80794500             cmp byte ptr [ecx + 0x45], 0
// 004135e8  74f6                 je 0x4135e0
// 004135ea  c3                   ret 
// standard library map_str<string> (function ?_Min@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
