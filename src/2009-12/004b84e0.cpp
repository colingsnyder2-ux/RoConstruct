// from server: 100% by auto
// roc 2009-12 004b84e0  unit: std::D::DU?$char_traits::V?$basic_string::V?$vector::?$SharedPtr  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b84e0
//
// 004b84e0  56                   push esi
// 004b84e1  8bf1                 mov esi, ecx
// 004b84e3  8b460c               mov eax, dword ptr [esi + 0xc]
// 004b84e6  83e800               sub eax, 0
// 004b84e9  57                   push edi
// 004b84ea  8b3df0bc9800         mov edi, dword ptr [0x98bcf0]
// 004b84f0  7442                 je 0x4b8534
// 004b84f2  83e801               sub eax, 1
// 004b84f5  741a                 je 0x4b8511
// 004b84f7  83e801               sub eax, 1
// 004b84fa  7546                 jne 0x4b8542
// 004b84fc  8b4604               mov eax, dword ptr [esi + 4]
// 004b84ff  50                   push eax
// 004b8500  ffd7                 call edi
// 004b8502  8b5608               mov edx, dword ptr [esi + 8]
// 004b8505  83c404               add esp, 4
// 004b8508  52                   push edx
// 004b8509  ffd7                 call edi
// 004b850b  83c404               add esp, 4
// 004b850e  5f                   pop edi
// 004b850f  5e                   pop esi
// 004b8510  c3                   ret 
// 004b8511  8b4e04               mov ecx, dword ptr [esi + 4]
// 004b8514  85c9                 test ecx, ecx
// 004b8516  742a                 je 0x4b8542
// 004b8518  6a00                 push 0
// 004b851a  e801ffffff           call 0x4b8420
// 004b851f  8b4e04               mov ecx, dword ptr [esi + 4]
// 004b8522  51                   push ecx
// 004b8523  ffd7                 call edi
// 004b8525  8b5608               mov edx, dword ptr [esi + 8]
// 004b8528  83c404               add esp, 4
// 004b852b  52                   push edx
// 004b852c  ffd7                 call edi
// 004b852e  83c404               add esp, 4
// 004b8531  5f                   pop edi
// 004b8532  5e                   pop esi
// 004b8533  c3                   ret 
// 004b8534  8b4e04               mov ecx, dword ptr [esi + 4]
// 004b8537  85c9                 test ecx, ecx
// 004b8539  7407                 je 0x4b8542
// 004b853b  6a01                 push 1
// 004b853d  e8defeffff           call 0x4b8420
// 004b8542  8b5608               mov edx, dword ptr [esi + 8]
// 004b8545  52                   push edx
// 004b8546  ffd7                 call edi
// 004b8548  83c404               add esp, 4
// 004b854b  5f                   pop edi
// 004b854c  5e                   pop esi
// 004b854d  c3                   ret 
// library ogre-1.7.0/OgreScriptLexer.cpp (function ?destroy@?$SharedPtr@UScriptToken@Ogre@@@Ogre@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptLexer.cpp
