// from server: 100% by auto
// roc 2009-12 004af0b0  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004af0b0
//
// 004af0b0  6aff                 push -1
// 004af0b2  68d8c59300           push 0x93c5d8
// 004af0b7  64a100000000         mov eax, dword ptr fs:[0]
// 004af0bd  50                   push eax
// 004af0be  64892500000000       mov dword ptr fs:[0], esp
// 004af0c5  51                   push ecx
// 004af0c6  56                   push esi
// 004af0c7  8bf1                 mov esi, ecx
// 004af0c9  6a04                 push 4
// 004af0cb  89742408             mov dword ptr [esp + 8], esi
// 004af0cf  e88c473400           call 0x7f3860
// 004af0d4  83c404               add esp, 4
// 004af0d7  85c0                 test eax, eax
// 004af0d9  7404                 je 0x4af0df
// 004af0db  8930                 mov dword ptr [eax], esi
// 004af0dd  eb02                 jmp 0x4af0e1
// 004af0df  33c0                 xor eax, eax
// 004af0e1  8906                 mov dword ptr [esi], eax
// 004af0e3  8bce                 mov ecx, esi
// 004af0e5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004af0ed  e88ef9ffff           call 0x4aea80
// 004af0f2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004af0f6  894618               mov dword ptr [esi + 0x18], eax
// 004af0f9  c6406901             mov byte ptr [eax + 0x69], 1
// 004af0fd  8b4618               mov eax, dword ptr [esi + 0x18]
// 004af100  894004               mov dword ptr [eax + 4], eax
// 004af103  8b4618               mov eax, dword ptr [esi + 0x18]
// 004af106  8900                 mov dword ptr [eax], eax
// 004af108  8b4618               mov eax, dword ptr [esi + 0x18]
// 004af10b  894008               mov dword ptr [eax + 8], eax
// 004af10e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004af115  8bc6                 mov eax, esi
// 004af117  5e                   pop esi
// 004af118  64890d00000000       mov dword ptr fs:[0], ecx
// 004af11f  83c410               add esp, 0x10
// 004af122  c20800               ret 8
// standard library map_str<pod64> (function ??0?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE@ABU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@1@ABV?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@1@@Z)

// stl: map_str<pod64>
struct E { int v[16]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
