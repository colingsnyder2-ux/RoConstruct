// from server: 100% by auto
// roc 2009-06 0048c310  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048c310
//
// 0048c310  6a6c                 push 0x6c
// 0048c312  e821c72800           call 0x718a38
// 0048c317  83c404               add esp, 4
// 0048c31a  85c0                 test eax, eax
// 0048c31c  7406                 je 0x48c324
// 0048c31e  c70000000000         mov dword ptr [eax], 0
// 0048c324  8d4804               lea ecx, [eax + 4]
// 0048c327  85c9                 test ecx, ecx
// 0048c329  7406                 je 0x48c331
// 0048c32b  c70100000000         mov dword ptr [ecx], 0
// 0048c331  8d4808               lea ecx, [eax + 8]
// 0048c334  85c9                 test ecx, ecx
// 0048c336  7406                 je 0x48c33e
// 0048c338  c70100000000         mov dword ptr [ecx], 0
// 0048c33e  c6406801             mov byte ptr [eax + 0x68], 1
// 0048c342  c6406900             mov byte ptr [eax + 0x69], 0
// 0048c346  c3                   ret 
// standard library map_str<pod64> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@XZ)

// stl: map_str<pod64>
struct E { int v[16]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
