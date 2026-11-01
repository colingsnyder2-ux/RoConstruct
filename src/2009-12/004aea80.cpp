// from server: 100% by auto
// roc 2009-12 004aea80  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004aea80
//
// 004aea80  6a6c                 push 0x6c
// 004aea82  e8d94d3400           call 0x7f3860
// 004aea87  83c404               add esp, 4
// 004aea8a  85c0                 test eax, eax
// 004aea8c  7406                 je 0x4aea94
// 004aea8e  c70000000000         mov dword ptr [eax], 0
// 004aea94  8d4804               lea ecx, [eax + 4]
// 004aea97  85c9                 test ecx, ecx
// 004aea99  7406                 je 0x4aeaa1
// 004aea9b  c70100000000         mov dword ptr [ecx], 0
// 004aeaa1  8d4808               lea ecx, [eax + 8]
// 004aeaa4  85c9                 test ecx, ecx
// 004aeaa6  7406                 je 0x4aeaae
// 004aeaa8  c70100000000         mov dword ptr [ecx], 0
// 004aeaae  c6406801             mov byte ptr [eax + 0x68], 1
// 004aeab2  c6406900             mov byte ptr [eax + 0x69], 0
// 004aeab6  c3                   ret 
// standard library map_str<pod64> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@XZ)

// stl: map_str<pod64>
struct E { int v[16]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
