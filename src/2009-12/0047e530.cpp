// from server: 100% by auto
// roc 2009-12 0047e530  unit: Ogre::VResource::?$SharedPtr  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047e530
//
// 0047e530  56                   push esi
// 0047e531  8bf1                 mov esi, ecx
// 0047e533  8b460c               mov eax, dword ptr [esi + 0xc]
// 0047e536  83e800               sub eax, 0
// 0047e539  57                   push edi
// 0047e53a  8b3df0bc9800         mov edi, dword ptr [0x98bcf0]
// 0047e540  7445                 je 0x47e587
// 0047e542  83e801               sub eax, 1
// 0047e545  741a                 je 0x47e561
// 0047e547  83e801               sub eax, 1
// 0047e54a  754a                 jne 0x47e596
// 0047e54c  8b4604               mov eax, dword ptr [esi + 4]
// 0047e54f  50                   push eax
// 0047e550  ffd7                 call edi
// 0047e552  8b4e08               mov ecx, dword ptr [esi + 8]
// 0047e555  83c404               add esp, 4
// 0047e558  51                   push ecx
// 0047e559  ffd7                 call edi
// 0047e55b  83c404               add esp, 4
// 0047e55e  5f                   pop edi
// 0047e55f  5e                   pop esi
// 0047e560  c3                   ret 
// 0047e561  837e0400             cmp dword ptr [esi + 4], 0
// 0047e565  742f                 je 0x47e596
// 0047e567  8b4e04               mov ecx, dword ptr [esi + 4]
// 0047e56a  8b11                 mov edx, dword ptr [ecx]
// 0047e56c  8b02                 mov eax, dword ptr [edx]
// 0047e56e  6a00                 push 0
// 0047e570  ffd0                 call eax
// 0047e572  8b4e04               mov ecx, dword ptr [esi + 4]
// 0047e575  51                   push ecx
// 0047e576  ffd7                 call edi
// 0047e578  8b4e08               mov ecx, dword ptr [esi + 8]
// 0047e57b  83c404               add esp, 4
// 0047e57e  51                   push ecx
// 0047e57f  ffd7                 call edi
// 0047e581  83c404               add esp, 4
// 0047e584  5f                   pop edi
// 0047e585  5e                   pop esi
// 0047e586  c3                   ret 
// 0047e587  8b4e04               mov ecx, dword ptr [esi + 4]
// 0047e58a  85c9                 test ecx, ecx
// 0047e58c  7408                 je 0x47e596
// 0047e58e  8b11                 mov edx, dword ptr [ecx]
// 0047e590  8b02                 mov eax, dword ptr [edx]
// 0047e592  6a01                 push 1
// 0047e594  ffd0                 call eax
// 0047e596  8b4e08               mov ecx, dword ptr [esi + 8]
// 0047e599  51                   push ecx
// 0047e59a  ffd7                 call edi
// 0047e59c  83c404               add esp, 4
// 0047e59f  5f                   pop edi
// 0047e5a0  5e                   pop esi
// 0047e5a1  c3                   ret 
// library ogre-1.7.0/OgreCompositionPass.cpp (function ?destroy@?$SharedPtr@VResource@Ogre@@@Ogre@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreCompositionPass.cpp
