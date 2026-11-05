// from server: 100% by auto
// roc 2008-06 00670670  unit: RBX::AdornRbxGfx  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00670670
//
// 00670670  64a100000000         mov eax, dword ptr fs:[0]
// 00670676  6aff                 push -1
// 00670678  6868c87d00           push 0x7dc868
// 0067067d  50                   push eax
// 0067067e  64892500000000       mov dword ptr fs:[0], esp
// 00670685  83ec0c               sub esp, 0xc
// 00670688  56                   push esi
// 00670689  8bf1                 mov esi, ecx
// 0067068b  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0067068f  8b4104               mov eax, dword ptr [ecx + 4]
// 00670692  394604               cmp dword ptr [esi + 4], eax
// 00670695  745f                 je 0x6706f6
// 00670697  89442408             mov dword ptr [esp + 8], eax
// 0067069b  8b4108               mov eax, dword ptr [ecx + 8]
// 0067069e  c7442404d4d18400     mov dword ptr [esp + 4], 0x84d1d4
// 006706a6  8944240c             mov dword ptr [esp + 0xc], eax
// 006706aa  85c0                 test eax, eax
// 006706ac  7402                 je 0x6706b0
// 006706ae  ff00                 inc dword ptr [eax]
// 006706b0  8b06                 mov eax, dword ptr [esi]
// 006706b2  8b5008               mov edx, dword ptr [eax + 8]
// 006706b5  8d4c2404             lea ecx, [esp + 4]
// 006706b9  51                   push ecx
// 006706ba  8bce                 mov ecx, esi
// 006706bc  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 006706c4  ffd2                 call edx
// 006706c6  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006706ca  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 006706d2  c7442404d4d18400     mov dword ptr [esp + 4], 0x84d1d4
// 006706da  85c0                 test eax, eax
// 006706dc  7418                 je 0x6706f6
// 006706de  ff08                 dec dword ptr [eax]
// 006706e0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006706e4  833800               cmp dword ptr [eax], 0
// 006706e7  750d                 jne 0x6706f6
// 006706e9  8b542404             mov edx, dword ptr [esp + 4]
// 006706ed  8b4204               mov eax, dword ptr [edx + 4]
// 006706f0  8d4c2404             lea ecx, [esp + 4]
// 006706f4  ffd0                 call eax
// 006706f6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006706fa  8bc6                 mov eax, esi
// 006706fc  5e                   pop esi
// 006706fd  64890d00000000       mov dword ptr fs:[0], ecx
// 00670704  83c418               add esp, 0x18
// 00670707  c20400               ret 4
// library ogre-1.4.9/OgreAlignedAllocator.cpp (function ??4?$SharedPtr@VHardwareVertexBuffer@Ogre@@@Ogre@@QAEAAV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreAlignedAllocator.cpp
