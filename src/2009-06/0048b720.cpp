// from server: 100% by auto
// roc 2009-06 0048b720  unit: Ogre::RbxManualTextureLoader  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048b720
//
// 0048b720  8b442404             mov eax, dword ptr [esp + 4]
// 0048b724  8b08                 mov ecx, dword ptr [eax]
// 0048b726  80796900             cmp byte ptr [ecx + 0x69], 0
// 0048b72a  750e                 jne 0x48b73a
// 0048b72c  8d642400             lea esp, [esp]
// 0048b730  8bc1                 mov eax, ecx
// 0048b732  8b08                 mov ecx, dword ptr [eax]
// 0048b734  80796900             cmp byte ptr [ecx + 0x69], 0
// 0048b738  74f6                 je 0x48b730
// 0048b73a  c3                   ret 
// standard library map_str<pod64> (function ?_Min@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<pod64>
struct E { int v[16]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
