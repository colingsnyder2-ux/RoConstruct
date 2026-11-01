// from server: 100% by auto
// roc 2010-06 008c3c70  unit: Ogre::VResource::?$SharedPtr  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008c3c70
//
// 008c3c70  64a100000000         mov eax, dword ptr fs:[0]
// 008c3c76  6aff                 push -1
// 008c3c78  68e8fb9b00           push 0x9bfbe8
// 008c3c7d  50                   push eax
// 008c3c7e  8b442410             mov eax, dword ptr [esp + 0x10]
// 008c3c82  64892500000000       mov dword ptr fs:[0], esp
// 008c3c89  83ec10               sub esp, 0x10
// 008c3c8c  56                   push esi
// 008c3c8d  8bf1                 mov esi, ecx
// 008c3c8f  8b4804               mov ecx, dword ptr [eax + 4]
// 008c3c92  394e04               cmp dword ptr [esi + 4], ecx
// 008c3c95  7466                 je 0x8c3cfd
// 008c3c97  894c2408             mov dword ptr [esp + 8], ecx
// 008c3c9b  8b4808               mov ecx, dword ptr [eax + 8]
// 008c3c9e  8b400c               mov eax, dword ptr [eax + 0xc]
// 008c3ca1  c74424044c7fa800     mov dword ptr [esp + 4], 0xa87f4c
// 008c3ca9  894c240c             mov dword ptr [esp + 0xc], ecx
// 008c3cad  89442410             mov dword ptr [esp + 0x10], eax
// 008c3cb1  85c9                 test ecx, ecx
// 008c3cb3  7402                 je 0x8c3cb7
// 008c3cb5  ff01                 inc dword ptr [ecx]
// 008c3cb7  8b16                 mov edx, dword ptr [esi]
// 008c3cb9  8b5208               mov edx, dword ptr [edx + 8]
// 008c3cbc  8d442404             lea eax, [esp + 4]
// 008c3cc0  50                   push eax
// 008c3cc1  8bce                 mov ecx, esi
// 008c3cc3  c744242000000000     mov dword ptr [esp + 0x20], 0
// 008c3ccb  ffd2                 call edx
// 008c3ccd  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008c3cd1  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 008c3cd9  c74424044c7fa800     mov dword ptr [esp + 4], 0xa87f4c
// 008c3ce1  85c0                 test eax, eax
// 008c3ce3  7418                 je 0x8c3cfd
// 008c3ce5  ff08                 dec dword ptr [eax]
// 008c3ce7  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008c3ceb  833800               cmp dword ptr [eax], 0
// 008c3cee  750d                 jne 0x8c3cfd
// 008c3cf0  8b542404             mov edx, dword ptr [esp + 4]
// 008c3cf4  8b4204               mov eax, dword ptr [edx + 4]
// 008c3cf7  8d4c2404             lea ecx, [esp + 4]
// 008c3cfb  ffd0                 call eax
// 008c3cfd  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008c3d01  8bc6                 mov eax, esi
// 008c3d03  5e                   pop esi
// 008c3d04  64890d00000000       mov dword ptr fs:[0], ecx
// 008c3d0b  83c41c               add esp, 0x1c
// 008c3d0e  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??4?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@QAEAAV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
