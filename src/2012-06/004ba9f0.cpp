// from server: 100% by auto
// roc 2012-06 004ba9f0  unit: Ogre::VResource::?$SharedPtr  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004ba9f0
//
// 004ba9f0  64a100000000         mov eax, dword ptr fs:[0]
// 004ba9f6  6aff                 push -1
// 004ba9f8  681856aa00           push 0xaa5618
// 004ba9fd  50                   push eax
// 004ba9fe  8b442410             mov eax, dword ptr [esp + 0x10]
// 004baa02  64892500000000       mov dword ptr fs:[0], esp
// 004baa09  83ec10               sub esp, 0x10
// 004baa0c  56                   push esi
// 004baa0d  8bf1                 mov esi, ecx
// 004baa0f  8b4804               mov ecx, dword ptr [eax + 4]
// 004baa12  394e04               cmp dword ptr [esi + 4], ecx
// 004baa15  7466                 je 0x4baa7d
// 004baa17  894c2408             mov dword ptr [esp + 8], ecx
// 004baa1b  8b4808               mov ecx, dword ptr [eax + 8]
// 004baa1e  8b400c               mov eax, dword ptr [eax + 0xc]
// 004baa21  c74424047c44b600     mov dword ptr [esp + 4], 0xb6447c
// 004baa29  894c240c             mov dword ptr [esp + 0xc], ecx
// 004baa2d  89442410             mov dword ptr [esp + 0x10], eax
// 004baa31  85c9                 test ecx, ecx
// 004baa33  7402                 je 0x4baa37
// 004baa35  ff01                 inc dword ptr [ecx]
// 004baa37  8b16                 mov edx, dword ptr [esi]
// 004baa39  8b5208               mov edx, dword ptr [edx + 8]
// 004baa3c  8d442404             lea eax, [esp + 4]
// 004baa40  50                   push eax
// 004baa41  8bce                 mov ecx, esi
// 004baa43  c744242000000000     mov dword ptr [esp + 0x20], 0
// 004baa4b  ffd2                 call edx
// 004baa4d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004baa51  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 004baa59  c74424047c44b600     mov dword ptr [esp + 4], 0xb6447c
// 004baa61  85c0                 test eax, eax
// 004baa63  7418                 je 0x4baa7d
// 004baa65  ff08                 dec dword ptr [eax]
// 004baa67  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004baa6b  833800               cmp dword ptr [eax], 0
// 004baa6e  750d                 jne 0x4baa7d
// 004baa70  8b542404             mov edx, dword ptr [esp + 4]
// 004baa74  8b4204               mov eax, dword ptr [edx + 4]
// 004baa77  8d4c2404             lea ecx, [esp + 4]
// 004baa7b  ffd0                 call eax
// 004baa7d  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004baa81  8bc6                 mov eax, esi
// 004baa83  5e                   pop esi
// 004baa84  64890d00000000       mov dword ptr fs:[0], ecx
// 004baa8b  83c41c               add esp, 0x1c
// 004baa8e  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??4?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@QAEAAV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
