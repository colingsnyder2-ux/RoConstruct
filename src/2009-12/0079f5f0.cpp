// from server: 100% by auto
// roc 2009-12 0079f5f0  unit: seg_00790000  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079f5f0
//
// 0079f5f0  56                   push esi
// 0079f5f1  57                   push edi
// 0079f5f2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0079f5f6  6a01                 push 1
// 0079f5f8  57                   push edi
// 0079f5f9  e8b296feff           call 0x788cb0
// 0079f5fe  8bf0                 mov esi, eax
// 0079f600  83c408               add esp, 8
// 0079f603  85f6                 test esi, esi
// 0079f605  7510                 jne 0x79f617
// 0079f607  68b8b69e00           push 0x9eb6b8
// 0079f60c  6a01                 push 1
// 0079f60e  57                   push edi
// 0079f60f  e86caffeff           call 0x78a580
// 0079f614  83c40c               add esp, 0xc
// 0079f617  57                   push edi
// 0079f618  e863ffffff           call 0x79f580
// 0079f61d  8b048558b49e00       mov eax, dword ptr [eax*4 + 0x9eb458]
// 0079f624  50                   push eax
// 0079f625  57                   push edi
// 0079f626  e8b597feff           call 0x788de0
// 0079f62b  83c40c               add esp, 0xc
// 0079f62e  5f                   pop edi
// 0079f62f  b801000000           mov eax, 1
// 0079f634  5e                   pop esi
// 0079f635  c3                   ret 
// library lua-5.1.3/lbaselib.c (function _luaB_costatus)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.3 lbaselib.c
