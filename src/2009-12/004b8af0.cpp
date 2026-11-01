// from server: 100% by auto
// roc 2009-12 004b8af0  unit: Ogre::UFileInfo::V?$vector::?$SharedPtr  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b8af0
//
// 004b8af0  53                   push ebx
// 004b8af1  8b1df0bc9800         mov ebx, dword ptr [0x98bcf0]
// 004b8af7  56                   push esi
// 004b8af8  8bf1                 mov esi, ecx
// 004b8afa  8b460c               mov eax, dword ptr [esi + 0xc]
// 004b8afd  83e800               sub eax, 0
// 004b8b00  7440                 je 0x4b8b42
// 004b8b02  83e801               sub eax, 1
// 004b8b05  741a                 je 0x4b8b21
// 004b8b07  83e801               sub eax, 1
// 004b8b0a  754f                 jne 0x4b8b5b
// 004b8b0c  8b4604               mov eax, dword ptr [esi + 4]
// 004b8b0f  50                   push eax
// 004b8b10  ffd3                 call ebx
// 004b8b12  8b5608               mov edx, dword ptr [esi + 8]
// 004b8b15  83c404               add esp, 4
// 004b8b18  52                   push edx
// 004b8b19  ffd3                 call ebx
// 004b8b1b  83c404               add esp, 4
// 004b8b1e  5e                   pop esi
// 004b8b1f  5b                   pop ebx
// 004b8b20  c3                   ret 
// 004b8b21  8b4e04               mov ecx, dword ptr [esi + 4]
// 004b8b24  85c9                 test ecx, ecx
// 004b8b26  7433                 je 0x4b8b5b
// 004b8b28  e853faffff           call 0x4b8580
// 004b8b2d  8b4e04               mov ecx, dword ptr [esi + 4]
// 004b8b30  51                   push ecx
// 004b8b31  ffd3                 call ebx
// 004b8b33  8b5608               mov edx, dword ptr [esi + 8]
// 004b8b36  83c404               add esp, 4
// 004b8b39  52                   push edx
// 004b8b3a  ffd3                 call ebx
// 004b8b3c  83c404               add esp, 4
// 004b8b3f  5e                   pop esi
// 004b8b40  5b                   pop ebx
// 004b8b41  c3                   ret 
// 004b8b42  57                   push edi
// 004b8b43  8b7e04               mov edi, dword ptr [esi + 4]
// 004b8b46  85ff                 test edi, edi
// 004b8b48  7410                 je 0x4b8b5a
// 004b8b4a  8bcf                 mov ecx, edi
// 004b8b4c  e82ffaffff           call 0x4b8580
// 004b8b51  57                   push edi
// 004b8b52  e803ad3300           call 0x7f385a
// 004b8b57  83c404               add esp, 4
// 004b8b5a  5f                   pop edi
// 004b8b5b  8b5608               mov edx, dword ptr [esi + 8]
// 004b8b5e  52                   push edx
// 004b8b5f  ffd3                 call ebx
// 004b8b61  83c404               add esp, 4
// 004b8b64  5e                   pop esi
// 004b8b65  5b                   pop ebx
// 004b8b66  c3                   ret 
// library ogre-1.7.0/OgreScriptLexer.cpp (function ?destroy@?$SharedPtr@V?$vector@V?$SharedPtr@UScriptToken@Ogre@@@Ogre@@V?$allocator@V?$SharedPtr@UScriptToken@Ogre@@@Ogre@@@std@@@std@@@Ogre@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptLexer.cpp
