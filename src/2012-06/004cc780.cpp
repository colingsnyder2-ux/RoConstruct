// from server: 100% by auto
// roc 2012-06 004cc780  unit: std::D::DU?$char_traits::V?$basic_string::V?$_Tset_traits::?$_Tree_nod::PAU_Node::?$STLAllocator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004cc780
//
// 004cc780  8b442404             mov eax, dword ptr [esp + 4]
// 004cc784  8b4808               mov ecx, dword ptr [eax + 8]
// 004cc787  80794500             cmp byte ptr [ecx + 0x45], 0
// 004cc78b  750e                 jne 0x4cc79b
// 004cc78d  8d4900               lea ecx, [ecx]
// 004cc790  8bc1                 mov eax, ecx
// 004cc792  8b4808               mov ecx, dword ptr [eax + 8]
// 004cc795  80794500             cmp byte ptr [ecx + 0x45], 0
// 004cc799  74f5                 je 0x4cc790
// 004cc79b  c3                   ret 
// standard library map_str<string> (function ?_Max@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
