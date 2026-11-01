// from server: 100% by auto
// roc 2011-06 007b72f0  unit: RBX::SpatialFilter  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007b72f0
//
// 007b72f0  56                   push esi
// 007b72f1  8b742408             mov esi, dword ptr [esp + 8]
// 007b72f5  57                   push edi
// 007b72f6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007b72fa  3bf7                 cmp esi, edi
// 007b72fc  7415                 je 0x7b7313
// 007b72fe  53                   push ebx
// 007b72ff  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 007b7303  53                   push ebx
// 007b7304  8bce                 mov ecx, esi
// 007b7306  e825feffff           call 0x7b7130
// 007b730b  83c610               add esi, 0x10
// 007b730e  3bf7                 cmp esi, edi
// 007b7310  75f1                 jne 0x7b7303
// 007b7312  5b                   pop ebx
// 007b7313  5f                   pop edi
// 007b7314  5e                   pop esi
// 007b7315  c3                   ret 
// library ogre-1.7.0/OgreScriptLexer.cpp (function ??$_Fill@PAV?$SharedPtr@UScriptToken@Ogre@@@Ogre@@V12@@std@@YAXPAV?$SharedPtr@UScriptToken@Ogre@@@Ogre@@0ABV12@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptLexer.cpp
