// from server: 100% by auto
// roc 2007-08 004a7ba0  unit: RBX::Network::Replicator::ChangePropertyItem  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a7ba0
//
// 004a7ba0  56                   push esi
// 004a7ba1  8b742408             mov esi, dword ptr [esp + 8]
// 004a7ba5  57                   push edi
// 004a7ba6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004a7baa  3bf7                 cmp esi, edi
// 004a7bac  7415                 je 0x4a7bc3
// 004a7bae  53                   push ebx
// 004a7baf  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 004a7bb3  53                   push ebx
// 004a7bb4  8bce                 mov ecx, esi
// 004a7bb6  e835092800           call 0x7284f0
// 004a7bbb  83c610               add esi, 0x10
// 004a7bbe  3bf7                 cmp esi, edi
// 004a7bc0  75f1                 jne 0x4a7bb3
// 004a7bc2  5b                   pop ebx
// 004a7bc3  5f                   pop edi
// 004a7bc4  5e                   pop esi
// 004a7bc5  c3                   ret 
// library ogre-1.7.0/OgreScriptLexer.cpp (function ??$_Fill@PAV?$SharedPtr@UScriptToken@Ogre@@@Ogre@@V12@@std@@YAXPAV?$SharedPtr@UScriptToken@Ogre@@@Ogre@@0ABV12@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptLexer.cpp
