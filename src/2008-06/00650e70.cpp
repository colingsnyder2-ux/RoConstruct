// from server: 100% by auto
// roc 2008-06 00650e70  unit: RBX::ChatOutput  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00650e70
//
// 00650e70  8b442404             mov eax, dword ptr [esp + 4]
// 00650e74  8b4808               mov ecx, dword ptr [eax + 8]
// 00650e77  80794900             cmp byte ptr [ecx + 0x49], 0
// 00650e7b  750e                 jne 0x650e8b
// 00650e7d  8d4900               lea ecx, [ecx]
// 00650e80  8bc1                 mov eax, ecx
// 00650e82  8b4808               mov ecx, dword ptr [eax + 8]
// 00650e85  80794900             cmp byte ptr [ecx + 0x49], 0
// 00650e89  74f5                 je 0x650e80
// 00650e8b  c3                   ret 
// standard library map_str<pod32> (function ?_Max@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
