// from server: 100% by EspClaude
// roc 2009-06 004984a0  unit: Ogre::UFileInfo::V?$vector::?$SharedPtr  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004984a0
//
// 004984a0  56                   push esi
// 004984a1  8b742408             mov esi, dword ptr [esp + 8]
// 004984a5  3b74240c             cmp esi, dword ptr [esp + 0xc]
// 004984a9  744a                 je 0x4984f5
// 004984ab  53                   push ebx
// 004984ac  55                   push ebp
// 004984ad  57                   push edi
// 004984ae  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 004984b2  8d5f04               lea ebx, [edi + 4]
// 004984b5  8d6f20               lea ebp, [edi + 0x20]
// 004984b8  8b07                 mov eax, dword ptr [edi]
// 004984ba  53                   push ebx
// 004984bb  8d4e04               lea ecx, [esi + 4]
// 004984be  8906                 mov dword ptr [esi], eax
// 004984c0  ff1564e48900         call dword ptr [0x89e464]
// 004984c6  55                   push ebp
// 004984c7  8d4e20               lea ecx, [esi + 0x20]
// 004984ca  ff1564e48900         call dword ptr [0x89e464]
// 004984d0  8d473c               lea eax, [edi + 0x3c]
// 004984d3  50                   push eax
// 004984d4  8d4e3c               lea ecx, [esi + 0x3c]
// 004984d7  ff1564e48900         call dword ptr [0x89e464]
// 004984dd  8b4f58               mov ecx, dword ptr [edi + 0x58]
// 004984e0  894e58               mov dword ptr [esi + 0x58], ecx
// 004984e3  8b575c               mov edx, dword ptr [edi + 0x5c]
// 004984e6  89565c               mov dword ptr [esi + 0x5c], edx
// 004984e9  83c660               add esi, 0x60
// 004984ec  3b742418             cmp esi, dword ptr [esp + 0x18]
// 004984f0  75c6                 jne 0x4984b8
// 004984f2  5f                   pop edi
// 004984f3  5d                   pop ebp
// 004984f4  5b                   pop ebx
// 004984f5  5e                   pop esi
// 004984f6  c3                   ret 
// copied from an identical function in another client (function ??$_Fill@PAUFileInfo@Ogre@@U12@@std@@YAXPAUFileInfo@Ogre@@0ABU12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll OgreFileSystem.cpp