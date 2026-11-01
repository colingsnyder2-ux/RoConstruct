// from server: 100% by auto
// roc 2011-06 0091de70  unit: Ogre::VResource::?$SharedPtr  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0091de70
//
// 0091de70  64a100000000         mov eax, dword ptr fs:[0]
// 0091de76  6aff                 push -1
// 0091de78  68282ea100           push 0xa12e28
// 0091de7d  50                   push eax
// 0091de7e  8b442410             mov eax, dword ptr [esp + 0x10]
// 0091de82  64892500000000       mov dword ptr fs:[0], esp
// 0091de89  83ec10               sub esp, 0x10
// 0091de8c  56                   push esi
// 0091de8d  8bf1                 mov esi, ecx
// 0091de8f  8b4804               mov ecx, dword ptr [eax + 4]
// 0091de92  394e04               cmp dword ptr [esi + 4], ecx
// 0091de95  7466                 je 0x91defd
// 0091de97  894c2408             mov dword ptr [esp + 8], ecx
// 0091de9b  8b4808               mov ecx, dword ptr [eax + 8]
// 0091de9e  8b400c               mov eax, dword ptr [eax + 0xc]
// 0091dea1  c74424044044af00     mov dword ptr [esp + 4], 0xaf4440
// 0091dea9  894c240c             mov dword ptr [esp + 0xc], ecx
// 0091dead  89442410             mov dword ptr [esp + 0x10], eax
// 0091deb1  85c9                 test ecx, ecx
// 0091deb3  7402                 je 0x91deb7
// 0091deb5  ff01                 inc dword ptr [ecx]
// 0091deb7  8b16                 mov edx, dword ptr [esi]
// 0091deb9  8b5208               mov edx, dword ptr [edx + 8]
// 0091debc  8d442404             lea eax, [esp + 4]
// 0091dec0  50                   push eax
// 0091dec1  8bce                 mov ecx, esi
// 0091dec3  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0091decb  ffd2                 call edx
// 0091decd  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0091ded1  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0091ded9  c74424044044af00     mov dword ptr [esp + 4], 0xaf4440
// 0091dee1  85c0                 test eax, eax
// 0091dee3  7418                 je 0x91defd
// 0091dee5  ff08                 dec dword ptr [eax]
// 0091dee7  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0091deeb  833800               cmp dword ptr [eax], 0
// 0091deee  750d                 jne 0x91defd
// 0091def0  8b542404             mov edx, dword ptr [esp + 4]
// 0091def4  8b4204               mov eax, dword ptr [edx + 4]
// 0091def7  8d4c2404             lea ecx, [esp + 4]
// 0091defb  ffd0                 call eax
// 0091defd  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0091df01  8bc6                 mov eax, esi
// 0091df03  5e                   pop esi
// 0091df04  64890d00000000       mov dword ptr fs:[0], ecx
// 0091df0b  83c41c               add esp, 0x1c
// 0091df0e  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??4?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@QAEAAV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
