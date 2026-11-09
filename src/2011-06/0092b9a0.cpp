// from server: 100% by auto
// roc 2011-06 0092b9a0  unit: std::D::DU?$char_traits::V?$basic_string::V?$_Tset_traits::?$_Tree_nod::PAU_Node::?$STLAllocator  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0092b9a0
//
// 0092b9a0  8b442404             mov eax, dword ptr [esp + 4]
// 0092b9a4  8b08                 mov ecx, dword ptr [eax]
// 0092b9a6  80794500             cmp byte ptr [ecx + 0x45], 0
// 0092b9aa  750e                 jne 0x92b9ba
// 0092b9ac  8d642400             lea esp, [esp]
// 0092b9b0  8bc1                 mov eax, ecx
// 0092b9b2  8b08                 mov ecx, dword ptr [eax]
// 0092b9b4  80794500             cmp byte ptr [ecx + 0x45], 0
// 0092b9b8  74f6                 je 0x92b9b0
// 0092b9ba  c3                   ret 
// standard library map_str<string> (function ?_Min@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
