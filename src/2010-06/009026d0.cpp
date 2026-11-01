// from server: 100% by auto
// roc 2010-06 009026d0  unit: std::D::DU?$char_traits::V?$basic_string::V?$vector::?$SharedPtr  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009026d0
//
// 009026d0  56                   push esi
// 009026d1  8bf1                 mov esi, ecx
// 009026d3  8b460c               mov eax, dword ptr [esi + 0xc]
// 009026d6  83e800               sub eax, 0
// 009026d9  57                   push edi
// 009026da  8b3df0b89e00         mov edi, dword ptr [0x9eb8f0]
// 009026e0  7442                 je 0x902724
// 009026e2  83e801               sub eax, 1
// 009026e5  741a                 je 0x902701
// 009026e7  83e801               sub eax, 1
// 009026ea  7546                 jne 0x902732
// 009026ec  8b4604               mov eax, dword ptr [esi + 4]
// 009026ef  50                   push eax
// 009026f0  ffd7                 call edi
// 009026f2  8b5608               mov edx, dword ptr [esi + 8]
// 009026f5  83c404               add esp, 4
// 009026f8  52                   push edx
// 009026f9  ffd7                 call edi
// 009026fb  83c404               add esp, 4
// 009026fe  5f                   pop edi
// 009026ff  5e                   pop esi
// 00902700  c3                   ret 
// 00902701  8b4e04               mov ecx, dword ptr [esi + 4]
// 00902704  85c9                 test ecx, ecx
// 00902706  742a                 je 0x902732
// 00902708  6a00                 push 0
// 0090270a  e8f1d3e6ff           call 0x76fb00
// 0090270f  8b4e04               mov ecx, dword ptr [esi + 4]
// 00902712  51                   push ecx
// 00902713  ffd7                 call edi
// 00902715  8b5608               mov edx, dword ptr [esi + 8]
// 00902718  83c404               add esp, 4
// 0090271b  52                   push edx
// 0090271c  ffd7                 call edi
// 0090271e  83c404               add esp, 4
// 00902721  5f                   pop edi
// 00902722  5e                   pop esi
// 00902723  c3                   ret 
// 00902724  8b4e04               mov ecx, dword ptr [esi + 4]
// 00902727  85c9                 test ecx, ecx
// 00902729  7407                 je 0x902732
// 0090272b  6a01                 push 1
// 0090272d  e8ced3e6ff           call 0x76fb00
// 00902732  8b5608               mov edx, dword ptr [esi + 8]
// 00902735  52                   push edx
// 00902736  ffd7                 call edi
// 00902738  83c404               add esp, 4
// 0090273b  5f                   pop edi
// 0090273c  5e                   pop esi
// 0090273d  c3                   ret 
// library ogre-1.7.0/OgreScriptLexer.cpp (function ?destroy@?$SharedPtr@UScriptToken@Ogre@@@Ogre@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptLexer.cpp
