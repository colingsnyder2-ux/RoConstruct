// from server: 100% by auto
// roc 2009-06 006fd3e0  unit: RBX::AdornRbxGfx  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fd3e0
//
// 006fd3e0  64a100000000         mov eax, dword ptr fs:[0]
// 006fd3e6  6aff                 push -1
// 006fd3e8  68182a8700           push 0x872a18
// 006fd3ed  50                   push eax
// 006fd3ee  64892500000000       mov dword ptr fs:[0], esp
// 006fd3f5  83ec0c               sub esp, 0xc
// 006fd3f8  56                   push esi
// 006fd3f9  8bf1                 mov esi, ecx
// 006fd3fb  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006fd3ff  8b4104               mov eax, dword ptr [ecx + 4]
// 006fd402  394604               cmp dword ptr [esi + 4], eax
// 006fd405  745f                 je 0x6fd466
// 006fd407  89442408             mov dword ptr [esp + 8], eax
// 006fd40b  8b4108               mov eax, dword ptr [ecx + 8]
// 006fd40e  c744240444eb8e00     mov dword ptr [esp + 4], 0x8eeb44
// 006fd416  8944240c             mov dword ptr [esp + 0xc], eax
// 006fd41a  85c0                 test eax, eax
// 006fd41c  7402                 je 0x6fd420
// 006fd41e  ff00                 inc dword ptr [eax]
// 006fd420  8b06                 mov eax, dword ptr [esi]
// 006fd422  8b5008               mov edx, dword ptr [eax + 8]
// 006fd425  8d4c2404             lea ecx, [esp + 4]
// 006fd429  51                   push ecx
// 006fd42a  8bce                 mov ecx, esi
// 006fd42c  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 006fd434  ffd2                 call edx
// 006fd436  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006fd43a  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 006fd442  c744240444eb8e00     mov dword ptr [esp + 4], 0x8eeb44
// 006fd44a  85c0                 test eax, eax
// 006fd44c  7418                 je 0x6fd466
// 006fd44e  ff08                 dec dword ptr [eax]
// 006fd450  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006fd454  833800               cmp dword ptr [eax], 0
// 006fd457  750d                 jne 0x6fd466
// 006fd459  8b542404             mov edx, dword ptr [esp + 4]
// 006fd45d  8b4204               mov eax, dword ptr [edx + 4]
// 006fd460  8d4c2404             lea ecx, [esp + 4]
// 006fd464  ffd0                 call eax
// 006fd466  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006fd46a  8bc6                 mov eax, esi
// 006fd46c  5e                   pop esi
// 006fd46d  64890d00000000       mov dword ptr fs:[0], ecx
// 006fd474  83c418               add esp, 0x18
// 006fd477  c20400               ret 4
// library ogre-1.4.9/OgreAlignedAllocator.cpp (function ??4?$SharedPtr@VHardwareVertexBuffer@Ogre@@@Ogre@@QAEAAV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreAlignedAllocator.cpp
