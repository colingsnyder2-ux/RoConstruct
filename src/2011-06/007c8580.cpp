// from server: 100% by auto
// roc 2011-06 007c8580  unit: RBX::AdornBillboarder  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007c8580
//
// 007c8580  8b442404             mov eax, dword ptr [esp + 4]
// 007c8584  8b08                 mov ecx, dword ptr [eax]
// 007c8586  80795900             cmp byte ptr [ecx + 0x59], 0
// 007c858a  750e                 jne 0x7c859a
// 007c858c  8d642400             lea esp, [esp]
// 007c8590  8bc1                 mov eax, ecx
// 007c8592  8b08                 mov ecx, dword ptr [eax]
// 007c8594  80795900             cmp byte ptr [ecx + 0x59], 0
// 007c8598  74f6                 je 0x7c8590
// 007c859a  c3                   ret 
// standard library map_str<pod48> (function ?_Min@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<pod48>
struct E { int v[12]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
