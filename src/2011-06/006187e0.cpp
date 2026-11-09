// from server: 100% by auto
// roc 2011-06 006187e0  unit: RBX::ScriptContext  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006187e0
//
// 006187e0  8b442404             mov eax, dword ptr [esp + 4]
// 006187e4  8b08                 mov ecx, dword ptr [eax]
// 006187e6  80794900             cmp byte ptr [ecx + 0x49], 0
// 006187ea  750e                 jne 0x6187fa
// 006187ec  8d642400             lea esp, [esp]
// 006187f0  8bc1                 mov eax, ecx
// 006187f2  8b08                 mov ecx, dword ptr [eax]
// 006187f4  80794900             cmp byte ptr [ecx + 0x49], 0
// 006187f8  74f6                 je 0x6187f0
// 006187fa  c3                   ret 
// standard library map_str<pod32> (function ?_Min@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
