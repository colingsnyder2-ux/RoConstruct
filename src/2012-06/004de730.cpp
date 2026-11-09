// from server: 100% by auto
// roc 2012-06 004de730  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004de730
//
// 004de730  6a6c                 push 0x6c
// 004de732  e8e3394a00           call 0x98211a
// 004de737  83c404               add esp, 4
// 004de73a  85c0                 test eax, eax
// 004de73c  7406                 je 0x4de744
// 004de73e  c70000000000         mov dword ptr [eax], 0
// 004de744  8d4804               lea ecx, [eax + 4]
// 004de747  85c9                 test ecx, ecx
// 004de749  7406                 je 0x4de751
// 004de74b  c70100000000         mov dword ptr [ecx], 0
// 004de751  8d4808               lea ecx, [eax + 8]
// 004de754  85c9                 test ecx, ecx
// 004de756  7406                 je 0x4de75e
// 004de758  c70100000000         mov dword ptr [ecx], 0
// 004de75e  c6406801             mov byte ptr [eax + 0x68], 1
// 004de762  c6406900             mov byte ptr [eax + 0x69], 0
// 004de766  c3                   ret 
// standard library map_str<pod64> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@XZ)

// stl: map_str<pod64>
struct E { int v[16]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
