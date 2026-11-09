// from server: 100% by auto
// roc 2011-06 009383e0  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 009383e0
//
// 009383e0  6a6c                 push 0x6c
// 009383e2  e8771cedff           call 0x80a05e
// 009383e7  83c404               add esp, 4
// 009383ea  85c0                 test eax, eax
// 009383ec  7406                 je 0x9383f4
// 009383ee  c70000000000         mov dword ptr [eax], 0
// 009383f4  8d4804               lea ecx, [eax + 4]
// 009383f7  85c9                 test ecx, ecx
// 009383f9  7406                 je 0x938401
// 009383fb  c70100000000         mov dword ptr [ecx], 0
// 00938401  8d4808               lea ecx, [eax + 8]
// 00938404  85c9                 test ecx, ecx
// 00938406  7406                 je 0x93840e
// 00938408  c70100000000         mov dword ptr [ecx], 0
// 0093840e  c6406801             mov byte ptr [eax + 0x68], 1
// 00938412  c6406900             mov byte ptr [eax + 0x69], 0
// 00938416  c3                   ret 
// standard library map_str<pod64> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@XZ)

// stl: map_str<pod64>
struct E { int v[16]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
