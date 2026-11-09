// from server: 100% by auto
// roc 2012-06 0093c360  unit: RBX::AdornBillboarder  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0093c360
//
// 0093c360  8b442404             mov eax, dword ptr [esp + 4]
// 0093c364  8b4808               mov ecx, dword ptr [eax + 8]
// 0093c367  80795900             cmp byte ptr [ecx + 0x59], 0
// 0093c36b  750e                 jne 0x93c37b
// 0093c36d  8d4900               lea ecx, [ecx]
// 0093c370  8bc1                 mov eax, ecx
// 0093c372  8b4808               mov ecx, dword ptr [eax + 8]
// 0093c375  80795900             cmp byte ptr [ecx + 0x59], 0
// 0093c379  74f5                 je 0x93c370
// 0093c37b  c3                   ret 
// standard library map_str<pod48> (function ?_Max@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<pod48>
struct E { int v[12]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
