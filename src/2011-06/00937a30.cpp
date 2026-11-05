// from server: 100% by auto
// roc 2011-06 00937a30  unit: Ogre::VertexStreamer  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00937a30
//
// 00937a30  8b442404             mov eax, dword ptr [esp + 4]
// 00937a34  8b08                 mov ecx, dword ptr [eax]
// 00937a36  80796900             cmp byte ptr [ecx + 0x69], 0
// 00937a3a  750e                 jne 0x937a4a
// 00937a3c  8d642400             lea esp, [esp]
// 00937a40  8bc1                 mov eax, ecx
// 00937a42  8b08                 mov ecx, dword ptr [eax]
// 00937a44  80796900             cmp byte ptr [ecx + 0x69], 0
// 00937a48  74f6                 je 0x937a40
// 00937a4a  c3                   ret 
// standard library map_str<pod64> (function ?_Min@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<pod64>
struct E { int v[16]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
