// from server: 100% by auto
// roc 2011-06 00937a10  unit: Ogre::VertexStreamer  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00937a10
//
// 00937a10  8b442404             mov eax, dword ptr [esp + 4]
// 00937a14  8b4808               mov ecx, dword ptr [eax + 8]
// 00937a17  80796900             cmp byte ptr [ecx + 0x69], 0
// 00937a1b  750e                 jne 0x937a2b
// 00937a1d  8d4900               lea ecx, [ecx]
// 00937a20  8bc1                 mov eax, ecx
// 00937a22  8b4808               mov ecx, dword ptr [eax + 8]
// 00937a25  80796900             cmp byte ptr [ecx + 0x69], 0
// 00937a29  74f5                 je 0x937a20
// 00937a2b  c3                   ret 
// standard library map_str<pod64> (function ?_Max@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<pod64>
struct E { int v[16]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
