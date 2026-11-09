// from server: 100% by auto
// roc 2011-06 00415b70  unit: PasteVerb  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00415b70
//
// 00415b70  8b442404             mov eax, dword ptr [esp + 4]
// 00415b74  8b4808               mov ecx, dword ptr [eax + 8]
// 00415b77  80794500             cmp byte ptr [ecx + 0x45], 0
// 00415b7b  750e                 jne 0x415b8b
// 00415b7d  8d4900               lea ecx, [ecx]
// 00415b80  8bc1                 mov eax, ecx
// 00415b82  8b4808               mov ecx, dword ptr [eax + 8]
// 00415b85  80794500             cmp byte ptr [ecx + 0x45], 0
// 00415b89  74f5                 je 0x415b80
// 00415b8b  c3                   ret 
// standard library map_str<string> (function ?_Max@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
