// from server: 100% by auto
// roc 2012-06 0040ab50  unit: RBX::VScriptContext::?$FactoryProduct::Creator  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0040ab50
//
// 0040ab50  8b442404             mov eax, dword ptr [esp + 4]
// 0040ab54  8b08                 mov ecx, dword ptr [eax]
// 0040ab56  80794500             cmp byte ptr [ecx + 0x45], 0
// 0040ab5a  750e                 jne 0x40ab6a
// 0040ab5c  8d642400             lea esp, [esp]
// 0040ab60  8bc1                 mov eax, ecx
// 0040ab62  8b08                 mov ecx, dword ptr [eax]
// 0040ab64  80794500             cmp byte ptr [ecx + 0x45], 0
// 0040ab68  74f6                 je 0x40ab60
// 0040ab6a  c3                   ret 
// standard library map_str<string> (function ?_Min@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
