// from server: 100% by auto
// roc 2010-06 00902ce0  unit: Ogre::UFileInfo::V?$vector::?$SharedPtr  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00902ce0
//
// 00902ce0  53                   push ebx
// 00902ce1  8b1df0b89e00         mov ebx, dword ptr [0x9eb8f0]
// 00902ce7  56                   push esi
// 00902ce8  8bf1                 mov esi, ecx
// 00902cea  8b460c               mov eax, dword ptr [esi + 0xc]
// 00902ced  83e800               sub eax, 0
// 00902cf0  7440                 je 0x902d32
// 00902cf2  83e801               sub eax, 1
// 00902cf5  741a                 je 0x902d11
// 00902cf7  83e801               sub eax, 1
// 00902cfa  754f                 jne 0x902d4b
// 00902cfc  8b4604               mov eax, dword ptr [esi + 4]
// 00902cff  50                   push eax
// 00902d00  ffd3                 call ebx
// 00902d02  8b5608               mov edx, dword ptr [esi + 8]
// 00902d05  83c404               add esp, 4
// 00902d08  52                   push edx
// 00902d09  ffd3                 call ebx
// 00902d0b  83c404               add esp, 4
// 00902d0e  5e                   pop esi
// 00902d0f  5b                   pop ebx
// 00902d10  c3                   ret 
// 00902d11  8b4e04               mov ecx, dword ptr [esi + 4]
// 00902d14  85c9                 test ecx, ecx
// 00902d16  7433                 je 0x902d4b
// 00902d18  e853faffff           call 0x902770
// 00902d1d  8b4e04               mov ecx, dword ptr [esi + 4]
// 00902d20  51                   push ecx
// 00902d21  ffd3                 call ebx
// 00902d23  8b5608               mov edx, dword ptr [esi + 8]
// 00902d26  83c404               add esp, 4
// 00902d29  52                   push edx
// 00902d2a  ffd3                 call ebx
// 00902d2c  83c404               add esp, 4
// 00902d2f  5e                   pop esi
// 00902d30  5b                   pop ebx
// 00902d31  c3                   ret 
// 00902d32  57                   push edi
// 00902d33  8b7e04               mov edi, dword ptr [esi + 4]
// 00902d36  85ff                 test edi, edi
// 00902d38  7410                 je 0x902d4a
// 00902d3a  8bcf                 mov ecx, edi
// 00902d3c  e82ffaffff           call 0x902770
// 00902d41  57                   push edi
// 00902d42  e8534ceaff           call 0x7a799a
// 00902d47  83c404               add esp, 4
// 00902d4a  5f                   pop edi
// 00902d4b  8b5608               mov edx, dword ptr [esi + 8]
// 00902d4e  52                   push edx
// 00902d4f  ffd3                 call ebx
// 00902d51  83c404               add esp, 4
// 00902d54  5e                   pop esi
// 00902d55  5b                   pop ebx
// 00902d56  c3                   ret 
// library ogre-1.7.0/OgreScriptLexer.cpp (function ?destroy@?$SharedPtr@V?$vector@V?$SharedPtr@UScriptToken@Ogre@@@Ogre@@V?$allocator@V?$SharedPtr@UScriptToken@Ogre@@@Ogre@@@std@@@std@@@Ogre@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptLexer.cpp
