// from server: 100% by auto
// roc 2009-06 0048c220  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048c220
//
// 0048c220  64a100000000         mov eax, dword ptr fs:[0]
// 0048c226  6aff                 push -1
// 0048c228  6888538500           push 0x855388
// 0048c22d  50                   push eax
// 0048c22e  64892500000000       mov dword ptr fs:[0], esp
// 0048c235  83ec0c               sub esp, 0xc
// 0048c238  56                   push esi
// 0048c239  8bf1                 mov esi, ecx
// 0048c23b  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0048c23f  8b4104               mov eax, dword ptr [ecx + 4]
// 0048c242  394604               cmp dword ptr [esi + 4], eax
// 0048c245  745f                 je 0x48c2a6
// 0048c247  89442408             mov dword ptr [esp + 8], eax
// 0048c24b  8b4108               mov eax, dword ptr [ecx + 8]
// 0048c24e  c744240404dc8b00     mov dword ptr [esp + 4], 0x8bdc04
// 0048c256  8944240c             mov dword ptr [esp + 0xc], eax
// 0048c25a  85c0                 test eax, eax
// 0048c25c  7402                 je 0x48c260
// 0048c25e  ff00                 inc dword ptr [eax]
// 0048c260  8b06                 mov eax, dword ptr [esi]
// 0048c262  8b5008               mov edx, dword ptr [eax + 8]
// 0048c265  8d4c2404             lea ecx, [esp + 4]
// 0048c269  51                   push ecx
// 0048c26a  8bce                 mov ecx, esi
// 0048c26c  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0048c274  ffd2                 call edx
// 0048c276  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0048c27a  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0048c282  c744240404dc8b00     mov dword ptr [esp + 4], 0x8bdc04
// 0048c28a  85c0                 test eax, eax
// 0048c28c  7418                 je 0x48c2a6
// 0048c28e  ff08                 dec dword ptr [eax]
// 0048c290  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0048c294  833800               cmp dword ptr [eax], 0
// 0048c297  750d                 jne 0x48c2a6
// 0048c299  8b542404             mov edx, dword ptr [esp + 4]
// 0048c29d  8b4204               mov eax, dword ptr [edx + 4]
// 0048c2a0  8d4c2404             lea ecx, [esp + 4]
// 0048c2a4  ffd0                 call eax
// 0048c2a6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0048c2aa  8bc6                 mov eax, esi
// 0048c2ac  5e                   pop esi
// 0048c2ad  64890d00000000       mov dword ptr fs:[0], ecx
// 0048c2b4  83c418               add esp, 0x18
// 0048c2b7  c20400               ret 4
// library ogre-1.4.9/OgreAlignedAllocator.cpp (function ??4?$SharedPtr@VHardwareVertexBuffer@Ogre@@@Ogre@@QAEAAV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreAlignedAllocator.cpp
