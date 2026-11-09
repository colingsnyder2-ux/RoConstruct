// from server: 100% by auto
// roc 2009-06 00413b80  unit: CutVerb  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00413b80
//
// 00413b80  8b442404             mov eax, dword ptr [esp + 4]
// 00413b84  8b08                 mov ecx, dword ptr [eax]
// 00413b86  80794500             cmp byte ptr [ecx + 0x45], 0
// 00413b8a  750e                 jne 0x413b9a
// 00413b8c  8d642400             lea esp, [esp]
// 00413b90  8bc1                 mov eax, ecx
// 00413b92  8b08                 mov ecx, dword ptr [eax]
// 00413b94  80794500             cmp byte ptr [ecx + 0x45], 0
// 00413b98  74f6                 je 0x413b90
// 00413b9a  c3                   ret 
// standard library map_str<string> (function ?_Min@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
