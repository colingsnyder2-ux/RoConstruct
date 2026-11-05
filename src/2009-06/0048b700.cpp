// from server: 100% by auto
// roc 2009-06 0048b700  unit: Ogre::RbxManualTextureLoader  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048b700
//
// 0048b700  8b442404             mov eax, dword ptr [esp + 4]
// 0048b704  8b4808               mov ecx, dword ptr [eax + 8]
// 0048b707  80796900             cmp byte ptr [ecx + 0x69], 0
// 0048b70b  750e                 jne 0x48b71b
// 0048b70d  8d4900               lea ecx, [ecx]
// 0048b710  8bc1                 mov eax, ecx
// 0048b712  8b4808               mov ecx, dword ptr [eax + 8]
// 0048b715  80796900             cmp byte ptr [ecx + 0x69], 0
// 0048b719  74f5                 je 0x48b710
// 0048b71b  c3                   ret 
// standard library map_str<pod64> (function ?_Max@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// stl: map_str<pod64>
struct E { int v[16]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
