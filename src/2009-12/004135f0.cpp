// from server: 100% by auto
// roc 2009-12 004135f0  unit: CutVerb  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004135f0
//
// 004135f0  8b442404             mov eax, dword ptr [esp + 4]
// 004135f4  8b08                 mov ecx, dword ptr [eax]
// 004135f6  80794500             cmp byte ptr [ecx + 0x45], 0
// 004135fa  750e                 jne 0x41360a
// 004135fc  8d642400             lea esp, [esp]
// 00413600  8bc1                 mov eax, ecx
// 00413602  8b08                 mov ecx, dword ptr [eax]
// 00413604  80794500             cmp byte ptr [ecx + 0x45], 0
// 00413608  74f6                 je 0x413600
// 0041360a  c3                   ret 
// standard library map_str<string> (function ?_Min@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
