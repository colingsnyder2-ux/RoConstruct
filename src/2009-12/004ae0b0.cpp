// from server: 100% by auto
// roc 2009-12 004ae0b0  unit: Ogre::RbxManualTextureLoader  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004ae0b0
//
// 004ae0b0  8b442404             mov eax, dword ptr [esp + 4]
// 004ae0b4  8b08                 mov ecx, dword ptr [eax]
// 004ae0b6  80796900             cmp byte ptr [ecx + 0x69], 0
// 004ae0ba  750e                 jne 0x4ae0ca
// 004ae0bc  8d642400             lea esp, [esp]
// 004ae0c0  8bc1                 mov eax, ecx
// 004ae0c2  8b08                 mov ecx, dword ptr [eax]
// 004ae0c4  80796900             cmp byte ptr [ecx + 0x69], 0
// 004ae0c8  74f6                 je 0x4ae0c0
// 004ae0ca  c3                   ret 
// standard library map_str<pod64> (function ?_Min@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<pod64>
struct E { int v[16]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
