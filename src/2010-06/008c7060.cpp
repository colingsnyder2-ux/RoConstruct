// from server: 100% by auto
// roc 2010-06 008c7060  unit: RBX::AdornRbxGfx  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008c7060
//
// 008c7060  64a100000000         mov eax, dword ptr fs:[0]
// 008c7066  6aff                 push -1
// 008c7068  6868d09b00           push 0x9bd068
// 008c706d  50                   push eax
// 008c706e  8b442410             mov eax, dword ptr [esp + 0x10]
// 008c7072  64892500000000       mov dword ptr fs:[0], esp
// 008c7079  83ec10               sub esp, 0x10
// 008c707c  56                   push esi
// 008c707d  8bf1                 mov esi, ecx
// 008c707f  8b4804               mov ecx, dword ptr [eax + 4]
// 008c7082  394e04               cmp dword ptr [esi + 4], ecx
// 008c7085  7466                 je 0x8c70ed
// 008c7087  894c2408             mov dword ptr [esp + 8], ecx
// 008c708b  8b4808               mov ecx, dword ptr [eax + 8]
// 008c708e  8b400c               mov eax, dword ptr [eax + 0xc]
// 008c7091  c74424046081a800     mov dword ptr [esp + 4], 0xa88160
// 008c7099  894c240c             mov dword ptr [esp + 0xc], ecx
// 008c709d  89442410             mov dword ptr [esp + 0x10], eax
// 008c70a1  85c9                 test ecx, ecx
// 008c70a3  7402                 je 0x8c70a7
// 008c70a5  ff01                 inc dword ptr [ecx]
// 008c70a7  8b16                 mov edx, dword ptr [esi]
// 008c70a9  8b5208               mov edx, dword ptr [edx + 8]
// 008c70ac  8d442404             lea eax, [esp + 4]
// 008c70b0  50                   push eax
// 008c70b1  8bce                 mov ecx, esi
// 008c70b3  c744242000000000     mov dword ptr [esp + 0x20], 0
// 008c70bb  ffd2                 call edx
// 008c70bd  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008c70c1  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 008c70c9  c74424046081a800     mov dword ptr [esp + 4], 0xa88160
// 008c70d1  85c0                 test eax, eax
// 008c70d3  7418                 je 0x8c70ed
// 008c70d5  ff08                 dec dword ptr [eax]
// 008c70d7  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008c70db  833800               cmp dword ptr [eax], 0
// 008c70de  750d                 jne 0x8c70ed
// 008c70e0  8b542404             mov edx, dword ptr [esp + 4]
// 008c70e4  8b4204               mov eax, dword ptr [edx + 4]
// 008c70e7  8d4c2404             lea ecx, [esp + 4]
// 008c70eb  ffd0                 call eax
// 008c70ed  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008c70f1  8bc6                 mov eax, esi
// 008c70f3  5e                   pop esi
// 008c70f4  64890d00000000       mov dword ptr fs:[0], ecx
// 008c70fb  83c41c               add esp, 0x1c
// 008c70fe  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ??4?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@QAEAAV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
