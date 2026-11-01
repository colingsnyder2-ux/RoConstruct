// from server: 100% by auto
// roc 2009-12 004ae090  unit: Ogre::RbxManualTextureLoader  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004ae090
//
// 004ae090  8b442404             mov eax, dword ptr [esp + 4]
// 004ae094  8b4808               mov ecx, dword ptr [eax + 8]
// 004ae097  80796900             cmp byte ptr [ecx + 0x69], 0
// 004ae09b  750e                 jne 0x4ae0ab
// 004ae09d  8d4900               lea ecx, [ecx]
// 004ae0a0  8bc1                 mov eax, ecx
// 004ae0a2  8b4808               mov ecx, dword ptr [eax + 8]
// 004ae0a5  80796900             cmp byte ptr [ecx + 0x69], 0
// 004ae0a9  74f5                 je 0x4ae0a0
// 004ae0ab  c3                   ret 
// standard library map_str<pod64> (function ?_Max@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<pod64>
struct E { int v[16]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
