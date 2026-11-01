// from server: 100% by auto
// roc 2009-12 0079f700  unit: seg_00790000  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079f700
//
// 0079f700  56                   push esi
// 0079f701  57                   push edi
// 0079f702  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0079f706  6a01                 push 1
// 0079f708  57                   push edi
// 0079f709  e8a295feff           call 0x788cb0
// 0079f70e  8bf0                 mov esi, eax
// 0079f710  83c408               add esp, 8
// 0079f713  85f6                 test esi, esi
// 0079f715  7510                 jne 0x79f727
// 0079f717  68b8b69e00           push 0x9eb6b8
// 0079f71c  6a01                 push 1
// 0079f71e  57                   push edi
// 0079f71f  e85caefeff           call 0x78a580
// 0079f724  83c40c               add esp, 0xc
// 0079f727  57                   push edi
// 0079f728  e87390feff           call 0x7887a0
// 0079f72d  83c404               add esp, 4
// 0079f730  48                   dec eax
// 0079f731  8bce                 mov ecx, esi
// 0079f733  e808ffffff           call 0x79f640
// 0079f738  8bf0                 mov esi, eax
// 0079f73a  85f6                 test esi, esi
// 0079f73c  7d1b                 jge 0x79f759
// 0079f73e  6a00                 push 0
// 0079f740  57                   push edi
// 0079f741  e80a98feff           call 0x788f50
// 0079f746  6afe                 push -2
// 0079f748  57                   push edi
// 0079f749  e80291feff           call 0x788850
// 0079f74e  83c410               add esp, 0x10
// 0079f751  5f                   pop edi
// 0079f752  b802000000           mov eax, 2
// 0079f757  5e                   pop esi
// 0079f758  c3                   ret 
// 0079f759  6a01                 push 1
// 0079f75b  57                   push edi
// 0079f75c  e8ef97feff           call 0x788f50
// 0079f761  83c8ff               or eax, 0xffffffff
// 0079f764  2bc6                 sub eax, esi
// 0079f766  50                   push eax
// 0079f767  57                   push edi
// 0079f768  e8e390feff           call 0x788850
// 0079f76d  83c410               add esp, 0x10
// 0079f770  5f                   pop edi
// 0079f771  8d4601               lea eax, [esi + 1]
// 0079f774  5e                   pop esi
// 0079f775  c3                   ret 
// library lua-5.1.3/lbaselib.c (function _luaB_coresume)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.3 lbaselib.c
