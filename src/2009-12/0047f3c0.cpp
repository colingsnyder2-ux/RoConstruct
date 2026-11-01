// from server: 100% by auto
// roc 2009-12 0047f3c0  unit: RBX::AdornRbxGfx  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047f3c0
//
// 0047f3c0  64a100000000         mov eax, dword ptr fs:[0]
// 0047f3c6  6aff                 push -1
// 0047f3c8  6868ea9200           push 0x92ea68
// 0047f3cd  50                   push eax
// 0047f3ce  8b442410             mov eax, dword ptr [esp + 0x10]
// 0047f3d2  64892500000000       mov dword ptr fs:[0], esp
// 0047f3d9  83ec10               sub esp, 0x10
// 0047f3dc  56                   push esi
// 0047f3dd  8bf1                 mov esi, ecx
// 0047f3df  8b4804               mov ecx, dword ptr [eax + 4]
// 0047f3e2  394e04               cmp dword ptr [esi + 4], ecx
// 0047f3e5  7466                 je 0x47f44d
// 0047f3e7  894c2408             mov dword ptr [esp + 8], ecx
// 0047f3eb  8b4808               mov ecx, dword ptr [eax + 8]
// 0047f3ee  8b400c               mov eax, dword ptr [eax + 0xc]
// 0047f3f1  c7442404e0219b00     mov dword ptr [esp + 4], 0x9b21e0
// 0047f3f9  894c240c             mov dword ptr [esp + 0xc], ecx
// 0047f3fd  89442410             mov dword ptr [esp + 0x10], eax
// 0047f401  85c9                 test ecx, ecx
// 0047f403  7402                 je 0x47f407
// 0047f405  ff01                 inc dword ptr [ecx]
// 0047f407  8b16                 mov edx, dword ptr [esi]
// 0047f409  8b5208               mov edx, dword ptr [edx + 8]
// 0047f40c  8d442404             lea eax, [esp + 4]
// 0047f410  50                   push eax
// 0047f411  8bce                 mov ecx, esi
// 0047f413  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0047f41b  ffd2                 call edx
// 0047f41d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0047f421  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0047f429  c7442404e0219b00     mov dword ptr [esp + 4], 0x9b21e0
// 0047f431  85c0                 test eax, eax
// 0047f433  7418                 je 0x47f44d
// 0047f435  ff08                 dec dword ptr [eax]
// 0047f437  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0047f43b  833800               cmp dword ptr [eax], 0
// 0047f43e  750d                 jne 0x47f44d
// 0047f440  8b542404             mov edx, dword ptr [esp + 4]
// 0047f444  8b4204               mov eax, dword ptr [edx + 4]
// 0047f447  8d4c2404             lea ecx, [esp + 4]
// 0047f44b  ffd0                 call eax
// 0047f44d  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0047f451  8bc6                 mov eax, esi
// 0047f453  5e                   pop esi
// 0047f454  64890d00000000       mov dword ptr fs:[0], ecx
// 0047f45b  83c41c               add esp, 0x1c
// 0047f45e  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??4?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@QAEAAV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
