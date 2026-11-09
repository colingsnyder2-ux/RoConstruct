// from server: 100% by auto
// roc 2011-06 007c8560  unit: RBX::AdornBillboarder  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007c8560
//
// 007c8560  8b442404             mov eax, dword ptr [esp + 4]
// 007c8564  8b4808               mov ecx, dword ptr [eax + 8]
// 007c8567  80795900             cmp byte ptr [ecx + 0x59], 0
// 007c856b  750e                 jne 0x7c857b
// 007c856d  8d4900               lea ecx, [ecx]
// 007c8570  8bc1                 mov eax, ecx
// 007c8572  8b4808               mov ecx, dword ptr [eax + 8]
// 007c8575  80795900             cmp byte ptr [ecx + 0x59], 0
// 007c8579  74f5                 je 0x7c8570
// 007c857b  c3                   ret 
// standard library map_str<pod48> (function ?_Max@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<pod48>
struct E { int v[12]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
