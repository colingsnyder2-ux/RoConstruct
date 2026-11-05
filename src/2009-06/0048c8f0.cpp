// from server: 100% by auto
// roc 2009-06 0048c8f0  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048c8f0
//
// 0048c8f0  6aff                 push -1
// 0048c8f2  6878ef8600           push 0x86ef78
// 0048c8f7  64a100000000         mov eax, dword ptr fs:[0]
// 0048c8fd  50                   push eax
// 0048c8fe  64892500000000       mov dword ptr fs:[0], esp
// 0048c905  51                   push ecx
// 0048c906  56                   push esi
// 0048c907  8bf1                 mov esi, ecx
// 0048c909  6a04                 push 4
// 0048c90b  89742408             mov dword ptr [esp + 8], esi
// 0048c90f  e824c12800           call 0x718a38
// 0048c914  83c404               add esp, 4
// 0048c917  85c0                 test eax, eax
// 0048c919  7404                 je 0x48c91f
// 0048c91b  8930                 mov dword ptr [eax], esi
// 0048c91d  eb02                 jmp 0x48c921
// 0048c91f  33c0                 xor eax, eax
// 0048c921  8906                 mov dword ptr [esi], eax
// 0048c923  8bce                 mov ecx, esi
// 0048c925  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0048c92d  e8def9ffff           call 0x48c310
// 0048c932  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0048c936  894618               mov dword ptr [esi + 0x18], eax
// 0048c939  c6406901             mov byte ptr [eax + 0x69], 1
// 0048c93d  8b4618               mov eax, dword ptr [esi + 0x18]
// 0048c940  894004               mov dword ptr [eax + 4], eax
// 0048c943  8b4618               mov eax, dword ptr [esi + 0x18]
// 0048c946  8900                 mov dword ptr [eax], eax
// 0048c948  8b4618               mov eax, dword ptr [esi + 0x18]
// 0048c94b  894008               mov dword ptr [eax + 8], eax
// 0048c94e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0048c955  8bc6                 mov eax, esi
// 0048c957  5e                   pop esi
// 0048c958  64890d00000000       mov dword ptr fs:[0], ecx
// 0048c95f  83c410               add esp, 0x10
// 0048c962  c20800               ret 8
// standard library map_str<pod64> (function ??0?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE@ABU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@1@ABV?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@1@@Z)

// stl: map_str<pod64>
struct E { int v[16]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
