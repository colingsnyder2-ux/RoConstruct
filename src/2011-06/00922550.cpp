// from server: 100% by auto
// roc 2011-06 00922550  unit: Ogre::VDataStream::?$SharedPtr  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00922550
//
// 00922550  56                   push esi
// 00922551  8bf1                 mov esi, ecx
// 00922553  8b460c               mov eax, dword ptr [esi + 0xc]
// 00922556  83e800               sub eax, 0
// 00922559  57                   push edi
// 0092255a  8b3d1c19a400         mov edi, dword ptr [0xa4191c]
// 00922560  7446                 je 0x9225a8
// 00922562  83e801               sub eax, 1
// 00922565  741a                 je 0x922581
// 00922567  83e801               sub eax, 1
// 0092256a  754c                 jne 0x9225b8
// 0092256c  8b4604               mov eax, dword ptr [esi + 4]
// 0092256f  50                   push eax
// 00922570  ffd7                 call edi
// 00922572  8b4e08               mov ecx, dword ptr [esi + 8]
// 00922575  83c404               add esp, 4
// 00922578  51                   push ecx
// 00922579  ffd7                 call edi
// 0092257b  83c404               add esp, 4
// 0092257e  5f                   pop edi
// 0092257f  5e                   pop esi
// 00922580  c3                   ret 
// 00922581  837e0400             cmp dword ptr [esi + 4], 0
// 00922585  7431                 je 0x9225b8
// 00922587  8b4e04               mov ecx, dword ptr [esi + 4]
// 0092258a  8b11                 mov edx, dword ptr [ecx]
// 0092258c  8b4208               mov eax, dword ptr [edx + 8]
// 0092258f  6a00                 push 0
// 00922591  ffd0                 call eax
// 00922593  8b4e04               mov ecx, dword ptr [esi + 4]
// 00922596  51                   push ecx
// 00922597  ffd7                 call edi
// 00922599  8b4e08               mov ecx, dword ptr [esi + 8]
// 0092259c  83c404               add esp, 4
// 0092259f  51                   push ecx
// 009225a0  ffd7                 call edi
// 009225a2  83c404               add esp, 4
// 009225a5  5f                   pop edi
// 009225a6  5e                   pop esi
// 009225a7  c3                   ret 
// 009225a8  8b4e04               mov ecx, dword ptr [esi + 4]
// 009225ab  85c9                 test ecx, ecx
// 009225ad  7409                 je 0x9225b8
// 009225af  8b11                 mov edx, dword ptr [ecx]
// 009225b1  8b4208               mov eax, dword ptr [edx + 8]
// 009225b4  6a01                 push 1
// 009225b6  ffd0                 call eax
// 009225b8  8b4e08               mov ecx, dword ptr [esi + 8]
// 009225bb  51                   push ecx
// 009225bc  ffd7                 call edi
// 009225be  83c404               add esp, 4
// 009225c1  5f                   pop edi
// 009225c2  5e                   pop esi
// 009225c3  c3                   ret 
// library ogre-1.7.0/OgreConfigFile.cpp (function ?destroy@?$SharedPtr@VDataStream@Ogre@@@Ogre@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreConfigFile.cpp
