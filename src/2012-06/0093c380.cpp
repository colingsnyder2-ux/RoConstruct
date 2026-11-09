// from server: 100% by auto
// roc 2012-06 0093c380  unit: RBX::AdornBillboarder  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0093c380
//
// 0093c380  8b442404             mov eax, dword ptr [esp + 4]
// 0093c384  8b08                 mov ecx, dword ptr [eax]
// 0093c386  80795900             cmp byte ptr [ecx + 0x59], 0
// 0093c38a  750e                 jne 0x93c39a
// 0093c38c  8d642400             lea esp, [esp]
// 0093c390  8bc1                 mov eax, ecx
// 0093c392  8b08                 mov ecx, dword ptr [eax]
// 0093c394  80795900             cmp byte ptr [ecx + 0x59], 0
// 0093c398  74f6                 je 0x93c390
// 0093c39a  c3                   ret 
// standard library map_str<pod48> (function ?_Min@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<pod48>
struct E { int v[12]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
