// from server: 100% by auto
// roc 2008-06 0068ff50  unit: Ogre::RbxSceneManagerFactory  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068ff50
//
// 0068ff50  64a100000000         mov eax, dword ptr fs:[0]
// 0068ff56  6aff                 push -1
// 0068ff58  68c8e27d00           push 0x7de2c8
// 0068ff5d  50                   push eax
// 0068ff5e  64892500000000       mov dword ptr fs:[0], esp
// 0068ff65  83ec0c               sub esp, 0xc
// 0068ff68  56                   push esi
// 0068ff69  8bf1                 mov esi, ecx
// 0068ff6b  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0068ff6f  8b4104               mov eax, dword ptr [ecx + 4]
// 0068ff72  394604               cmp dword ptr [esi + 4], eax
// 0068ff75  745f                 je 0x68ffd6
// 0068ff77  89442408             mov dword ptr [esp + 8], eax
// 0068ff7b  8b4108               mov eax, dword ptr [ecx + 8]
// 0068ff7e  c74424044cec8400     mov dword ptr [esp + 4], 0x84ec4c
// 0068ff86  8944240c             mov dword ptr [esp + 0xc], eax
// 0068ff8a  85c0                 test eax, eax
// 0068ff8c  7402                 je 0x68ff90
// 0068ff8e  ff00                 inc dword ptr [eax]
// 0068ff90  8b06                 mov eax, dword ptr [esi]
// 0068ff92  8b5008               mov edx, dword ptr [eax + 8]
// 0068ff95  8d4c2404             lea ecx, [esp + 4]
// 0068ff99  51                   push ecx
// 0068ff9a  8bce                 mov ecx, esi
// 0068ff9c  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0068ffa4  ffd2                 call edx
// 0068ffa6  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0068ffaa  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0068ffb2  c74424044cec8400     mov dword ptr [esp + 4], 0x84ec4c
// 0068ffba  85c0                 test eax, eax
// 0068ffbc  7418                 je 0x68ffd6
// 0068ffbe  ff08                 dec dword ptr [eax]
// 0068ffc0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0068ffc4  833800               cmp dword ptr [eax], 0
// 0068ffc7  750d                 jne 0x68ffd6
// 0068ffc9  8b542404             mov edx, dword ptr [esp + 4]
// 0068ffcd  8b4204               mov eax, dword ptr [edx + 4]
// 0068ffd0  8d4c2404             lea ecx, [esp + 4]
// 0068ffd4  ffd0                 call eax
// 0068ffd6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0068ffda  8bc6                 mov eax, esi
// 0068ffdc  5e                   pop esi
// 0068ffdd  64890d00000000       mov dword ptr fs:[0], ecx
// 0068ffe4  83c418               add esp, 0x18
// 0068ffe7  c20400               ret 4
// library ogre-1.4.9/OgreAlignedAllocator.cpp (function ??4?$SharedPtr@VHardwareVertexBuffer@Ogre@@@Ogre@@QAEAAV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreAlignedAllocator.cpp
