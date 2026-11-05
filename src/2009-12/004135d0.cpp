// from server: 100% by auto
// roc 2009-12 004135d0  unit: CutVerb  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004135d0
//
// 004135d0  8b442404             mov eax, dword ptr [esp + 4]
// 004135d4  8b4808               mov ecx, dword ptr [eax + 8]
// 004135d7  80794500             cmp byte ptr [ecx + 0x45], 0
// 004135db  750e                 jne 0x4135eb
// 004135dd  8d4900               lea ecx, [ecx]
// 004135e0  8bc1                 mov eax, ecx
// 004135e2  8b4808               mov ecx, dword ptr [eax + 8]
// 004135e5  80794500             cmp byte ptr [ecx + 0x45], 0
// 004135e9  74f5                 je 0x4135e0
// 004135eb  c3                   ret 
// standard library map_str<string> (function ?_Max@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
