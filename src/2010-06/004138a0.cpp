// from server: 100% by auto
// roc 2010-06 004138a0  unit: CutVerb  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004138a0
//
// 004138a0  8b442404             mov eax, dword ptr [esp + 4]
// 004138a4  8b4808               mov ecx, dword ptr [eax + 8]
// 004138a7  80794500             cmp byte ptr [ecx + 0x45], 0
// 004138ab  750e                 jne 0x4138bb
// 004138ad  8d4900               lea ecx, [ecx]
// 004138b0  8bc1                 mov eax, ecx
// 004138b2  8b4808               mov ecx, dword ptr [eax + 8]
// 004138b5  80794500             cmp byte ptr [ecx + 0x45], 0
// 004138b9  74f5                 je 0x4138b0
// 004138bb  c3                   ret 
// standard library map_str<string> (function ?_Max@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
