// from server: 100% by auto
// roc 2009-06 00413b60  unit: CutVerb  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00413b60
//
// 00413b60  8b442404             mov eax, dword ptr [esp + 4]
// 00413b64  8b4808               mov ecx, dword ptr [eax + 8]
// 00413b67  80794500             cmp byte ptr [ecx + 0x45], 0
// 00413b6b  750e                 jne 0x413b7b
// 00413b6d  8d4900               lea ecx, [ecx]
// 00413b70  8bc1                 mov eax, ecx
// 00413b72  8b4808               mov ecx, dword ptr [eax + 8]
// 00413b75  80794500             cmp byte ptr [ecx + 0x45], 0
// 00413b79  74f5                 je 0x413b70
// 00413b7b  c3                   ret 
// standard library map_str<string> (function ?_Max@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
