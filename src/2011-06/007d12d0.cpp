// from server: 100% by auto
// roc 2011-06 007d12d0  unit: RBX::ScoreHud  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007d12d0
//
// 007d12d0  56                   push esi
// 007d12d1  8b742408             mov esi, dword ptr [esp + 8]
// 007d12d5  57                   push edi
// 007d12d6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007d12da  3bf7                 cmp esi, edi
// 007d12dc  7415                 je 0x7d12f3
// 007d12de  53                   push ebx
// 007d12df  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 007d12e3  53                   push ebx
// 007d12e4  8bce                 mov ecx, esi
// 007d12e6  e8d597cdff           call 0x4aaac0
// 007d12eb  83c610               add esi, 0x10
// 007d12ee  3bf7                 cmp esi, edi
// 007d12f0  75f1                 jne 0x7d12e3
// 007d12f2  5b                   pop ebx
// 007d12f3  5f                   pop edi
// 007d12f4  5e                   pop esi
// 007d12f5  c3                   ret 
// library ogre-1.7.0/OgreScriptLexer.cpp (function ??$_Fill@PAV?$SharedPtr@UScriptToken@Ogre@@@Ogre@@V12@@std@@YAXPAV?$SharedPtr@UScriptToken@Ogre@@@Ogre@@0ABV12@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptLexer.cpp
