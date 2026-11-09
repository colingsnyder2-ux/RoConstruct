// from server: 100% by auto
// roc 2009-06 006e2020  unit: RBX::ChatOutput  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e2020
//
// 006e2020  8b442404             mov eax, dword ptr [esp + 4]
// 006e2024  8b08                 mov ecx, dword ptr [eax]
// 006e2026  80794900             cmp byte ptr [ecx + 0x49], 0
// 006e202a  750e                 jne 0x6e203a
// 006e202c  8d642400             lea esp, [esp]
// 006e2030  8bc1                 mov eax, ecx
// 006e2032  8b08                 mov ecx, dword ptr [eax]
// 006e2034  80794900             cmp byte ptr [ecx + 0x49], 0
// 006e2038  74f6                 je 0x6e2030
// 006e203a  c3                   ret 
// standard library map_str<pod32> (function ?_Min@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
