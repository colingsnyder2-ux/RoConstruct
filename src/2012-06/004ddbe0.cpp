// from server: 100% by auto
// roc 2012-06 004ddbe0  unit: Ogre::VertexStreamer  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004ddbe0
//
// 004ddbe0  8b442404             mov eax, dword ptr [esp + 4]
// 004ddbe4  8b4808               mov ecx, dword ptr [eax + 8]
// 004ddbe7  80796900             cmp byte ptr [ecx + 0x69], 0
// 004ddbeb  750e                 jne 0x4ddbfb
// 004ddbed  8d4900               lea ecx, [ecx]
// 004ddbf0  8bc1                 mov eax, ecx
// 004ddbf2  8b4808               mov ecx, dword ptr [eax + 8]
// 004ddbf5  80796900             cmp byte ptr [ecx + 0x69], 0
// 004ddbf9  74f5                 je 0x4ddbf0
// 004ddbfb  c3                   ret 
// standard library map_str<pod64> (function ?_Max@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<pod64>
struct E { int v[16]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
