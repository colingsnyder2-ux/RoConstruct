// from server: 100% by auto
// roc 2011-06 0092b1e0  unit: Ogre::UFileInfo::V?$vector::?$SharedPtr  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0092b1e0
//
// 0092b1e0  53                   push ebx
// 0092b1e1  8b1d1c19a400         mov ebx, dword ptr [0xa4191c]
// 0092b1e7  56                   push esi
// 0092b1e8  8bf1                 mov esi, ecx
// 0092b1ea  8b460c               mov eax, dword ptr [esi + 0xc]
// 0092b1ed  83e800               sub eax, 0
// 0092b1f0  7440                 je 0x92b232
// 0092b1f2  83e801               sub eax, 1
// 0092b1f5  741a                 je 0x92b211
// 0092b1f7  83e801               sub eax, 1
// 0092b1fa  754f                 jne 0x92b24b
// 0092b1fc  8b4604               mov eax, dword ptr [esi + 4]
// 0092b1ff  50                   push eax
// 0092b200  ffd3                 call ebx
// 0092b202  8b5608               mov edx, dword ptr [esi + 8]
// 0092b205  83c404               add esp, 4
// 0092b208  52                   push edx
// 0092b209  ffd3                 call ebx
// 0092b20b  83c404               add esp, 4
// 0092b20e  5e                   pop esi
// 0092b20f  5b                   pop ebx
// 0092b210  c3                   ret 
// 0092b211  8b4e04               mov ecx, dword ptr [esi + 4]
// 0092b214  85c9                 test ecx, ecx
// 0092b216  7433                 je 0x92b24b
// 0092b218  e8a3faffff           call 0x92acc0
// 0092b21d  8b4e04               mov ecx, dword ptr [esi + 4]
// 0092b220  51                   push ecx
// 0092b221  ffd3                 call ebx
// 0092b223  8b5608               mov edx, dword ptr [esi + 8]
// 0092b226  83c404               add esp, 4
// 0092b229  52                   push edx
// 0092b22a  ffd3                 call ebx
// 0092b22c  83c404               add esp, 4
// 0092b22f  5e                   pop esi
// 0092b230  5b                   pop ebx
// 0092b231  c3                   ret 
// 0092b232  57                   push edi
// 0092b233  8b7e04               mov edi, dword ptr [esi + 4]
// 0092b236  85ff                 test edi, edi
// 0092b238  7410                 je 0x92b24a
// 0092b23a  8bcf                 mov ecx, edi
// 0092b23c  e87ffaffff           call 0x92acc0
// 0092b241  57                   push edi
// 0092b242  e811eeedff           call 0x80a058
// 0092b247  83c404               add esp, 4
// 0092b24a  5f                   pop edi
// 0092b24b  8b5608               mov edx, dword ptr [esi + 8]
// 0092b24e  52                   push edx
// 0092b24f  ffd3                 call ebx
// 0092b251  83c404               add esp, 4
// 0092b254  5e                   pop esi
// 0092b255  5b                   pop ebx
// 0092b256  c3                   ret 
// library ogre-1.7.0/OgreScriptLexer.cpp (function ?destroy@?$SharedPtr@V?$vector@V?$SharedPtr@UScriptToken@Ogre@@@Ogre@@V?$allocator@V?$SharedPtr@UScriptToken@Ogre@@@Ogre@@@std@@@std@@@Ogre@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptLexer.cpp
