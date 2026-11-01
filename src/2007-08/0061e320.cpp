// from server: 100% by auto
// roc 2007-08 0061e320  unit: RBX::ScoreHud  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0061e320
//
// 0061e320  56                   push esi
// 0061e321  8b742408             mov esi, dword ptr [esp + 8]
// 0061e325  57                   push edi
// 0061e326  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0061e32a  3bf7                 cmp esi, edi
// 0061e32c  7415                 je 0x61e343
// 0061e32e  53                   push ebx
// 0061e32f  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0061e333  53                   push ebx
// 0061e334  8bce                 mov ecx, esi
// 0061e336  e805bae6ff           call 0x489d40
// 0061e33b  83c610               add esi, 0x10
// 0061e33e  3bf7                 cmp esi, edi
// 0061e340  75f1                 jne 0x61e333
// 0061e342  5b                   pop ebx
// 0061e343  5f                   pop edi
// 0061e344  5e                   pop esi
// 0061e345  c3                   ret 
// library ogre-1.7.0/OgreScriptLexer.cpp (function ??$_Fill@PAV?$SharedPtr@UScriptToken@Ogre@@@Ogre@@V12@@std@@YAXPAV?$SharedPtr@UScriptToken@Ogre@@@Ogre@@0ABV12@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptLexer.cpp
